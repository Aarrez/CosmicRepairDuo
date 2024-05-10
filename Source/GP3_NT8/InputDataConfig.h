#pragma once
#include "InputAction.h"
#include "InputDataConfig.generated.h"

UCLASS()
class UInputDataConfig : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UInputAction* MoveInputAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UInputAction* LookInputAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UInputAction* JumpInputAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UInputAction* SprintInputAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UInputAction* DropInputAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UInputAction* InteractInputAction = nullptr;
};
