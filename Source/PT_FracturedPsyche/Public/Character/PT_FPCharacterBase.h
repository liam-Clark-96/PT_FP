// Copyright Liam Clark

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "PT_FPCharacterBase.generated.h"

class UAbilitySystemComponent; //Forward Declaration
class UGameplayEffect; //Forward Declaration
class UGameplayAbility; //Forward Declaration

UCLASS()
class PT_FRACTUREDPSYCHE_API APT_FPCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APT_FPCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override; //Get Ability System Component

	virtual void PossessedBy(AController* NewController) override; //Called when the character is possessed

	virtual void OnRep_PlayerState() override; //Called when the PlayerState is replicated

protected:

	virtual void InitAbilityActorInfo(); //Initialize Ability Actor Info

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	virtual void BeginPlay() override;
};


