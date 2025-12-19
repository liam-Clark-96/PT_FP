// Copyright Liam Clark


#include "Player/PT_FPPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

void APT_FPPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void APT_FPPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//Check if the local player mapping context is valud
	check(PlayerContext);

	//Get the enhanced input local player subsystem and add the mapping context checking it firstthen adding the context
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
	{
		Subsystem->AddMappingContext(PlayerContext, 0);
	}

	//Show the mouse cursor and set the default cursor type
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	//Set the input mode to game and UI so that both game and UI inputs are processed
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);

}

void APT_FPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Set up the enchanced input component cast checking it first
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	//binding the move action to the move function
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APT_FPPlayerController::Move);
}


APT_FPPlayerController::APT_FPPlayerController()
{
	//enable the replication for the player controller to support multiplayer functionality
	bReplicates = true;
}

void APT_FPPlayerController::Move(const FInputActionValue& InputActionValue)
{
	//Getting the input axis vector from the input action value
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	//Getting the control rotation of the player controller
	const FRotator Rotation = GetControlRotation();
	//Isolating the yaw rotation to ignore pitch and roll for movement direction
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	//Getting the forward and right direction vectors based on the yaw rotation
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	//Adding Movement input to the controlled pawn based on the input axis and directional vectors
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
