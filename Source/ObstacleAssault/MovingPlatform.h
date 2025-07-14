// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;

public:	
	// Called every frame
	void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector Amplitudes{100,100,100};
	
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector MoveSpeeds{100,100,100};

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FRotator RotateSpeeds{0,0,0};

	UPROPERTY(VisibleAnywhere, Category="Moving Platform")
	double Distance{0.};
	
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector Directions{1,1,1};

private:
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	void SetNewDirection(double max, double min, double& current, double& direction) const;
	void CorrectDirectionsAndLocation(FVector& currentLocation);

	FVector startingLocation{};
	FVector maxFinishLocation{};
	FVector minFinishLocation{};
};
