// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestingGroundFPSGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDFPS_API AInfiniteTerrainGameMode : public ATestingGroundFPSGameMode
{
	GENERATED_BODY()

public:
	AInfiniteTerrainGameMode();

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nav Mesh Bounds Volume Pool")
	class UActorPool *NavMeshBoundsVolumePool;



private:
	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);
	
	
	
	
};
