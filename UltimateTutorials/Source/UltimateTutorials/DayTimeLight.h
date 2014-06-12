

#pragma once

#include "Engine/Light.h"
#include "DayTimeLight.generated.h"

/**
 * 
 */
UCLASS()
class ADayTimeLight : public ALight
{
	GENERATED_UCLASS_BODY()
		void Tick(float DeltaSeconds) OVERRIDE;
		virtual void BeginPlay() OVERRIDE;
		float SunSpeed = 0.5f;
		

	public:
		UPROPERTY(VisibleAnywhere, Category = "Light")
		TSubobjectPtr<UDirectionalLightComponent> lightComp;
	
	private:
		FVector MyRot;
	

};
