// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FallDetectorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OBSTACLEASSAULT_API UFallDetectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFallDetectorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetTrackedActor(AActor* newActor);

private:
	UPROPERTY(EditAnywhere, Category="Fall Parameters")
	double FallingEdge{-100.};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Fall Parameters", meta = (AllowPrivateAccess = "true"))
	bool HasFell{false};

	AActor* TrackedActor{nullptr};
};
