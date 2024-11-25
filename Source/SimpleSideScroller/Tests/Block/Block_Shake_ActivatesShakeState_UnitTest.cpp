#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"

#include "SimpleSideScroller/Code/Block/UBlockComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBlock_Shake_ActivatesShakeState_UnitTest, "Block.Shake.ActivatesShakeState", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FBlock_Shake_ActivatesShakeState_UnitTest::RunTest(const FString& Parameters)
{
	UBlockComponent* Block = UBlockComponent::Create();
	
	Block->Shake();

	TestTrue("block is in shake state", Block->GetCurrentState() == EBlockState::Shake);
	return true;
}




