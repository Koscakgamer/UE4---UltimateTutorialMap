#pragma once
#include "GameFramework/Actor.h"
#include "DayNightLight.generated.h"
/**
*
*/
UCLASS()
class ADayNightLight : public AActor
{
	GENERATED_UCLASS_BODY()
		void Tick(float DeltaSeconds) OVERRIDE;
		virtual void BeginPlay() OVERRIDE;

public:
	UPROPERTY(VisibleAnywhere, Category = "My_Light")
		TSubobjectPtr<UDirectionalLightComponent> lightComp;
};