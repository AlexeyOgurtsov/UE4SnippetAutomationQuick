#pragma once

#include "MyTestableClass.generated.h"


UCLASS()
class UMyTestableClass : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Creation)
	static UMyTestableClass* NewInitializedObject(UObject* InOuter);

	UFUNCTION(BlueprintPure, Category = Props)
	float GetMyWeight() const { return MyWeight; }

private:
	UPROPERTY()
	float MyWeight = 0.0F;
};