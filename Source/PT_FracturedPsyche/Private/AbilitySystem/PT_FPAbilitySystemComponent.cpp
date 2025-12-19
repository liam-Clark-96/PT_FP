// Copyright Liam Clark


#include "AbilitySystem/PT_FPAbilitySystemComponent.h"

void UPT_FPAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UPT_FPAbilitySystemComponent::EffectApplied); 
	// Subscribe to Effect Applied Delegate and bind to Effect Applied function
}

void UPT_FPAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer); //Get all asset tags from the effect spec
	EffectAssetTags.Broadcast(TagContainer); //Broadcast the tags using the delegate
}
