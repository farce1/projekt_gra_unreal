// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingPlatform.generated.h"

UCLASS()
class FIRSTGAME_API AFloatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingPlatform();

	// Mesh for the platform
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform")
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	FVector StartPoint;

	// Add visualization widget for manipulation with meta
	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"))
	FVector EndPoint;

	// Manage speed of interpolation/change moving speed for Platform
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform")
	float InterpSpeed;

	// Manage time of interpolation for Platform
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform")
	float InterpTime;

	// Setup interpolation time
	FTimerHandle InterpTimer;

	// Check whether interpolation is in progress
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform")
	bool bInterping;

	// Store distance traveled by platform
	float Distance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Toggle Switch for platform direction
	void ToggleInterping();

	// Swap vectors when opposite direction
	void SwapVectors(FVector& VecOne, FVector& VecTwo);
};
