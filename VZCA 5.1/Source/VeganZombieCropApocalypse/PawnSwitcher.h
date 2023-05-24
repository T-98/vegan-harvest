// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnSwitcher.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VEGANZOMBIECROPAPOCALYPSE_API UPawnSwitcher : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPawnSwitcher();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SwitchPawn();


	// A variable that stores the pawn movement component of the current pawn
    UPawnMovementComponent* CharacterPawnMovement;

    // A variable that stores the other pawn that already exists in the world
    APawn* OtherPawn;

    // A variable that stores the tag for the current pawn. Warning! should be set in construction script of the pawn blueprint
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Switcher Tags")
    FName CurrentPawnTag;

    // A variable that stores the tag for the other pawn. Warning! should be set in construction script of the pawn blueprint
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Switcher Tags")
    FName OtherPawnTag;

	  // A variable that stores the camera component of the current pawn
    UCameraComponent* CurrentPawnCamera;

    // A variable that stores the camera component of the other pawn
    UCameraComponent* OtherPawnCamera;

    // A variable that stores the blend time for the camera transition in seconds
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Switch Variables")
    float CameraBlendTime;


		
};
