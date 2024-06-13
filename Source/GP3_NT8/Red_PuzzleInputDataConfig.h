#pragma once
#include "InputAction.h"
#include "Red_PuzzleInputDataConfig.generated.h"

UCLASS()
class URedPuzzleInputDataConfig : public UDataAsset 
{

	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UInputAction* PuzzleInputAction = nullptr;
};