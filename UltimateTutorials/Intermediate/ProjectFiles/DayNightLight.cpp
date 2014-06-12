#include "UltimateTutorials.h" //<- Das hier durch deine Projekt Header austauschen
#include "DayNightLight.h"

ADayNightLight::ADayNightLight(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	lightComp = PCIP.CreateDefaultSubobject<UDirectionalLightComponent>(this, "DirLight");
	RootComponent = lightComp;
}

void ADayNightLight::Tick(float DeltaSeconds){
		AddActorLocalRotation(FRotator(3, 0, 0));
}

void ADayNightLight::BeginPlay()
{
	Super::BeginPlay();
	lightComp->SetMobility(EComponentMobility::Movable);
}