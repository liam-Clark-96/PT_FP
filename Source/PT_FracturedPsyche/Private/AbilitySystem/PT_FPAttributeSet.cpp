// Copyright Liam Clark


#include "AbilitySystem/PT_FPAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"
#include <AbilitySystemBlueprintLibrary.h>

UPT_FPAttributeSet::UPT_FPAttributeSet()
{
	//-----Health---------
	InitLanternIntegrity(100.f);
	InitMaxLanternIntegrity(100.f);
	//--------------------
	//-----Stamina--------
	InitBreath(100.f);
	InitMaxBreath(100.f);
	InitBreathRechargeRate(1.f);
	//--------------------
	//------Mana----------
	InitInsight(100.f);
	InitMaxInsight(100.f);
	//--------------------
	//----MoveSpeed-------
	InitMoveSpeed(600.f);
	//--------------------
}

void UPT_FPAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	// Call the base class function to ensure proper replication setup for inherited properties
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UPT_FPAttributeSet, LanternIntegrity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPT_FPAttributeSet, MaxLanternIntegrity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPT_FPAttributeSet, Breath, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPT_FPAttributeSet, MaxBreath, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPT_FPAttributeSet, BreathRechargeRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPT_FPAttributeSet, Insight, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPT_FPAttributeSet, MaxInsight, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPT_FPAttributeSet, MoveSpeed, COND_None, REPNOTIFY_Always);
}

void UPT_FPAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
}

void UPT_FPAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
}

void UPT_FPAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
}

void UPT_FPAttributeSet::OnRep_LanternIntegrity(const FGameplayAttributeData& OldValue)
{
}

void UPT_FPAttributeSet::OnRep_MaxLanternIntegrity(const FGameplayAttributeData& OldValue)
{
}

void UPT_FPAttributeSet::OnRep_Breath(const FGameplayAttributeData& OldValue)
{
}

void UPT_FPAttributeSet::OnRep_MaxBreath(const FGameplayAttributeData& OldValue)
{
}

void UPT_FPAttributeSet::OnRep_BreathRechargeRate(const FGameplayAttributeData& OldValue)
{
}

void UPT_FPAttributeSet::OnRep_Insight(const FGameplayAttributeData& OldValue)
{
}

void UPT_FPAttributeSet::OnRep_MaxInsight(const FGameplayAttributeData& OldValue)
{
}

void UPT_FPAttributeSet::OnRep_MoveSpeed(const FGameplayAttributeData& OldValue)
{
}
