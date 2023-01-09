// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DetectionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UMPGOREPACK_API UDetectionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDetectionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
		void AddVegetable(AActor* Actor);

	UFUNCTION(BlueprintCallable)
		int GetCount(const FName& Vegetable);

	TMap<FName, uint32> map;

private: 
	
	TSet<TWeakObjectPtr<AActor>> VegetableSet;
	void Cleanup();
};
