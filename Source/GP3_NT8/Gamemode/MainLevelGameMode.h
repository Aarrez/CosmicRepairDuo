#pragma once
#include "GameFramework/GameMode.h"

#include "MainLevelGameMode.generated.h"

class ARed_CharacterController;
class APlayerStart;

UCLASS()
class AMainLevelGameMode : public AGameModeBase
{

	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	UFUNCTION()
	void GetAllNecessaryActors();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<ARed_CharacterController*> Players;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<APlayerStart*> PlayerStarts;

	UPROPERTY(EditDefaultsOnly)
	bool NoPlayers = false;
	UPROPERTY(EditDefaultsOnly)
	bool NoStartPoints = false;

	int ArrayIndex {0};
};
