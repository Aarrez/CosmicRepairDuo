#include "Red_CharacterController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputDataConfig.h"
#include "Equipment/Red_Backpack.h"

void ARed_CharacterController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	Input->BindAction(InputConfig->InteractInputAction, ETriggerEvent::Triggered, this, &ARed_CharacterController::HandleInteractInput);
	Input->BindAction(InputConfig->DropInputAction, ETriggerEvent::Triggered, this, &ARed_CharacterController::HandleDropInput);
}

void ARed_CharacterController::SpawnBackpack(UClass* CompClass, FName CompName)
{
	/*if(CompName.IsNone())
		CompName = "DefaultName";

	AActor* NewActor = NewObject<AActor>(this, CompClass, CompName);
	if(!NewActor)
	{
		if(GEngine) GEngine->AddOnScreenDebugMessage(
			-1, 15.0f, FColor::Red, TEXT("Error when creating backpack componet"));
		return;
	}
	NewActor->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	NewActor->SetActorRelativeLocation(BackpackRoot->GetRelativeLocation());*/
}


void ARed_CharacterController::GetEquipBackPack(ARed_Backpack* pack)
{
}

void ARed_CharacterController::HandleMovement(const FVector2D& MoveAxis)
{
	FRotator ControlRotation = GetControlRotation();
	ControlRotation.Pitch = 0.f;
	FVector Forward = ControlRotation.Quaternion().GetForwardVector();
	FVector Side = ControlRotation.Quaternion().GetRightVector();
	AddMovementInput(Forward, MoveAxis.Y);
	AddMovementInput(Side, MoveAxis.X);
	
}

void ARed_CharacterController::HandleLook(const FVector2D& LookAxis)
{
	AddControllerPitchInput(LookAxis.Y);
	AddControllerYawInput(LookAxis.X);
}

void ARed_CharacterController::HandleJumpInput(const bool& JumpIsPressed)
{
	Jump();
}

void ARed_CharacterController::HandleSprintInput(const FInputActionInstance& ctx)
{
	bool SprintIsPressed = ctx.GetValue().Get<bool>();
	if(SprintIsPressed)
		GetCharacterMovement()->MaxWalkSpeed = SprintMaxSpeed;
	else
		GetCharacterMovement()->MaxWalkSpeed = 600.0;
}

void ARed_CharacterController::HandleInteractInput(const FInputActionInstance& ctx)
{
	bool InteractIsPressed = ctx.GetValue().Get<bool>();
}

void ARed_CharacterController::HandleDropInput(const FInputActionInstance& ctx)
{
	bool DropIsPressed = ctx.GetValue().Get<bool>();
}

int ARed_CharacterController::DistanceToObjectiveCheck(AActor* Objective)
{
	float DistanceToObjective = FVector::Dist(this->GetActorLocation(), Objective->GetActorLocation());
	if (DistanceChacks.Num() == 6)
	{
		if (DistanceToObjective <= DistanceChacks[0])
		{
			NumberOfLightsOn = 6;
		}
		else if (DistanceToObjective <= DistanceChacks[1])
		{
			NumberOfLightsOn = 5;
		}
		else if (DistanceToObjective <= DistanceChacks[2])
		{
			NumberOfLightsOn = 4;
		}
		else if (DistanceToObjective <= DistanceChacks[3])
		{
			NumberOfLightsOn = 3;
		}
		else if (DistanceToObjective <= DistanceChacks[4])
		{
			NumberOfLightsOn = 2;
		}
		else if (DistanceToObjective <= DistanceChacks[5])
		{
			NumberOfLightsOn = 1;
		}
		else
		{
			NumberOfLightsOn = 0;
		}
	}
	

	return NumberOfLightsOn;
}







