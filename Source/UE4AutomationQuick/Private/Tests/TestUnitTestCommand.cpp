#include "TestUnitTestCommand.h"
#include "Logging/LogMacros.h"

//#include "Engine/Engine.h" // GUnitTestManager NO in Engine/Engine.h!!!

FTestUnitTestCommand::FTestUnitTestCommand(int32 InNumIters)
:	NumIters{InNumIters}
{
}

bool FTestUnitTestCommand::Update()
{
	// (GUnitTestManager == nullptr) || (GUnitTestManager->IsRunningUnitTests());
	bool const bContinue = IterIndex < NumIters;

	UE_LOG(LogTemp, Log, TEXT("IterIndex=%d of %d"), IterIndex, NumIters);

	if(bContinue)
	{
		UE_LOG(LogTemp, Log, TEXT("Unit test command: Continue"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Unit test command: NOT Continue"));
	}

	IterIndex++;

	return ! bContinue;
}