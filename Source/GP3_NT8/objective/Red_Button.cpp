#include "Red_Button.h"
#include "Components/BoxComponent.h"
#include "Red_ObjectiveComponent.h"

ARed_Button::ARed_Button()
{
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	ButtonCollider = CreateDefaultSubobject<UBoxComponent>("ButtonCollider");
	ButtonCollider->SetupAttachment(Root);
	ButtonCollider->OnComponentBeginOverlap.AddDynamic(this, &ARed_Button::HandleBeginOverlap);

	ObjectiveComponent = CreateDefaultSubobject<URed_ObjectiveComponent>("ObjectiveComponent");
}

void ARed_Button::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bHasBeenPressed == false)
	{
		bHasBeenPressed = true;
		
		if (PuzzleManager)
		{
			OnButtonPressd();
			auto* Recever = PuzzleManager->FindComponentByClass<URed_ObjectiveComponent>();
			if (Recever)
			{
				Recever->OnConplete.Broadcast();
			}
			
		}
	}
}
