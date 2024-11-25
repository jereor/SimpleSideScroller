#include "UBlockComponent.h"

#include "Kismet/KismetMathLibrary.h"

UBlockComponent::UBlockComponent()
{
}

void UBlockComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UBlockComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	UpdateTick(DeltaTime);
}

void UBlockComponent::UpdateTick(const float DeltaTime)
{
	switch (CurrentState)
	{
	case EBlockState::Default:
		break;
	case EBlockState::Shake:
		ShakeTick(DeltaTime);
		break;
	default:
		break;
	}
}

void UBlockComponent::ShakeTick(const float DeltaSeconds)
{
	ShakeTime += DeltaSeconds;
	if (ShakeTime <= TimeToRise)
	{
		RelationalPosition += UKismetMathLibrary::Vector_Up() * DeltaSeconds * ShakeSpeed / TimeToRise;
	}
	else
	{
		RelationalPosition -= UKismetMathLibrary::Vector_Up() * DeltaSeconds * ShakeSpeed / TimeToReturn;
		RelationalPosition.Z = FMath::Clamp(RelationalPosition.Z, StartLocation.Z, INFINITY);
	}

	GetOwner()->SetActorLocation(StartLocation + RelationalPosition);

	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Relational Position: %s"), *RelationalPosition.ToString()));	
}
