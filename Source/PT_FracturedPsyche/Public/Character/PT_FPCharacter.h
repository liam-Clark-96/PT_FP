// Copyright Liam Clark

#pragma once

#include "CoreMinimal.h"
#include "Character/PT_FPCharacterBase.h"
#include "Player/PT_FPPlayerState.h"
#include "PT_FPCharacter.generated.h"

/**
 * 
 */

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;
class UPointLightComponent;

UCLASS()
class PT_FRACTUREDPSYCHE_API APT_FPCharacter : public APT_FPCharacterBase
{
	GENERATED_BODY()

public:
	APT_FPCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component|SpringArm")
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component|Camera")
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component|Lantern")
	TObjectPtr<UStaticMeshComponent> LanternMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component|Lantern|Light")
	TObjectPtr<UPointLightComponent> LanternLightComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Socket")
	FName LanternSocketName = TEXT("Left_LanternSocket"); // Create the socket on the left hand bone

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Component|SpringArm")
	float SpringArmLength = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Component|Camera")
	float CameraPitch = 0.0f;

};