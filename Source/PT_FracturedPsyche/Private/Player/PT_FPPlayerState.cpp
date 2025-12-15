// Copyright Liam Clark


#include "Player/PT_FPPlayerState.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"

APT_FPPlayerState::APT_FPPlayerState()
{
	SetNetUpdateFrequency(100.f); //Replication Frequency based on GAS needs

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent")); //Create Ability System Component, default subobjects are constructed once per class instance and properly replicated

	AbilitySystemComponent->SetIsReplicated(true); //Set Ability System Component to Replicate
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed); //Set Replication Mode to Mixed for better performance

	AttributeSet = CreateDefaultSubobject<UAttributeSet>(TEXT("AttributeSet")); //Create Attribute Set as Default Subobject 

}

UAbilitySystemComponent* APT_FPPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent; //Return Ability System Component
}
