// Copyright Liam Clark

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PT_FPAttributeSet.generated.h"

// Macro to define attribute accessors for an attribute in an AttributeSet
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties // Struct to hold commonly used effect properties for easy access
{
	GENERATED_BODY()

	FEffectProperties() {}
	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

UCLASS()
class PT_FRACTUREDPSYCHE_API UPT_FPAttributeSet : public UAttributeSet
{
	GENERATED_BODY()


public:
	UPT_FPAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; // For replication
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override; // For adjusting attributes before they change

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override; // For handling logic after gameplay effects are executed

	//Attributes Will go here	-------------

	//lantern integrity (which will be Health in the game)
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_LanternIntegrity, Category = "Attributes|LanternIntegrity")
	FGameplayAttributeData LanternIntegrity; // Current LanternIntegrity value
	ATTRIBUTE_ACCESSORS(UPT_FPAttributeSet, LanternIntegrity); // Macro to create accessors for LanternIntegrity attribute

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxLanternIntegrity, Category = "Attributes|LanternIntegrity")
	FGameplayAttributeData MaxLanternIntegrity; // Current max LanternIntegrity value
	ATTRIBUTE_ACCESSORS(UPT_FPAttributeSet, MaxLanternIntegrity); // Macro to create accessors for MaxLanternIntegrity attribute

	//Breath Attribute (Which will be Stamina in the game)
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Breath, Category = "Attributes|Breath")
	FGameplayAttributeData Breath; // Current breath value
	ATTRIBUTE_ACCESSORS(UPT_FPAttributeSet, Breath); // Macro to create accessors for Breath attribute

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxBreath, Category = "Attributes|Breath")
	FGameplayAttributeData MaxBreath; // Current max breath value
	ATTRIBUTE_ACCESSORS(UPT_FPAttributeSet, MaxBreath); // Macro to create accessors for MaxBreath attribute

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BreathRechargeRate, Category = "Attribute|Breath")
	FGameplayAttributeData BreathRechargeRate; // Current breath recharge rate value
	ATTRIBUTE_ACCESSORS(UPT_FPAttributeSet, BreathRechargeRate); // Macro to create accessors for BreathRechargeRate attribute

	//Insight Attribute (Which will be Mana in the Game)
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Insight, Category = "Attribute|Insight")
	FGameplayAttributeData Insight; // Current insight value
	ATTRIBUTE_ACCESSORS(UPT_FPAttributeSet, Insight); // Macro to create accessors for Insight attribute

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxInsight, Category = "Attribute|Insight")
	FGameplayAttributeData MaxInsight; // Current max insight value
	ATTRIBUTE_ACCESSORS(UPT_FPAttributeSet, MaxInsight); // Macro to create accessors for MaxInsight attribute

	//MoveSpeed Attribute for character movement speed modifications
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MoveSpeed, Category = "Attribute|MoveSpeed")
	FGameplayAttributeData MoveSpeed; // Current MoveSpeed value
	ATTRIBUTE_ACCESSORS(UPT_FPAttributeSet, MoveSpeed); // Macro to create accessors for MoveSpeed attribute
	//--------------------------------------


protected:
	//RepNotify functions for the Attributes
	UFUNCTION()
	void OnRep_LanternIntegrity(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_MaxLanternIntegrity(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_Breath(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_MaxBreath(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_BreathRechargeRate(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_Insight(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_MaxInsight(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_MoveSpeed(const FGameplayAttributeData& OldValue);


private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;

};
