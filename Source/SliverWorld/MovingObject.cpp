#include "MovingObject.h"
#include "Trigger.h"

AMovingObject::AMovingObject()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingObject::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	_worldStartPos = GetActorLocation();
	_worldTargetPos = GetTransform().TransformPosition(TargetPos);
}

void AMovingObject::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if (HasAuthority() && IsActivated())
	{
		FVector pos = GetActorLocation();
		FVector direction = (_worldTargetPos - _worldStartPos).GetSafeNormal();
		FVector deltaPos = direction * Speed * deltaTime;
		FVector distanceToTarget = _worldTargetPos - pos;

		if (deltaPos.Size() >= distanceToTarget.Size()) 
		{
			pos = _worldTargetPos;

			FVector tmpPos = _worldStartPos;
			_worldStartPos = _worldTargetPos;
			_worldTargetPos = tmpPos;
		}
		else
		{
			pos += deltaPos;
		}

		SetActorLocation(pos);
	}

	//UE_LOG(LogTemp, Display, TEXT("Position: %s"), *GetActorLocation().ToString());
}

bool AMovingObject::IsActivated()
{
	bool isActivated = true;
	for (auto trigger : Triggers)
	{
		isActivated &= trigger->IsActivated();
	}

	return isActivated;
}
