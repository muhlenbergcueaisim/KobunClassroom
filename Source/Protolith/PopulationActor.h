// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" 
#include "GameFramework/Actor.h"
#include "ProtoPawn.h"
#include <cstdlib>
#include "DNA.h"
#include "PopulationActor.generated.h"


UCLASS()
class PROTOLITH_API APopulationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APopulationActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*
	*	PROPERTIES
	*/

	// Number of seed individuals
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
		int initialSize = 9;

	// the current number of individuals
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
		int currentSize;

	// enable or disable crossover
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
		bool crossover = true;

	// the probability of crossover happening
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith", meta = (UIMin = "0.0", UIMax = "1.0"))
		float crossoverChance = 0.2;

	// the percentage of the population to keep at the end of each generation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (UIMin = "0.1", UIMax = "0.5"))
		float recuringPopulation = 0.2;

	// the probability of mutation happening
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (UIMin = "0.0", UIMax = "1.0"))
		float mutateChance = 0.0;

	// the largest effect that mutation could have
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (UIMin = "1"))
		int maxMutateChange = 1;

	// a flag for the user to stop making new generations
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool stop = false;

	// a flag to say weather or not you need two different pawns as parents
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool twoParents = true;

	// an array of pointers to actors in the population
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AProtoPawn*> Population;

	// allows us to select a blueprint of type ProtoPawn for the simulation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
		TSubclassOf<AProtoPawn> PawnType;

	/*
	*	FUNCTIONS
	*/

	// initializes the population
	UFUNCTION(BlueprintCallable, Category = "Protolith")
		TArray<AProtoPawn*> PopGenesis(TArray<FTransform> spawnTransform);
	
	// evaluates the fitness of each member of the population
	UFUNCTION(BlueprintCallable, Category = "Protolith")
		void EvaluateFitness(TArray<AProtoPawn*> Pop);

	// removes the weakest pawns
	UFUNCTION(BlueprintCallable, Category = "Protolith")
		void eliminate();

	// refills the population with a new generation
	UFUNCTION(BlueprintCallable, Category = "Protolith")
		void Reproduce(TArray<AProtoPawn*> pop, TArray<FTransform> newTransforms);

	// handles the structure of the genetic algorithm
	UFUNCTION(BlueprintCallable, Category = "Protolith")
		void geneticAlgorithm();

	// checks if all of the pawns have had their fitness's set
	UFUNCTION(BlueprintCallable, Category = "Protolith")
		bool fitnessesSet();

	// gets an index for a parent
	UFUNCTION(BlueprintCallable, Category = "Protolith")
		int getIndex();
    
    // swap function
    UFUNCTION(BlueprintCallable)
        void swap(int a, int b);
    
    // partition for quicksort
    UFUNCTION(BlueprintCallable)
        int partition(int low, int high);
    
    // sorting function
    UFUNCTION(BlueprintCallable)
        void sort(int low, int high);
    
    
};
