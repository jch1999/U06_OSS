#include "CMainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"

bool UCMainMenu::Initialize()
{
	bool bSuccess = Super::Initialize();
	if (!bSuccess) return false;

	if (!HostButton) return false;
	HostButton->OnClicked.AddDynamic(this, &UCMainMenu::HostServer);

	if (!JoinButton) return false;
	JoinButton->OnClicked.AddDynamic(this, &UCMainMenu::OpenJoinMenu);

	if (!CancelJoinButton) return false;
	CancelJoinButton->OnClicked.AddDynamic(this, &UCMainMenu::OpenMainMenu);

	if (!ConfirmJoinButton) return false;
	ConfirmJoinButton->OnClicked.AddDynamic(this, &UCMainMenu::JoinServer);

	return true;
}

void UCMainMenu::SetOwningInstance(ICMenuInterface* InInstance)
{
	OwningInstance = InInstance;
}

void UCMainMenu::StartUp()
{
	AddToViewport();

	bIsFocusable = true;


	FInputModeUIOnly InputMode;

	UWorld* World = GetWorld();
	if (!World)return;

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (!PC) return;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetWidgetToFocus(TakeWidget());

	PC->SetInputMode(InputMode);
	PC->bShowMouseCursor = true;
}

void UCMainMenu::ShutDown()
{
	RemoveFromParent();

	bIsFocusable = false;

	FInputModeGameOnly InputMode;

	UWorld* World = GetWorld();
	if (!World)return;

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (!PC) return;

	PC->SetInputMode(InputMode);
	PC->bShowMouseCursor = true;
}

void UCMainMenu::HostServer()
{
	if (!OwningInstance) return;

	OwningInstance->Host();
}

void UCMainMenu::JoinServer()
{
	if (!OwningInstance) return;
	if (!IPAddressField) return;

	// TODO. ¤Á¤Æ¤±
	OwningInstance->Join(IPAddressField->);
}

void UCMainMenu::OpenMainMenu()
{
	if (!MenuSwitcher) return;
	if (!MainMenu) return;

	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UCMainMenu::OpenJoinMenu()
{
	if (!MenuSwitcher) return;
	if (!JoinMenu) return;

	MenuSwitcher->SetActiveWidget(JoinMenu);
}
