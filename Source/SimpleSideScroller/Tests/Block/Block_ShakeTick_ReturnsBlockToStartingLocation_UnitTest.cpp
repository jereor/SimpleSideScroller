#include "SimpleSideScroller/Code/Block/UBlockComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBlock_ShakeTick_ReturnsBlockToStartingLocation_UnitTest, "Block.ShakeTick.ReturnsBlockToStartingLocation", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

constexpr float DeltaSeconds = 0.016f;

inline bool FBlock_ShakeTick_ReturnsBlockToStartingLocation_UnitTest::RunTest(const FString& Parameters)
{
	UBlockComponent* Block = UBlockComponent::Create(0.5f, 0.5f);
	const double StartZ = Block->GetRelationalPosition().Z;
	Block->Shake();

	float Timer = 0.0f;
	while (true)
	{
		if (Timer >= 1.0f) break;
		
		Block->ShakeTick(DeltaSeconds);
		Timer += DeltaSeconds;
	}
	
	TestTrue("block returned to starting location", Block->GetRelationalPosition().Z == StartZ);
	return true;
}
