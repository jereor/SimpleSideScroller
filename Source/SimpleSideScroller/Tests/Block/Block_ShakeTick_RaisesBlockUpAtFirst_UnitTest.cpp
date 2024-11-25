#include "SimpleSideScroller/Code/Block/UBlockComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBlock_ShakeTick_RaisesBlockUpAtFirst_UnitTest, "Block.ShakeTick.RaisesBlockUpAtFirst", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

constexpr float DeltaSeconds = 0.016f;

inline bool FBlock_ShakeTick_RaisesBlockUpAtFirst_UnitTest::RunTest(const FString& Parameters)
{
	UBlockComponent* Block = UBlockComponent::Create(0.5f);
	const double StartZ = Block->GetRelationalPosition().Z;
	
	Block->Shake();
	Block->ShakeTick(DeltaSeconds);

	TestTrue("block is higher than starting location", Block->GetRelationalPosition().Z > StartZ);
	return true;
}