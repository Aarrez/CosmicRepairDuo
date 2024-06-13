#include "MainLevelGameMode.h"
#include "GP3_NT8/Red_CharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"

void AMainLevelGameMode::BeginPlay()
{
	
}

void AMainLevelGameMode::GetAllNecessaryActors()
{
	TArray<AActor*> FoundPlayers;
	TArray<AActor*> FoundStartPoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARed_CharacterController::StaticClass(), FoundPlayers);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), FoundStartPoints);
}


