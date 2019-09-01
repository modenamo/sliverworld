#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Trigger.generated.h"

UCLASS()
class SLIVERWORLD_API ATrigger : public AActor
{
	GENERATED_BODY()
public:
	ATrigger();

public:
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* TriggerVolume;

	bool IsActivated() { return _isActivated; }

private:
	bool _isActivated = false;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
