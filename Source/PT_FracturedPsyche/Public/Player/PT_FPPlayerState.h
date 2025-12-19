// Copyright Liam Clark

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"

#include "PT_FPPlayerState.generated.h"

class UAbilitySystemComponent; //Forward Declaration
class UAttributeSet; //Forward Declaration

UCLASS()
class PT_FRACTUREDPSYCHE_API APT_FPPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	APT_FPPlayerState(); //Constructor

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override; //Get Ability System Component
	UAttributeSet* GetAttributeSet() const { return AttributeSet; } //Get Attribute Set
	

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent; //Ability System Component

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet; //Holds the Attributes

};
