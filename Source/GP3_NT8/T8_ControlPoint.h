#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "T8_ControlPoint.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnControlPointSpawned, FVector, position);

UCLASS()
class AT8_ControlPoint : public AActor
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable)
	FOnControlPointSpawned OnSpawned;
	
};
