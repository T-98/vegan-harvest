// Fill out your copyright notice in the Description page of Project Settings.


#include "Recipebuilder.h"

// Sets default values for this component's properties
URecipebuilder::URecipebuilder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Ingredients.Add(FName("Pumpkin"));
	Ingredients.Add(FName("Cabbage"));
	Ingredients.Add(FName("RedBellPepper"));
	Ingredients.Add(FName("GreenBellPepper"));
	Ingredients.Add(FName("Eggplant"));
	Ingredients.Add(FName("Garlic"));

	FName defaultKey = "DefaultKey";
	VegetableKeys.Add(defaultKey);

	int defaultVal = 0;
	VegetableValues.Add(defaultVal);
	// ...
}


// Called when the game starts
void URecipebuilder::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URecipebuilder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URecipebuilder::CreateRecipe()
{
	int numIngredients = FMath::RandRange(1, 10);
	while(numIngredients > 0)
	{
		//Get a random ingredient
		FName Ingredient = Ingredients[FMath::RandRange(0, 5)];

		//add it to the map or increase count basd on if it already exists or not
		if(RecipeMap.Contains(Ingredient))++RecipeMap[Ingredient];
		else RecipeMap.Add(Ingredient, 1);

		//decrement numIngredients
		--numIngredients;
	}
}

//reset recipe map to be used again
void URecipebuilder::ResetRecipeMap()
{
	RecipeMap.Reset();
}


void URecipebuilder::UpdateRecipeUI()
{
	//Get the detection component
	UDetectionComponent* DetectionComponent = GetOwner()->FindComponentByClass<UDetectionComponent>();

	//Get the map of vegetables that the player actually brought in
	TMap<FName, int>& DetectionMap = DetectionComponent->GetMap();

	for(auto& p : RecipeMap)
	{
		//if the veggie exists in the player's map
		if(DetectionMap.Contains(p.Key))
		{
			int count = 0, i = 0;
			//if the player has more of a veggie
			if(*DetectionMap.Find(p.Key) > p.Value)
			{
				count = p.Value;
				DetectionMap[p.Key] = DetectionMap[p.Key] - p.Value;
				p.Value = 0;
			}
			//if the recipe has more of a veggie
			else
			{
				count = DetectionMap[p.Key];
				p.Value = p.Value - DetectionMap[p.Key];
				DetectionMap[p.Key] = 0;
			}

			//Despawn veggies that have been consumed
			TSet<TWeakObjectPtr<AActor>>& VeggieSet = DetectionComponent->GetVegetableSet();
			if(count > 0)
			{
				for(auto& elem : VeggieSet)
				{
					if(elem.IsValid() && elem->FindComponentByClass<UStaticMeshComponent>()->ComponentTags[0] == p.Key) 
					{
						elem->Destroy();
						if(++i >= count)break;
					}
				}
				DetectionComponent->Cleanup();
			}

			//remove the veggie from the map if the count is 0
			//if(p.Value == 0) RecipeMap.Remove(p.Key);

		}
		UE_LOG(LogTemp, Warning, TEXT("KEY: %s"), *p.Key.ToString());
		UE_LOG(LogTemp, Warning, TEXT("VALUE: %d"), p.Value);
	}
}

TMap<FName, int>& URecipebuilder::GetRecipeMap()
{
	return RecipeMap;
}

TArray<FName>& URecipebuilder::GetKeyArray()
{
	RecipeMap.GenerateKeyArray(VegetableKeys);
	return VegetableKeys;
}

TArray<int>& URecipebuilder::GetValueArray()
{
	RecipeMap.GenerateValueArray(VegetableValues);
	return VegetableValues;
}

//check if all ingredients for the current recipe are delivered
bool URecipebuilder::IsRecipeComplete() const
{
	for(auto& p : RecipeMap)
	{
		if(p.Value != 0) return false;
	}
	return true;
}

FString URecipebuilder::StringifyMap(const TMap<FName, int> &map_) 
{
    FString out;
    bool bFirst = true;
    for (const auto &pair : map_) {
        if (bFirst)
            bFirst = false;
        else
            out += "; ";
        out += pair.Key.ToString() + TEXT(" => ") + FString::FromInt(pair.Value);
    }
    return out;
}