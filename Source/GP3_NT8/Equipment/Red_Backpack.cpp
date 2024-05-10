#include "Red_Backpack.h"
#include "Red_Tools.h"

ARed_Backpack::ARed_Backpack()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComponent->SetSphereRadius(300, true);
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ARed_Backpack::OnOverlapBegin);
}

void ARed_Backpack::DrainPower(UActorComponent* Meter)
{
}

void ARed_Backpack::DropBackPack()
{
}

void ARed_Backpack::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	this->AttachToActor(OtherActor, FAttachmentTransformRules::KeepRelativeTransform);
}
