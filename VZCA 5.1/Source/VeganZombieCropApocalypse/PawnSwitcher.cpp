// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnSwitcher.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"


// Sets default values for this component's properties
UPawnSwitcher::UPawnSwitcher()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPawnSwitcher::BeginPlay()
{
	Super::BeginPlay();

    //FindCurrentCamera (for use later with camerablend) and find pawn with specified tag
	CurrentPawnCamera = GetOwner()->FindComponentByClass<UCameraComponent>();
    for (TActorIterator<AActor> It(GetWorld()); It; ++It)
    {
        // Check if the actor has the tag stored in OtherPawnTag variable
        if (It->ActorHasTag(OtherPawnTag))
        {
            // Assign it to the other pawn variable and break the loop
            OtherPawn = Cast<APawn>(*It);

			// Find and assign its camera component to the other pawn camera variable
            OtherPawnCamera = OtherPawn->FindComponentByClass<UCameraComponent>();
            
            break;
        }
    }

    

}


// Called every frame
void UPawnSwitcher::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UPawnSwitcher::SwitchPawn()
{
    // Get the world and the player controller
    UWorld* World = GetWorld();
    APlayerController* PlayerController = World->GetFirstPlayerController();

    // Check if they are valid and the other pawn exists
    if (World && PlayerController && OtherPawn && OtherPawnCamera)
    {
        // Check if the current pawn has the tag stored in CurrentPawnTag variable by using HasTag function
        if (GetOwner()->ActorHasTag(CurrentPawnTag))
        {
            // Possess the other pawn
            PlayerController->Possess(OtherPawn);
        } else 

        {
            // Possess the original pawn
            PlayerController->Possess(Cast<APawn>(GetOwner()));
        }
    }
}



