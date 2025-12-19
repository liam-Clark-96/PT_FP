// Copyright Liam Clark


#include "Character/PT_FPCharacter.h"
#include "Player/PT_FPPlayerState.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

APT_FPCharacter::APT_FPCharacter()
{
	//Set up Spring Arm Component
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->TargetArmLength = SpringArmLength;
	SpringArmComponent->bUsePawnControlRotation = false;
	SpringArmComponent->SetUsingAbsoluteRotation(true);
	SpringArmComponent->bDoCollisionTest = false;
	SpringArmComponent->SetRelativeRotation(FRotator(CameraPitch, 0.f, 0.0f));

	//Set up Camera Component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;

	//Setup the Lantern Mesh Component
	LanternMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LanternMeshComponent"));
	LanternMeshComponent->SetupAttachment(GetMesh(), LanternSocketName);
	LanternMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//Setup the Lantern Light Component
	LanternLightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("LanternLightComponent"));
	LanternLightComponent->SetupAttachment(LanternMeshComponent);
	LanternLightComponent->SetIntensity(2500.f); // test and change within BP
	
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f); // Rotation rate
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


}

void APT_FPCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Initialize Ability Actor Info for server
	InitAbilityActorInfo();
}

void APT_FPCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// Initialize Ability Actor Info for clients
	InitAbilityActorInfo();
}

void APT_FPCharacter::InitAbilityActorInfo()
{
	//APT_FPPlayerState* PlayerState = GetPlayerState<APT_FPPlayerState>();
	//check(PlayerState);
	//PlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(PlayerState, this);
}
