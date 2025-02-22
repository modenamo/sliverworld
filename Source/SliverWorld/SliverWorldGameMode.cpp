// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SliverWorldGameMode.h"
#include "SliverWorldCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASliverWorldGameMode::ASliverWorldGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
