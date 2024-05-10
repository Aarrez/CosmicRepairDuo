#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedActionKeyMapping.h"
#include "Equipment/Red_EquipmentComponent.h"
#include "Red_CharacterController.generated.h"

class UInputDataConfig;
class ARed_Backpack;

UCLASS()
class ARed_CharacterController : public ACharacter
{
	GENERATED_BODY()
	
public:
	ARed_CharacterController();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category="InputMapping")
	UInputMappingContext* InputMapping = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InputConfig")
	UInputDataConfig* InputConfig = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float SprintMaxSpeed = 600.0f;

	UPROPERTY(EditDefaultsOnly, Category="Roots")
	TObjectPtr<USceneComponent> BackpackRoot = nullptr;

	UPROPERTY(EditDefaultsOnly, Category="Roots")
	TObjectPtr<USceneComponent> ToolRoot = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<URed_EquipmentComponent> EquipmentComponent = nullptr;

	UFUNCTION(BlueprintCallable)
	void SpawnBackpack(UClass* CompClass, FName CompName = NAME_None);
	
protected:
private:

	UFUNCTION()
	void GetEquipBackPack(ARed_Backpack* pack);

	void HandleMovement(const FInputActionInstance& ctx);

	void HandleLook(const FInputActionInstance& ctx);

	void HandleJumpInput(const FInputActionInstance& ctx);
	void HandleSprintInput(const FInputActionInstance& ctx);

	void HandleInteractInput(const FInputActionInstance& ctx);
	void HandleDropInput(const FInputActionInstance& ctx);

	
	
};
