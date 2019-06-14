#include "Misc/AutomationTest.h"
#include "MyTestableClass.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST( FMyTestableClassTestFirst, "MyTests.TestableClassTest.First", EAutomationTestFlags::CommandletContext | EAutomationTestFlags::SmokeFilter )

bool FMyTestableClassTestFirst::RunTest(const FString& Parameters)
{
	auto Obj = UMyTestableClass::NewInitializedObject(nullptr);
	TestNotNull(TEXT("NewInitializedObject must return valid pointer"), Obj);
	
	return true;
}