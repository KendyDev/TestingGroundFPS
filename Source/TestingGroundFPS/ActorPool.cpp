// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorPool.h"


// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

AActor * UActorPool::CheckOut()
{
	return nullptr;
}

void UActorPool::ReturnActor(AActor * ActorToReturn)
{
	if (ActorToReturn == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Actor To Return is null"));
		return;
	}
}

void UActorPool::Add(AActor * ActorToAdd)
{
	if (ActorToAdd == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Actor To Return is null"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor added: {%s}."),  *(this->GetName()), *(ActorToAdd->GetName()));
}
