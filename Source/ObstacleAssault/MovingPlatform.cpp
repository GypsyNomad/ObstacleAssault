#include "MovingPlatform.h"

#include <tuple>

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startingLocation = GetActorLocation();
	maxFinishLocation = startingLocation + Amplitudes;
	minFinishLocation = startingLocation - Amplitudes;
}

void AMovingPlatform::SetNewDirection(double max, double min, double& current, double& direction) const
{
    auto overshoot{0.};
    if (current > max)
    {
        overshoot = current - max;
        direction = -1;
        current = max;
    }
    if (current < min)
    {
        overshoot = min - current;
        direction = 1;
        current = min;
    }
}

void AMovingPlatform::CorrectDirectionsAndLocation(FVector& currentLocation)
{
	SetNewDirection(maxFinishLocation.X, minFinishLocation.X, currentLocation.X, Directions.X);
	SetNewDirection(maxFinishLocation.Y, minFinishLocation.Y, currentLocation.Y, Directions.Y);
	SetNewDirection(maxFinishLocation.Z, minFinishLocation.Z, currentLocation.Z, Directions.Z);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
    auto const currentLocation = GetActorLocation();
	auto newLocation = currentLocation + Directions * MoveSpeeds * DeltaTime;

	CorrectDirectionsAndLocation(newLocation);

    Distance = FVector::Distance(startingLocation, newLocation);

	SetActorLocation(newLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    MovePlatform(DeltaTime);
    RotatePlatform(DeltaTime);
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
    AddActorLocalRotation(RotateSpeeds * DeltaTime);
}