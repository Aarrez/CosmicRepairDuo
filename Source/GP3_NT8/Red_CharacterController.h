#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedActionKeyMapping.h"
#include "Equipment/Red_EquipmentComponent.h"
#include "Red_CharacterController.generated.h"

class URedPuzzleInputDataConfig;
class UInputDataConfig;
class ARed_Backpack;

UCLASS()
class ARed_CharacterController : public ACharacter
{
	GENERATED_BODY()
	
public:

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category="InputMapping")
	UInputMappingContext* InputMapping = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InputConfig")
	UInputDataConfig* InputConfig = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "InputMapping")
	UInputMappingContext* PuzzleInoutMapping = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "InputConfig")
	URedPuzzleInputDataConfig* PuzzleInputConfig = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float SprintMaxSpeed = 600.0f;
	
	UFUNCTION(BlueprintCallable)
	void SpawnBackpack(UClass* CompClass, FName CompName = NAME_None);
	
	int NumberOfLightsOn = 0;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TArray<float> DistanceChacks;

protected:
private:

	UFUNCTION()
	void GetEquipBackPack(ARed_Backpack* pack);

	UFUNCTION(BlueprintCallable)
	void HandleMovement(const FVector2D& MoveAxis);

	UFUNCTION(BlueprintCallable)
	void HandleLook(const FVector2D& LookAxis);

	UFUNCTION(BlueprintCallable)
	void HandleJumpInput(const bool& Jumped);
	UFUNCTION(BlueprintCallable)
	void HandleSprintInput(const FInputActionInstance& ctx);

	UFUNCTION(BlueprintCallable)
	void HandleInteractInput(const FInputActionInstance& ctx);
	UFUNCTION(BlueprintCallable)
	void HandleDropInput(const FInputActionInstance& ctx);

	UFUNCTION(BlueprintCallable)
	int DistanceToObjectiveCheck(AActor* Objective);
	
	
};
