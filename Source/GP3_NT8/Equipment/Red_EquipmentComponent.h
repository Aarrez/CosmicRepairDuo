#pragma once
#include "Components/ActorComponent.h"
#include "Red_Backpack.h"
#include "Red_EquipmentComponent.generated.h"

class ARed_Backpack;
class ARed_Tools;

UCLASS(meta = (BlueprintSpawnableComponent))
class URed_EquipmentComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	URed_EquipmentComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
	TSoftObjectPtr<ARed_Backpack> Backpack = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
	TSoftObjectPtr<ARed_Tools> Tool = nullptr;

};
