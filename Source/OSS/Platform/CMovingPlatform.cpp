#include "CMovingPlatform.h"

ACMovingPlatform::ACMovingPlatform()
{
	Speed = 200.0f;

	SetMobility(EComponentMobility::Movable);

	// Todo. Enable Tick
}
void ACMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += FVector::RightVector * Speed * DeltaTime;

	SetActorLocation(CurrentLocation);
}
