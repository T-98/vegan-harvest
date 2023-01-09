// Fill out your copyright notice in the Description page of Project Settings.


#include "DetectionComponent.h"

// Sets default values for this component's properties
UDetectionComponent::UDetectionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDetectionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDetectionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDetectionComponent::AddVegetable(AActor* Actor)
{
	if(!Actor->ActorHasTag("Vegetable")) return;
	bool bAlreadyInSet = false;
	//checks whether an element is already in the set and sets the bool to true or else adds the element to the set
	VegetableSet.Add(Actor, &bAlreadyInSet);
	if(bAlreadyInSet == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Adding..."));
		UStaticMeshComponent* StaticMesh = Actor->FindComponentByClass<UStaticMeshComponent>();
		if(StaticMesh!=nullptr && !StaticMesh->ComponentTags.IsEmpty())
		{
			const FName& Tag = StaticMesh->ComponentTags[0];
			UE_LOG(LogTemp, Display, TEXT("%s"), *StaticMesh->ComponentTags[0].ToString());
			if(map.Contains(Tag))++map[Tag];
			else map.Add(Tag, 1);
		}
	}
	Cleanup();
}

void UDetectionComponent::Cleanup()
{
	if(VegetableSet.Num() > 20)
	{
		TArray<TWeakObjectPtr<AActor>> ToRemove;

		//Iterating over the set and adding invalid object references to the remove array to ensure iterator stability
		//Don't want to remove objects as we iterate over a container to not mess up the iterators
		for(auto& item : VegetableSet)
		{
			if(!item.IsValid())ToRemove.Add(item);
		}

		for(auto& item : ToRemove)
		{
			VegetableSet.Remove(item);
		}
	}
}

int UDetectionComponent::GetCount(const FName& Vegetable)
{
	if(map.Contains(Vegetable))
	{
		return map[Vegetable];
	}
	
	return 0;
}

static FString StringifyMap(const TMap<FName, uint32> &map) {
    FString out;
    bool bFirst = true;
    for (const auto &pair : map) {
        if (bFirst)
            bFirst = false;
        else
            out += "; ";
        out += pair.Key.ToString() + TEXT(" => ") + FString::FromInt(pair.Value);
    }
    return out;
}