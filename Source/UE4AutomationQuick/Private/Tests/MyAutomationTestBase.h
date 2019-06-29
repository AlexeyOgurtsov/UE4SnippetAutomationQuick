#pragma once

#include "Misc/AutomationTest.h"

class FMyAutomationTestBase : public FAutomationTestBase
{
public:
	FMyAutomationTestBase(const FString& InName, const bool bComplexTask) :
		FAutomationTestBase{InName, bComplexTask} 
	{
	}

protected:
	void MyMessage(const FString& InMessage)
	{
		AddInfo(FString("MyMessage: ") + InMessage);
	}
};