// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExamenBPEGED_C_FPGameMode.h"
#include "ExamenBPEGED_C_FPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AExamenBPEGED_C_FPGameMode::AExamenBPEGED_C_FPGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
