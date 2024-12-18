#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "CMovingPlatform.generated.h"

UCLASS()
class OSS_API ACMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	ACMovingPlatform();

	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Moving")
	float Speed;
};
