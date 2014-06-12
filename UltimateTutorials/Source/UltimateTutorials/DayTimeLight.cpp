

#include "UltimateTutorials.h"
#include "DayTimeLight.h"


ADayTimeLight::ADayTimeLight(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;
	lightComp = PCIP.CreateDefaultSubobject<UDirectionalLightComponent>(this, "DirLight");
	RootComponent = lightComp;
}

void ADayTimeLight::Tick(float DeltaSeconds){

	Super::Tick(DeltaSeconds);

	FRotator SunRot = GetActorRotation();
	MyRot.X += SunSpeed*DeltaSeconds;
	if (MyRot.X > 360)
		MyRot.X -= 360;
	SunRot.Pitch = MyRot.X;
	SunRot.Roll = MyRot.Y;
	SunRot.Yaw = MyRot.Z;
	SetActorRotation(SunRot);

}

void ADayTimeLight::BeginPlay()
{
	Super::BeginPlay();
	lightComp->SetMobility(EComponentMobility::Movable);
	FRotator SunRot = GetActorRotation();
	MyRot.X = SunRot.Pitch;
	MyRot.Y = SunRot.Roll;
	MyRot.Z = SunRot.Yaw;
}
