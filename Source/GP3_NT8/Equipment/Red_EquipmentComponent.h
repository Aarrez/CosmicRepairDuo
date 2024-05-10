#pragma once
#include "Components/ActorComponent.h"
#include "Red_Backpack.h"
#include "Red_EquipmentComponent.generated.h"

class ARed_Backpack;
class ARed_Tools;
class ARed_CharacterController;

UCLASS(meta = (BlueprintSpawnableComponent))
class URed_EquipmentComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	URed_EquipmentComponent();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Inventory")
	TSoftObjectPtr<ARed_Backpack> Backpack = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Inventory")
	TSoftObjectPtr<ARed_Tools> Tool = nullptr;

	UPROPERTY(VisibleAnywhere)
	ARed_CharacterController* OwningController = nullptr;
	
	UFUNCTION(BlueprintCallable)
	virtual void EquipBackPack(UClass* _backpack);

	UFUNCTION(BlueprintCallable)
	virtual void EquipTool(ARed_Tools* _tool);

	UFUNCTION(BlueprintCallable)
	virtual void DropBackPack();

	UFUNCTION(BlueprintCallable)
	virtual void DropTool();
};
