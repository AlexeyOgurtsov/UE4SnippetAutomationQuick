#pragma once

#include "Misc/AutomationTest.h"

class FComplexTest : public FAutomationTestBase
{
public:
	FComplexTest(const FString& InName, const bool bComplexTask)
	: FAutomationTestBase(InName, bComplexTask) 
	{ }

private:	
};