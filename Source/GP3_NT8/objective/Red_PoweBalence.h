#pragma once 
#include "Blueprint/UserWidget.h"
#include "Red_PoweBalence.generated.h"

UCLASS()
class URedPowerBalance : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	int sliderValuChack(float Value);

	UFUNCTION(BlueprintCallable)
	int SliderValueCheck(float Value, float RedBarHigher, float RedBarLower, float YellowBarLower, float YellowBarHigher);
};