// Fill out your copyright notice in the Description page of Project Settings.
#include "BaseRoomActor.h"


#pragma once

/**
 * 
 */
class SLEEPERAGENTANISIMOV_API RoomLayout
{
public:
	RoomLayout();
	~RoomLayout();

	bool northDoor;
	bool eastDoor;
	bool southDoor;
	bool westDoor;
	int rarity;
	int type;
	TArray<FStaticMeshStruct> staticMeshes;
	TArray<FVector2D> itemLocations;
	TArray<FGuardStruct> guards;
	TArray<FPatrolRouteStruct> patrolRoutes;
	TArray<FCameraStruct> cameras;
	TArray<FLightStruct> lights;
};
