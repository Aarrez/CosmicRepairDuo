#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Red_Debris_Interface.generated.h"

UINTERFACE(MinimalAPI)
class URed_Debris_Interface : public UInterface
{
	GENERATED_BODY()
};

class GP3_NT8_API IRed_Debris_Interface
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StartWashing(float WashTick);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StopWashing(float WashTick);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void CompleteWashing();
	
};
