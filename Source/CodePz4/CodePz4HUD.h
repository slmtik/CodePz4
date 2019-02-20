// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CodePz4HUD.generated.h"

UCLASS()
class ACodePz4HUD : public AHUD
{
	GENERATED_BODY()

public:
	ACodePz4HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	const uint32* RemainingAmmo;
private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

