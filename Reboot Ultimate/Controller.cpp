#include "Controller.h"

#include "reboot.h"

AActor* AController::GetViewTarget()
{
	static auto GetViewTargetFn = FindObject<UFunction>("/Script/Engine.Controller.GetViewTarget");
	AActor* ViewTarget = nullptr;
	this->ProcessEvent(GetViewTargetFn, &ViewTarget);
	return ViewTarget;
}

void AController::Possess(class APawn* Pawn)
{
	auto PossessFn = FindFunction("Possess");
	this->ProcessEvent(PossessFn, &Pawn);
}

bool AController::LineOfSightTo(AActor* Other, const FVector& ViewPoint, bool bAlternateChecks)
{
	static auto LineOfSightToFn = FindObject<UFunction>("/Script/Engine.Controller.LineOfSightTo");

	struct
	{
		AActor* Other;
		FVector ViewPoint;
		bool bAlternateChecks;
		bool ReturnValue;
	}AController_LineOfSightTo_Params{ Other , ViewPoint , bAlternateChecks };

	this->ProcessEvent(LineOfSightToFn, &AController_LineOfSightTo_Params);

	return AController_LineOfSightTo_Params.ReturnValue;
}

void AController::StopMovement()
{
	static auto StopMovementFn = FindObject<UFunction>("/Script/Engine.Controller.StopMovement");
	this->ProcessEvent(StopMovementFn);
}

void AController::SetControlRotation(FRotator NewRotation)
{
	static auto SetControlRotationFn = FindObject<UFunction>("/Script/Engine.Controller.SetControlRotation");
	this->ProcessEvent(SetControlRotationFn, &NewRotation);
}