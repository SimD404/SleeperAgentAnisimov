// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/LevelScriptActor.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <queue>
#include <utility>
#include "LevelGenerationScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class SLEEPERAGENTANISIMOV_API ALevelGenerationScriptActor : public ALevelScriptActor
{

	TSubclassOf<class AActor> RoomBlueprint;
	ALevelGenerationScriptActor(const class FObjectInitializer& ObjectInitializer);

	GENERATED_BODY()
	int layout[9][9];

public:
	/** Generate a level*/
	UFUNCTION(BlueprintCallable, Category = "Level Generation")
	void GenerateLevel();
		
};
