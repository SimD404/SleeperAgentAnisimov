// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS()
class SLEEPERAGENTANISIMOV_API AItem : public AActor
{
	GENERATED_BODY()
public:
	
	UPROPERTY(VisibleAnywhere, Category = "Item Components")
	class UStaticMeshComponent* StaticMesh1;
	
	UPROPERTY(VisibleAnywhere, Category = "Item Component")
	class UCapsuleComponent* Capsule1;

	UPROPERTY(VisibleAnywhere, Category = "Item Component")
	class USceneComponent* myRootComponent;

	UPROPERTY(VisibleAnywhere, Category = "Item Component")
	class UArrowComponent* Arrow1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item Properties")
	bool Spawnable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item Properties")
	FString Name;

	UFUNCTION()
	void OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category="ItemFunctions")
	void UseItem();

	AItem(const FObjectInitializer& ObjectInitializer);

private:
	TSubclassOf<class UActorComponent> ItemComponentBlueprint;
	
	
};