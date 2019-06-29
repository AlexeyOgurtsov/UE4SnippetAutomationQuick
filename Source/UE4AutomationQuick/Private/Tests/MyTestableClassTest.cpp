#include "Misc/AutomationTest.h"
#include "TestUnitTestCommand.h"
#include "MyTestableClass.h"

#include "UObject/Package.h"
#include "Logging/LogMacros.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST( FMyTestableClassTestFirst, "MyTests.Testable.First", EAutomationTestFlags::EditorContext | EAutomationTestFlags::SmokeFilter )
IMPLEMENT_SIMPLE_AUTOMATION_TEST( FMyTestableClass_ConstructorInitFail, "MyTests.Testable.ConstructorInitFail", EAutomationTestFlags::EditorContext | EAutomationTestFlags::SmokeFilter )

IMPLEMENT_SIMPLE_AUTOMATION_TEST( FMyTestableClass_AlwaysFail, "MyTests.Trivial.AlwaysFail", EAutomationTestFlags::EditorContext | EAutomationTestFlags::SmokeFilter )

//namespace
//{
//	FMyTestableClassTestFirst MyTestableClassTestFirstInstance(TEXT("FMyTestableClassTestFirst"));
//}

bool FMyTestableClassTestFirst::RunTest(const FString& Parameters)
{
	//auto Obj = UMyTestableClass::NewInitializedObject(nullptr);
	//TestNotNull(TEXT("NewInitializedObject must return valid pointer"), Obj);
	
	return true;
}

bool FMyTestableClass_ConstructorInitFail::RunTest(const FString& Parameters)
{
	auto Obj = UMyTestableClass::NewInitializedObject(GetTransientPackage());
	TestNotNull(TEXT("NewInitializedObject must return valid pointer"), Obj);
	TestEqual(TEXT("Checking GetMyWeight()"), Obj->GetMyWeight(), 3.0F);
	
	return true;
}


bool FMyTestableClass_AlwaysFail::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FMyTestableClass_AlwaysFail::RunTest: Testing logging from SmokeTest"));
	return false;
}