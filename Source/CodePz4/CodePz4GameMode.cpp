// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "CodePz4GameMode.h"
#include "CodePz4HUD.h"
#include "CodePz4Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

ACodePz4GameMode::ACodePz4GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACodePz4HUD::StaticClass();

	
}

void ACodePz4GameMode::BeginPlay()
{
	Super::BeginPlay();

	ACodePz4Character* pzCharacter = Cast<ACodePz4Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (pzCharacter)
	{
		ACodePz4HUD* pzHud = Cast<ACodePz4HUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
		if (pzHud)
		{
			pzHud->RemainingAmmo = pzCharacter->GetRemainingAmmo();
		}
	}
}
