// Copyright Liam Clark


#include "Character/PT_FPCharacterBase.h"

// Sets default values
APT_FPCharacterBase::APT_FPCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

UAbilitySystemComponent* APT_FPCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void APT_FPCharacterBase::InitAbilityActorInfo()
{

}

void APT_FPCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}


