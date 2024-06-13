#pragma once
#include "Components/ActorComponent.h"
#include "Red_ObjectiveComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FObjectiveTriggerSignature);

UCLASS(meta = (BlueprintSpawnableComponent))
class URed_ObjectiveComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FObjectiveTriggerSignature OnConplete;

	UPROPERTY(BlueprintAssignable)
	FObjectiveTriggerSignature OnUnComplete;
};