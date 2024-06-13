#pragma once
#include "GameFramework/Actor.h"
#include "Red_Button.generated.h"

class UBoxComponent;
class URed_ObjectiveComponent;

UCLASS()
class ARed_Button : public AActor
{
	GENERATED_BODY()

public:
	ARed_Button();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	URed_ObjectiveComponent* ObjectiveComponent = nullptr;

	UFUNCTION(BlueprintImplementableEvent)
	void OnButtonPressd();

	UFUNCTION(BlueprintImplementableEvent)
	void OnButterRelease();

	UFUNCTION(BlueprintImplementableEvent)
	void HandlePuzzleComplete();

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	AActor* PuzzleManager;

private:

	



	UFUNCTION()
	void HandleBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void HendleEndOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root = nullptr;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* ButtonCollider = nullptr;

	

	UPROPERTY(VisibleAnywhere)
	bool bHasBeenPressed = false;
};
