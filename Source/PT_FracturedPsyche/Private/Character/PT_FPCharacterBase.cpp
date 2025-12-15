// Copyright Liam Clark


#include "Character/PT_FPCharacterBase.h"

#include "Player/PT_FPPlayerState.h"
#include "AbilitySystemComponent.h"

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

void APT_FPCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController); //Call parent PossessedBy
	
	InitAbilityActorInfo(); //Server-side init of Ability Actor Info
}

void APT_FPCharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState(); //Call parent OnRep_PlayerState

	InitAbilityActorInfo(); //Client-side init of Ability Actor Info
}

void APT_FPCharacterBase::InitAbilityActorInfo()
{
	APT_FPPlayerState* PS = GetPlayerState<APT_FPPlayerState>(); //Get Player State
	if (!PS) return;
	
	AbilitySystemComponent = PS->GetAbilitySystemComponent();
	if (!AbilitySystemComponent) return;

	AbilitySystemComponent->InitAbilityActorInfo(PS, this); //Initialize Ability Actor Info
		
		
}

void APT_FPCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}


