#include "CGameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"
#include "UI/CMainMenu.h"
#include "UI/CPauseMenu.h"

const static FName SESSION_NAME = TEXT("GameSession");

UCGameInstance::UCGameInstance()
{
	ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidgetClassAsset(TEXT("/Game/UI/WB_MainMenu"));
	if (MainMenuWidgetClassAsset.Succeeded())
	{
		MainMenuWidgetClass = MainMenuWidgetClassAsset.Class;
	}

	ConstructorHelpers::FClassFinder<UUserWidget> PauseMenuWidgetClassAsset(TEXT("/Game/UI/WB_PauseMenu"));
	if (PauseMenuWidgetClassAsset.Succeeded())
	{
		PauseMenuWidgetClass = PauseMenuWidgetClassAsset.Class;
	}
}

void UCGameInstance::Init()
{
	Super::Init();

	IOnlineSubsystem* OSS = IOnlineSubsystem::Get();
	if (OSS)
	{
		UE_LOG(LogTemp, Warning, TEXT("OSS : %s is avaliable."), *OSS->GetSubsystemName().ToString());
		
		SessionInterface = OSS->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			//UE_LOG(LogTemp, Warning, TEXT("Session is found."));
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UCGameInstance::OnCreateSessionComplete);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UCGameInstance::OnDestorySessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, & UCGameInstance::OnFindSessionComplete);

			SessionSearch = MakeShareable(new FOnlineSessionSearch());
			if (SessionSearch.IsValid())
			{
				UE_LOG(LogTemp, Warning, TEXT("Start finding session."));

				SessionSearch->bIsLanQuery = true;
				SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Not found subsuystem."));
		}
	}
}

void UCGameInstance::Host()
{
	if (SessionInterface.IsValid())
	{
		auto AlreadyExsistingSession = SessionInterface->GetNamedSession(SESSION_NAME);
		if (AlreadyExsistingSession)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s is already exsist. re-create session."));

			SessionInterface->DestroySession(SESSION_NAME);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No existing session found. Creating a new session..."));
			CreateSession();
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("SessionInterface is not valid. Host failed."));
	}
}

void UCGameInstance::Join(const FString& InAddress)
{
	if (MainMenu)
	{
		MainMenu->ShutDown();
	}

	UEngine* Engine = GetEngine();
	if (!Engine) return;

	Engine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::Printf(TEXT("Join to %s"), *InAddress));

	APlayerController* PC = GetFirstLocalPlayerController();
	if (!PC) return;
	PC->ClientTravel(InAddress, ETravelType::TRAVEL_Absolute);
}

void UCGameInstance::LoadMainMenu()
{
	if (!MainMenuWidgetClass) return;

	MainMenu = CreateWidget<UCMainMenu>(this, MainMenuWidgetClass);
	if (!MainMenu) return;

	MainMenu->SetOwningInstance(this);

	MainMenu->StartUp();
}

void UCGameInstance::LoadPauseMenu()
{
	if (!ensure(PauseMenuWidgetClass)) return;

	UCPauseMenu* PauseMenu = CreateWidget<UCPauseMenu>(this, PauseMenuWidgetClass);
	if (!PauseMenu) return;

	PauseMenu->SetOwningInstance(this);

	PauseMenu->StartUp();
}

void UCGameInstance::OpenMainMenuLevel()
{
	APlayerController* PC = GetFirstLocalPlayerController();
	if (!PC) return;
	PC->ClientTravel("/Game/Maps/MainMenu", ETravelType::TRAVEL_Absolute);
}

void UCGameInstance::OnCreateSessionComplete(FName InSessionName, bool InSuccess)
{
	if (!InSuccess)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not create session"));
		return;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Session name is %s"), *InSessionName.ToString());

	if (MainMenu)
	{
		MainMenu->ShutDown();
	}
	
	UEngine* Engine = GetEngine();
	if (!Engine) return;

	Engine->AddOnScreenDebugMessage(-1, 2.f, FColor::White, "Host");

	UWorld* World = GetWorld();
	if (!World) return;

	World->ServerTravel("/Game/Maps/Coop?listen");
}

void UCGameInstance::OnDestorySessionComplete(FName InSessionName, bool InSuccess)
{
	if (InSuccess == true)
	{
		CreateSession();
	}
}

void UCGameInstance::OnFindSessionComplete(bool InSuccess)
{
	if (InSuccess && SessionSearch.IsValid())
	{
		for (const FOnlineSessionSearchResult& SearchResult : SessionSearch->SearchResults)
		{
			UE_LOG(LogTemp, Display, TEXT("Found session name : %s"), *SearchResult.GetSessionIdStr());
			UE_LOG(LogTemp, Display, TEXT("Ping : %d"), SearchResult.PingInMs);
		}
		UE_LOG(LogTemp, Warning, TEXT("Finished finding session"));
	}
}

void UCGameInstance::CreateSession()
{
	if (SessionInterface.IsValid())
	{
		FOnlineSessionSettings SessionSettings;
		SessionSettings.bIsLANMatch = true;
		SessionSettings.NumPublicConnections = 5;
		SessionSettings.bShouldAdvertise = true;

		SessionInterface->CreateSession(0, SESSION_NAME, SessionSettings);
	}
}
