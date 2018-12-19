// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/WaypointTraversal.h"
#include "AIController.h"
#include "../Public/PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UWaypointTraversal::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 *NodeMemory)
{
	//Get the patrol points
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if(!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }

	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) { 

		UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points")); 
		return EBTNodeResult::Failed;
	}


	//Set the next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// Cycle the index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	
	

	return EBTNodeResult::Succeeded;
}