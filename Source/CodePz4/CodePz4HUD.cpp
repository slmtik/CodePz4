// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "CodePz4HUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"

ACodePz4HUD::ACodePz4HUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;
}


void ACodePz4HUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y + 20.0f));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );

	if (RemainingAmmo)
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("RemainingAmmo"), FText::AsNumber(*RemainingAmmo));
		DrawText(FText::Format(NSLOCTEXT("Hud", "RemainingAmmo", "Your have: {RemainingAmmo} shot(s) left. \n Press 'R' to reload."), Arguments).ToString(),
			FColor::White, 32.f, 32.f, GEngine->GetMediumFont(), 1.f, false);
	}	
}
