#include "Red_WeldingActor.h"


void ARed_WeldingActor::StartRepair(float RepairTick)
{
	if(CurrentDamage <= DamageToRepair)
		CurrentDamage += RepairTick;
	else
		IEquipment_Interface::Execute_WeldingDone(this);
}

