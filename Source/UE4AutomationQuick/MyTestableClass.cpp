#include "MyTestableClass.h"

UMyTestableClass* UMyTestableClass::NewInitializedObject(UObject* InOuter)
{
	UMyTestableClass* Obj = NewObject<UMyTestableClass>(InOuter, UMyTestableClass::StaticClass());
	Obj->MyWeight = 0.0F;
	return Obj;
}