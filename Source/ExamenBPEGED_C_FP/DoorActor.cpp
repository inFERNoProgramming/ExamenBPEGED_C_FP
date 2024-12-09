// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorActor.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
ADoorActor::ADoorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(RootComponent);

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(DoorFrame);
}

// Called when the game starts or when spawned
void ADoorActor::BeginPlay()
{
	Super::BeginPlay();

	if (CurveFloat)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindDynamic(this, &ADoorActor::OpenDoor);
		Timeline.AddInterpFloat(CurveFloat, TimelineProgress);
	}
	
}

// Called every frame
void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timeline.TickTimeline(DeltaTime);
}

void ADoorActor::OnInteract()
{
	UE_LOG(LogTemp, Display, TEXT("Interacted with door!"));
	if (bIsDoorClosed)
	{
		Timeline.Play(); //Open the door
	}
	else
	{
		Timeline.Reverse(); //Close the door
	}
	bIsDoorClosed = !bIsDoorClosed; //Flip Flop
}

void ADoorActor::OpenDoor(float Value)
{
	if (PlayerHasKey && PlayerNotHasNotKey)
	{
		FRotator Rot = FRotator(.0f, DoorRotateAngle * Value, .0f);

		Door->SetRelativeRotation(Rot);
	}
		
}