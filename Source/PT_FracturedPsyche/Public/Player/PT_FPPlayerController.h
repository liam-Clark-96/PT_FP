// Copyright Liam Clark

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PT_FPPlayerController.generated.h"

/**
 * 
 */

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class PT_FRACTUREDPSYCHE_API APT_FPPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APT_FPPlayerController();
	virtual void PlayerTick(float DeltaTime) override;
	

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	//Input Mapping Context for the player controller
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> PlayerContext;

	//Input Action for moving the player
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	//Function to handle the movement input
	void Move(const FInputActionValue& InputActionValue);
	
};
