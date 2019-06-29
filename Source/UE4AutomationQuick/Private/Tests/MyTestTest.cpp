#include "MyAutomationTestBase.h"
#include "ComplexTest.h"

#include "TestUnitTestCommand.h"

#include "Misc/AutomationTest.h"
//#include "Util/Core/LogUtilLib.h"

IMPLEMENT_CUSTOM_COMPLEX_AUTOMATION_TEST(FTestTest_CustomComplex, FComplexTest, "MyTests.TestTest.Complex", EAutomationTestFlags::EditorContext | EAutomationTestFlags::SmokeFilter);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestTest_Error, "MyTests.TestTest.Error", EAutomationTestFlags::EditorContext | EAutomationTestFlags::SmokeFilter)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestTest_Warnings, "MyTests.TestTest.Warnings", EAutomationTestFlags::EditorContext | EAutomationTestFlags::SmokeFilter)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestTest_Info, "MyTests.TestTest.Info", EAutomationTestFlags::EditorContext | EAutomationTestFlags::SmokeFilter)

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FTestTest_CustomSimple, FMyAutomationTestBase, "MyTests.TestTest.CustomSimple", EAutomationTestFlags::EditorContext | EAutomationTestFlags::SmokeFilter)

// Seems like Latents commands cannot be used with SmokeFilter! (check assertion)
IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FTestTest_LatentCommand, FMyAutomationTestBase, "MyTests.TestTest.LatentCommand", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FTestTest_LatentCommandEngine, FMyAutomationTestBase, "MyTests.TestTest.LatentCommandEngine", EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

void FTestTest_CustomComplex::GetTests(TArray<FString>& OutBeautifiedNames, TArray<FString>& OutTestCommands) const
{	
	UE_LOG(LogTemp, Log, TEXT("FTestTest_CustomComplex::GetTests..."));
	{
		OutBeautifiedNames.Add(FString(TEXT("ComplexTest_BeautyName_1")));
		OutTestCommands.Add(FString(TEXT("ComplexTest_TestCommand_1")));
	}

	{
		OutBeautifiedNames.Add(FString(TEXT("ComplexTest_BeautiName_2")));
		OutTestCommands.Add(FString(TEXT("ComplexTest_TestCommand_2")));
	}
	UE_LOG(LogTemp, Log, TEXT("FTestTest_CustomComplex::GetTests DONE"));
}
bool FTestTest_CustomComplex::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("CustomComplex::RunTest, Parameters=\"%s\""), *Parameters);
	return true;
}

bool FTestTest_Error::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FTestTest_Error::RunTest..."));
	AddError(TEXT("My test error"));
	AddError(TEXT("My test error 2"));
	UE_LOG(LogTemp, Log, TEXT("FTestTest_Error::RunTest DONE"));
	return true;
}

bool FTestTest_Warnings::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FTestTest_Warnings::RunTest..."));
	AddWarning(TEXT("My warning 1"));
	AddWarning(TEXT("My warning 2"));
	UE_LOG(LogTemp, Log, TEXT("FTestTest_Warnings::RunTest DONE"));
	return true;
}

bool FTestTest_Info::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FTestTest_Info::RunTest..."));
	AddInfo(TEXT("Info 1"));
	AddInfo(TEXT("Info 2"));

	// use AddInfo instead:
	//AddLogItem(TEXT("Log item 1"));
	//AddLogItem(TEXT("Log item 2"));

	UE_LOG(LogTemp, Log, TEXT("FTestTest_Info::RunTest DONE"));
	return true;
}

bool FTestTest_CustomSimple::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FTestTest_CustomSimple::RunTest..."));
	MyMessage(TEXT("MyMessage"));
	UE_LOG(LogTemp, Log, TEXT("FTestTest_CustomSimple::RunTest DONE"));
	return true;
}

bool FTestTest_LatentCommand::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FTestTest_LatentCommand::RunTest..."));
	// Seems like latent command can NOT be used with SmokeFilter! (check assertion)
	ADD_LATENT_AUTOMATION_COMMAND(FTestUnitTestCommand(/*MaxIters*/3));
	UE_LOG(LogTemp, Log, TEXT("FTestTest_LatentCommand::RunTest DONE"));
	return true;
}

bool FTestTest_LatentCommandEngine::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FTestTest_LatentCommandEngine::RunTest..."));
	// Seems like latent command can NOT be used with SmokeFilter! (check assertion)
	ADD_LATENT_AUTOMATION_COMMAND(FTestUnitTestCommand(/*MaxIters*/3));
	UE_LOG(LogTemp, Log, TEXT("FTestTest_LatentCommandEngine::RunTest DONE"));
	return true;
}