#pragma once
#include "CoreMinimal.h"
#include "Interfaces/Equipment_Interface.h"
#include "Red_WeldingActor.generated.h"

UCLASS()
class ARed_WeldingActor : public AActor, public IEquipment_Interface
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly,  BlueprintReadWrite)
	float CurrentDamage = 0.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DamageToRepair = 10.0;
	
	UFUNCTION(BlueprintCallable)
	void StartRepair(float RepairTick);
};
