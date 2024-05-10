#pragma once
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Red_Backpack.generated.h"

class ARed_Tools;

UCLASS(Blueprintable, BlueprintType)
class ARed_Backpack : public AActor
{
	GENERATED_BODY()

	ARed_Backpack();
public:
	
	//This could be either power or oxygen
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Meter")
	UActorComponent* MeterComponent = nullptr;
	//The tool the player is using
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tool")
	ARed_Tools* Tool = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collison")
	USphereComponent* SphereComponent = nullptr;
	
	UFUNCTION(BlueprintCallable)
	void DrainPower(UActorComponent* Meter);

	UFUNCTION(BlueprintCallable)
	void DropBackPack();

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	 
};
