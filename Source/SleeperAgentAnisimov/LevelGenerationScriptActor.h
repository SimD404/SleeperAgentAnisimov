// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/LevelScriptActor.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <queue>
#include <utility>
#include <vector>
#include <string>
#include "RoomLayout.h"
#include "LevelGenerationScriptActor.generated.h"


struct SearchData{
	bool visited;
	std::pair<int, int> parent;
	SearchData(){
		visited = false;
		parent = std::pair<int, int>(-1, -1);
	}
	
};

/**
 * 
 */
UCLASS()
class SLEEPERAGENTANISIMOV_API ALevelGenerationScriptActor : public ALevelScriptActor
{
	static const int levelWidth = 8;
	static const int levelHeight = 8;

	TSubclassOf<class AActor> roomLoaderBlueprint;
	ALevelGenerationScriptActor(const class FObjectInitializer& ObjectInitializer);

	GENERATED_BODY()
	int layout[levelWidth][levelHeight];
	ABaseRoomActor* layoutRooms[levelWidth][levelHeight];
	SearchData layoutSearchData[levelWidth][levelHeight];
	std::vector<std::vector<std::string>> layoutFileNames;
	int nRooms;
	std::queue<std::pair<int, int>> rooms;

public:
	/** Generate a level*/
	UFUNCTION(BlueprintCallable, Category = "Level Generation")
	void GenerateLevel();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Generation")
	FVector2D PlayerSpawn;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Generation")
    ABaseRoomActor* StartRoom;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Generation")
    TArray<ABaseRoomActor*> objectives;

private:
	std::vector<RoomLayout*> northRooms;
	std::vector<RoomLayout*> eastRooms;
	std::vector<RoomLayout*> southRooms;
	std::vector<RoomLayout*> westRooms;
	std::vector<RoomLayout*> treasureRooms;
	std::vector<RoomLayout*> normalRooms;
	std::vector<RoomLayout*> objectiveRooms;
	std::vector<RoomLayout*> startRooms;

    std::vector<std::pair<int, int>> indexOfObjectiveRooms;

	void LoadRoomLayouts();
	void LoadRoomLayout(FString path);
	void ExploreLevel();
	void PlanLayout();
	void PlanRegion(int startX, int startY, int endX, int endY, bool startRegion, int conn1X, int conn1Y, int conn2X, int conn2Y);
	int GetAdjacentRooms(int i, int j);
	int GetDistanceFromStart(int i, int j);
    int currentObjectiveIndex = 0;
		
};
