#pragma once

#include "CoreMinimal.h"
#include "UBlockComponent.generated.h"

enum class EBlockState
{
	Default,
	Shake
};

UCLASS()
class SIMPLESIDESCROLLER_API UBlockComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	static UBlockComponent* Create(const float TimeToRise = 0.5f, const float TimeToReturn = 0.5f, const float ShakeSpeed = 2000.0f, const FVector StartLocation = FVector::Zero())
	{
		UBlockComponent* BlockComponent = NewObject<UBlockComponent>();
		BlockComponent->StartLocation = StartLocation;
		BlockComponent->RelationalPosition = FVector::ZeroVector;
		BlockComponent->TimeToRise = TimeToRise;
		BlockComponent->TimeToReturn = TimeToReturn;
		BlockComponent->ShakeSpeed = ShakeSpeed;
		
		return BlockComponent;
	}
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	void Shake() { CurrentState = EBlockState::Shake; }
	void ShakeTick(float DeltaSeconds);
	EBlockState GetCurrentState() const { return CurrentState; }
	FVector GetStartLocation() const { return StartLocation; }
	UFUNCTION(BlueprintCallable)
	void SetStartLocation(const FVector NewStartLocation) { StartLocation = NewStartLocation; }
	FVector GetRelationalPosition() const { return RelationalPosition; }
	void UpdateTick(float DeltaTime);

	UPROPERTY(EditAnywhere)
	float TimeToRise;

	UPROPERTY(EditAnywhere)
	float TimeToReturn;

protected:
	virtual void BeginPlay() override;
	
private:
	UBlockComponent();
	EBlockState CurrentState;
	FVector StartLocation;
	FVector RelationalPosition;
	float ShakeTime;
	float ShakeSpeed;
	
};
