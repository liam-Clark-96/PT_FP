// Copyright Liam Clark

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "PT_FPAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer&) // Params: EffectAssetTags as FGameplayTagContainer to broadcast stored tags


/**
 * 
 */
UCLASS()
class PT_FRACTUREDPSYCHE_API UPT_FPAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityActorInfoSet();
	FEffectAssetTags EffectAssetTags;

protected:
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
		const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
	
};
