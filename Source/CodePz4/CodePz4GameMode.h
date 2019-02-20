// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CodePz4GameMode.generated.h"

UCLASS(minimalapi)
class ACodePz4GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACodePz4GameMode();
protected:
	virtual void BeginPlay() override;
};



