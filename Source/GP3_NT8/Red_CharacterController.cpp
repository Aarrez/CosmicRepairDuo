#include "Red_CharacterController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputDataConfig.h"
#include "Equipment/Red_Backpack.h"

ARed_CharacterController::ARed_CharacterController()
{
	BackpackRoot = CreateDefaultSubobject<USceneComponent>("BackpackRoot");
	ToolRoot = CreateDefaultSubobject<USceneComponent>("ToolRoot");
	EquipmentComponent = CreateDefaultSubobject<URed_EquipmentComponent>("EquipmentComponent");
}

void ARed_CharacterController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(PlayerController->Player);

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if(!InputConfig && GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red,
			TEXT("Inputconfig needs to be assigned"));
		return;
	}
		
	Input->BindAction(InputConfig->MoveInputAction, ETriggerEvent::Triggered, this, &ARed_CharacterController::HandleMovement);
	
	Input->BindAction(InputConfig->LookInputAction, ETriggerEvent::Triggered, this, &ARed_CharacterController::HandleLook);
	
	Input->BindAction(InputConfig->JumpInputAction, ETriggerEvent::Started, this, &ARed_CharacterController::HandleJumpInput);
	
	Input->BindAction(InputConfig->SprintInputAction, ETriggerEvent::Started, this, &ARed_CharacterController::HandleSprintInput);
	Input->BindAction(InputConfig->SprintInputAction, ETriggerEvent::Canceled, this, &ARed_CharacterController::HandleSprintInput);

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

void ARed_CharacterController::HandleMovement(const FInputActionInstance& ctx)
{
	FVector2D MoveAxis = ctx.GetValue().Get<FVector2D>();
	FRotator ControlRotation = GetControlRotation();
	ControlRotation.Pitch = 0.f;
	FVector Forward = ControlRotation.Quaternion().GetForwardVector();
	FVector Side = ControlRotation.Quaternion().GetRightVector();
	AddMovementInput(Forward, MoveAxis.Y);
	AddMovementInput(Side, MoveAxis.X);
	
}

void ARed_CharacterController::HandleLook(const FInputActionInstance& ctx)
{
	FVector2D LookAxis = ctx.GetValue().Get<FVector2D>();
	AddControllerPitchInput(LookAxis.Y);
	AddControllerYawInput(LookAxis.X);
}

void ARed_CharacterController::HandleJumpInput(const FInputActionInstance& ctx)
{
	bool JumpIsPressed = ctx.GetValue().Get<bool>();
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





