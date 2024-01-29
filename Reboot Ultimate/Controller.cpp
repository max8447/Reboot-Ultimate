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

void AController::StopMovement()
{
	static auto fn = FindObject<UFunction>("/Script/Engine.Controller.StopMovement");
	this->ProcessEvent(fn);
}

bool AController::LineOfSightTo(AActor* Other, FVector ViewPoint, bool bAlternateChecks)
{
	static auto fn = FindObject<UFunction>("/Script/Engine.Controller.LineOfSightTo");

	struct
	{
		AActor* Other;
		FVector ViewPoint;
		bool bAlternateChecks;
		bool ReturnValue;
	}params{ Other , ViewPoint , bAlternateChecks };

	this->ProcessEvent(fn, &params);

	return params.ReturnValue;
}

void AController::SetControlRotation(FRotator NewRotation)
{
	static auto fn = FindObject<UFunction>("/Script/Engine.Controller.SetControlRotation");
	this->ProcessEvent(fn, &NewRotation);
}