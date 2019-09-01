#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingObject.generated.h"

UCLASS()
class SLIVERWORLD_API AMovingObject : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float Speed = 10.0f;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetPos;

	UPROPERTY(EditAnywhere)
	TArray<class ATrigger*> Triggers;

private:
	FVector _worldStartPos;
	FVector _worldTargetPos;

public:
	AMovingObject();

	bool IsActivated();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
};
