/*=================================================
* FileName: InfiniteSystemComponent.cpp
* 
* Created by: TK-Master
* Project name: OceanProject
* Unreal Engine version: 4.10
* Created on: 2015/04/26
*
* Last Edited on: 2016/02/28
* Last Edited by: TK-Master
* 
* -------------------------------------------------
* For parts referencing UE4 code, the following copyright applies:
* Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
*
* Feel free to use this software in any commercial/free game.
* Selling this as a plugin/item, in whole or part, is not allowed.
* See "OceanProject\License.md" for full licensing details.
* =================================================*/

#include "OceanPluginPrivatePCH.h"
#include "InfiniteSystemComponent.h"
//#include "UnrealEd.h"

UInfiniteSystemComponent::UInfiniteSystemComponent(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) 
{
	PrimaryComponentTick.bCanEverTick = true;
	bAutoActivate = true;
	bTickInEditor = true;
	
	//Defaults
	UpdateInEditor = true;
	GridSnapSize = 0;
	MaxLookAtDistance = 20000;
	ScaleByDistance = true;
	ScaleDistanceFactor = 1000;
	ScaleStartDistance = 1;
	ScaleMin = 1;
	ScaleMax = 100;

	World = GetWorld();
}

void UInfiniteSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	//Store the world ref.
	World = GetWorld();
}

void UInfiniteSystemComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// If disabled or we are not attached to a parent component, return.
	if (!bIsActive || !AttachParent || !World) return;

	FVector CamLoc;
	FRotator CamRot;
	FVector PawnLoc;
	FVector NewLoc;

#if WITH_EDITOR
	if (GIsEditor)
	{
		if (!UpdateInEditor) return;

		TArray<FVector> viewLocations = GetWorld()->ViewLocationsRenderedLastFrame;
		if (viewLocations.Num() != 0)
		{
			CamLoc = viewLocations[0];
		}

		//FEditorViewportClient* client = (FEditorViewportClient*)GEditor->GetActiveViewport()->GetClient();
		//CamLoc = client->GetViewLocation();
		//CamRot = client->GetViewRotation();

		if (FollowMethod == LookAtLocation || FollowMethod == FollowCamera)
		{
			NewLoc = CamLoc;
			NewLoc = NewLoc.GridSnap(GridSnapSize);
			NewLoc.Z = AttachParent->GetComponentLocation().Z;
			AttachParent->SetWorldLocation(NewLoc);
		}
		else
		{
			AttachParent->SetRelativeLocation(FVector(0, 0, 0)); //Reset location
		}

		float Distance = FMath::Abs(CamLoc.Z - AttachParent->GetComponentLocation().Z);

		if (ScaleByDistance && Distance > ScaleStartDistance)
		{
			Distance = Distance - ScaleStartDistance;
			Distance = FMath::Max(Distance, 0.f);

			float DistScale = Distance / ScaleDistanceFactor;
			DistScale = FMath::Clamp(DistScale, ScaleMin, ScaleMax);
			AttachParent->SetRelativeScale3D(FVector(DistScale, DistScale, 1));
		}
		else if (ScaleByDistance)
		{
			AttachParent->SetRelativeScale3D(FVector(ScaleMin, ScaleMin, 1));
		}
		else
		{
			AttachParent->SetRelativeScale3D(FVector(1, 1, 1));
		}

// 		if (ScaleByDistance && FMath::Abs(CamLoc.Z - AttachParent->GetComponentLocation().Z) > ScaleStartDistance)
// 		{
// 			float DistScale = FMath::Abs(CamLoc.Z - AttachParent->GetComponentLocation().Z) / ScaleDistanceFactor;
// 			DistScale = FMath::Clamp(DistScale, ScaleMin, ScaleMax);
// 			AttachParent->SetRelativeScale3D(FVector(DistScale, DistScale, 1)); //Scale only on x & y axis
// 		}
// 		else if (!ScaleByDistance)
// 		{
// 			AttachParent->SetRelativeScale3D(FVector(1, 1, 1)); //Reset scale
// 		}
		return;
	}
#endif

	if (World->WorldType == EWorldType::Game || World->WorldType == EWorldType::PIE)
	{
		if (!GEngine || !GEngine->GetFirstLocalPlayerController(World)) return;
		
		GEngine->GetFirstLocalPlayerController(World)->PlayerCameraManager->GetCameraViewPoint(CamLoc, CamRot);

		if (GEngine->GetFirstLocalPlayerController(World)->GetPawn()) //null check
		{
			PawnLoc = GEngine->GetFirstLocalPlayerController(World)->GetPawn()->GetActorLocation();
		}
		else
		{
			PawnLoc = AttachParent->GetComponentLocation();
		}
	}

	switch (FollowMethod)
	{
		case LookAtLocation:
			if (!FMath::SegmentPlaneIntersection(CamLoc, CamLoc + CamRot.Vector() * MaxLookAtDistance, FPlane(AttachParent->GetComponentLocation(), FVector(0, 0, 1)), NewLoc))
			{
				NewLoc = CamLoc + CamRot.Vector() * MaxLookAtDistance;
			}
			break;
		case FollowCamera:
			NewLoc = CamLoc;
			break;
		case FollowPawn:
			NewLoc = PawnLoc;
			break;
		default:
			break;
	};

	//UE_LOG(LogTemp, Warning, TEXT("Camera Z Distance from Plane: %f"), FMath::Abs(CamLoc.Z - AttachParent->GetComponentLocation().Z));

	float Distance = FMath::Abs(CamLoc.Z - AttachParent->GetComponentLocation().Z);

	if (ScaleByDistance && Distance > ScaleStartDistance)
	{
		Distance = Distance - ScaleStartDistance;
		Distance = FMath::Max(Distance, 0.f);

		float DistScale = Distance / ScaleDistanceFactor;
		DistScale = FMath::Clamp(DistScale, ScaleMin, ScaleMax);
		AttachParent->SetRelativeScale3D(FVector(DistScale, DistScale, 1));
	}
	else if (ScaleByDistance)
	{
		AttachParent->SetRelativeScale3D(FVector(ScaleMin, ScaleMin, 1));
	}
	else
	{
		AttachParent->SetRelativeScale3D(FVector(1, 1, 1));
	}

	if (FollowMethod == Stationary) return;

	NewLoc = NewLoc.GridSnap(GridSnapSize);
	NewLoc.Z = AttachParent->GetComponentLocation().Z;
	AttachParent->SetWorldLocation(NewLoc);
}
