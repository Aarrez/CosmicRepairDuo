#include "T8_ControlPoint.h"

void AT8_ControlPoint::BeginPlay()
{
	Super::BeginPlay();
	OnSpawned.Broadcast(GetActorLocation());
}


