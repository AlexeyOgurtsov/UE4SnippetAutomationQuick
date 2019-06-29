#pragma once

#include "Misc/AutomationTest.h"

//DEFINE_LATENT_AUTOMATION_COMMAND(FTestUnitTestCommand);

class FTestUnitTestCommand : public IAutomationLatentCommand
{
public:
	FTestUnitTestCommand(int32 InNumIters);
	
	virtual bool Update() override;

private:
	int32 IterIndex = 0;
	int32 NumIters;
};