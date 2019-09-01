#include "Trigger.h"
#include "Components/BoxComponent.h"

ATrigger::ATrigger()
{
	PrimaryActorTick.bCanEverTick = true;
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	RootComponent = TriggerVolume;
}

void ATrigger::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ATrigger::OnOverlapBegin);
		TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &ATrigger::OnOverlapEnd);
	}
}

void ATrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Display, TEXT("Activated %s"), *GetName());
	_isActivated = true;
}

void ATrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Display, TEXT("Deactivated %s"), *GetName());
	_isActivated = false;
}

