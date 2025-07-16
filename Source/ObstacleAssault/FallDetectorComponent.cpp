#include "FallDetectorComponent.h"

UFallDetectorComponent::UFallDetectorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UFallDetectorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UFallDetectorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (TrackedActor)
	{
		auto const actorLocation = TrackedActor->GetActorLocation();
		HasFell = actorLocation.Z <= FallingEdge;
	}
}

void UFallDetectorComponent::SetTrackedActor(AActor* newActor)
{
	TrackedActor = newActor;
}