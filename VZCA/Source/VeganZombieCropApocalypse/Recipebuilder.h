// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DetectionComponent.h"
#include "Recipebuilder.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VEGANZOMBIECROPAPOCALYPSE_API URecipebuilder : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URecipebuilder();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
		TMap<FName, int>& GetRecipeMap();

	UFUNCTION(BlueprintCallable)
		FString StringifyMap(const TMap<FName, int> &map_);
	
private:

	TArray<FName> Ingredients;
	TMap<FName, int> RecipeMap;
	TArray<FName> VegetableKeys;
	TArray<int> VegetableValues;

	UFUNCTION(BlueprintCallable)
		void CreateRecipe();

	UFUNCTION(BlueprintCallable)
		void UpdateRecipeUI();

	UFUNCTION(BlueprintCallable)
		bool IsRecipeComplete() const;

	UFUNCTION(BlueprintCallable)
		void ResetRecipeMap();

	UFUNCTION(BlueprintCallable)
		TArray<FName>& GetKeyArray();

	UFUNCTION(BlueprintCallable)
		TArray<int>& GetValueArray();
};