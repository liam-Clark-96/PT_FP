// Copyright Liam Clark

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "PT_FPCharacterBase.generated.h"

class UAbilitySystemComponent; //Forward Declaration
class UAttributeSet; //Forward Declaration

UCLASS()
class PT_FRACTUREDPSYCHE_API APT_FPCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APT_FPCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override; //Get Ability System Component

	UAttributeSet* GetAttributeSet() const { return AttributeSet; } //Get Attribute Set


protected:

	virtual void InitAbilityActorInfo(); //Initialize Ability Actor Info

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;


	virtual void BeginPlay() override;
};


