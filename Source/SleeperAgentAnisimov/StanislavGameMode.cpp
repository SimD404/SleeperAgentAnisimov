// Fill out your copyright notice in the Description page of Project Settings.

#include "SleeperAgentAnisimov.h"
#include "StanislavGameMode.h"


AStanislavGameMode::AStanislavGameMode(const class FObjectInitializer& ObjectInitializer) :
Super(ObjectInitializer)
{
	PlayerControllerClass = ATopDownPlayerController::StaticClass();

	static ConstructorHelpers::FObjectFinder<UBlueprint> topDownBluePrint(TEXT("Blueprint'/Game/Blueprints/TopDownController.TopDownController'"));
	if (topDownBluePrint.Object != NULL)
	{
		PlayerControllerClass = (UClass*)topDownBluePrint.Object->GeneratedClass;
	}



	static ConstructorHelpers::FObjectFinder<UBlueprint> characterBluePrint(TEXT("Blueprint'/Game/Blueprints/PlayerCharacter.PlayerCharacter'"));
	if (characterBluePrint.Object != NULL)
	{
		DefaultPawnClass = (UClass*)characterBluePrint.Object->GeneratedClass;
	}
}

