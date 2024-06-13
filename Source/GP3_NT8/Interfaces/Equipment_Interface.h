#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Equipment_Interface.generated.h"

UINTERFACE(MinimalAPI)
class UEquipment_Interface : public UInterface
{
	GENERATED_BODY()
};

class GP3_NT8_API IEquipment_Interface
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StartWelding(float RepairTick);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StartUsing();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StopUsing();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void WeldingDone();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	float DrainEnergy();
};
