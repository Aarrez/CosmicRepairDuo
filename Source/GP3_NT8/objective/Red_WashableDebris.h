#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GP3_NT8/Interfaces/Red_Debris_Interface.h"
#include "Red_WashableDebris.generated.h"

UCLASS()
class ARed_WashableDebris : public AActor, public IRed_Debris_Interface
{
public:
	GENERATED_BODY()
};
