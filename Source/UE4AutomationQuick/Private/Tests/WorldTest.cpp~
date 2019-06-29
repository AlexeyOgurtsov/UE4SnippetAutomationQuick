#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Tests/AutomationEditorCommon.h" // Editor/UnrealEd/Public/Tests

#include "Util/Core/LogUtilLib.h"

#include "Engine/Engine.h"
#include "Engine/World.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyWorld_SmokeEditorTest, "MyTests.World.SmokeEditorTest", EAutomationTestFlags::Disabled | EAutomationTestFlags::EditorContext | EAutomationTestFlags::SmokeFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyWorld_SmokeClientTest, "MyTests.World.SmokeClientTest", EAutomationTestFlags::Disabled | EAutomationTestFlags::ClientContext | EAutomationTestFlags::SmokeFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyWorld_SmokeCommandletTest, "MyTests.World.SmokeCommandletTest", EAutomationTestFlags::Disabled |EAutomationTestFlags::CommandletContext | EAutomationTestFlags::SmokeFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyWorld_SmokeServerTest, "MyTests.World.SmokeServerTest", EAutomationTestFlags::Disabled |EAutomationTestFlags::ServerContext | EAutomationTestFlags::SmokeFilter);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyWorld_EngineEditorTest, "MyTests.World.EngineEditorTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyWorld_EngineClientTest, "MyTests.World.EngineClientTest", EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyWorld_EngineCommandletTest, "MyTests.World.EngineCommandletTest", EAutomationTestFlags::CommandletContext | EAutomationTestFlags::EngineFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyWorld_EngineServerTest, "MyTests.World.EngineServerTest", EAutomationTestFlags::ServerContext | EAutomationTestFlags::EngineFilter);

namespace
{
	class FWorldTestUtils
	{
	public:
		static void TestWorld()
		{
			M_LOGFUNC();

			{
				UWorld* const W = TestCreateWorld();
				if(W)
				{
					TestAddActors(W);
				
				TestDestroyWorld(W);
				}
			}
		}

	private:
		static void TestAddActors(UWorld* W)
		{
			M_LOGFUNC();
		}

		static void TestDestroyWorld(UWorld* W)
		{
			M_LOGFUNC();
			W->DestroyWorld(/*bInformEngineOrWorld*/false, /*NewWorld*/nullptr);	
		}

		static UWorld* TestCreateWorld()
		{
			M_LOGFUNC();

			// UWorld::CreateWorld
			// (
			// EWorldType::Type (Game, Editor, PIE, Inactive etc.),
			// bInformEngineOrWorld, // Calls GEngine->WorldAdded(NewWorld)
			// FName WorldName = NAME_None,
			// UPackage* InWorldPackage = nullptr (CreatePackage(nullptr, nullptr) in that case),
			// bAddToRoot = true // WARNING: AddToRoot by default
			// InFeatureLevel : ERHIFeatureLevel::Type:SM5, SM4, ES2 etc. = Num
			// )

			// Creation fails when SmokeFilter (works fine in EngineFilter | EditorContext)
			UWorld* const W = UWorld::CreateWorld(EWorldType::Game, false);
			M_LOG(TEXT("UWorld::CreateWorld returned: %s"), *ULogUtilLib::GetNameAndClassSafe(W));

				// Can we create world second time from the same world type?
				/// YES - tried, works in EditorContext | EngineFilter
				//UWorld* const WTwo = UWorld::CreateWorld(EWorldType::Game, false);
				//M_LOG(TEXT("UWorld::CreateWorld returned %s"), *ULogUtilLib::GetNameAndClassSafe(WTwo));
		
				//if(WTwo)
				//{
				//	WTwo->DestroyWorld(/*bInformEngineOrWorld*/false, /*NewWorld*/nullptr);
				//}
			
			if(W)
			{
				FWorldContext *WorldContext = nullptr;
				
				{
					M_LOGBLOCK(TEXT("CreateNewWorldContext"));
					WorldContext = &GEngine->CreateNewWorldContext(EWorldType::Game);
					WorldContext->SetCurrentWorld(W);
				}
			}
			return W;
		}

		static void TestEngineWorld()
		{
			// GEngine->GetWorld() always fails in SmokeFilter
			M_LOGFUNC();
			if(GEngine)
			{
				UE_LOG(LogTemp, Log, TEXT("GEngine valid"));
				UWorld* const W = GEngine->GetWorld();
				if(W)
				{
					UE_LOG(LogTemp, Log, TEXT("GEngine->GetWorld() returned VALID"));
				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT("GEngine->GetWorld() returned INVALID"));
				}
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("GEngine is nullptr"));
			}
		}
	};
} // anonymous

// ~ Smoke tests Begin
bool FMyWorld_SmokeEditorTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FMyWorld_SmokeEditorTest::RunTest"));

	// CreateWorld fails when SmokeFilter
	FWorldTestUtils::TestWorld();

	return true;
}

bool FMyWorld_SmokeClientTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FMyWorld_SmokeClientTest::RunTest"));

	FWorldTestUtils::TestWorld();

	return true;
}

bool FMyWorld_SmokeServerTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FMyWorld_SmokeServerTest::RunTest"));

	FWorldTestUtils::TestWorld();

	return true;
}

bool FMyWorld_SmokeCommandletTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FMyWorld_SmokeCommandletTest::RunTest"));

	FWorldTestUtils::TestWorld();

	return true;
}
// ~ Smoke tests End

// ~ Engine tests Begin
bool FMyWorld_EngineEditorTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FMyWorld_EngineEditorTest::RunTest"));

	FWorldTestUtils::TestWorld();

	return true;
}

bool FMyWorld_EngineClientTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FMyWorld_EngineClientTest::RunTest"));

	FWorldTestUtils::TestWorld();

	return true;
}

bool FMyWorld_EngineServerTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FMyWorld_EngineServerTest::RunTest"));

	FWorldTestUtils::TestWorld();

	return true;
}

bool FMyWorld_EngineCommandletTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FMyWorld_EngineCommandletTest::RunTest"));

	FWorldTestUtils::TestWorld();

	return true;
}
// ~ Engine tests End



