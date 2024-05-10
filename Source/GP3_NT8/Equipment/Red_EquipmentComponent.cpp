#include "Red_EquipmentComponent.h"
#include "Red_Backpack.h"
#include "Red_Tools.h"
#include "GP3_NT8/Red_CharacterController.h"

URed_EquipmentComponent::URed_EquipmentComponent()
{
	
}

void URed_EquipmentComponent::BeginPlay()
{
	OwningController = Cast<ARed_CharacterController>(GetOwner());
}


void URed_EquipmentComponent::EquipBackPack(UClass* _backpack)
{
	
}

void URed_EquipmentComponent::EquipTool(ARed_Tools* _tool)
{
}

void URed_EquipmentComponent::DropBackPack()
{
	Backpack->DropBackPack();
	Backpack = nullptr;
}

void URed_EquipmentComponent::DropTool()
{
}

