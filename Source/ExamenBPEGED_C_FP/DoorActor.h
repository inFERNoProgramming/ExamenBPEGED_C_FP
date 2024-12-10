// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "DoorActor.generated.h"

UCLASS()
class EXAMENBPEGED_C_FP_API ADoorActor : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool PlayerHasKey = false;
	bool PlayerNotHasNotKey = false;
	
	// Sets default values for this actor's properties
	ADoorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnInteract();
	
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Mesh");
	class UStaticMeshComponent* DoorFrame;
	UPROPERTY(VisibleAnywhere, Category = "Mesh");
	UStaticMeshComponent* Door;
	
protected:

	FTimeline Timeline;
	UPROPERTY(EditAnywhere)
	UCurveFloat* CurveFloat;
	
	bool bIsDoorClosed = true;
	
	UPROPERTY(EditAnywhere)
	float DoorRotateAngle = 110.f;

	UFUNCTION()
	void OpenDoor(float Value); //bind Function
		
};

