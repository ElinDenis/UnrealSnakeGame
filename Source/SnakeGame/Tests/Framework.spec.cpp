// SnakeGame. Copyright Elin Denis. All Rights Reserved.
// Developed with Unreal Engine 5.3
#if WITH_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Misc/PathViews.h"

// Project class include
#include "Tests/Utils/TestUtils.h"
#include "Framework/SG_GameMode.h"
#include "Framework/SG_Pawn.h"

BEGIN_DEFINE_SPEC(
    FSnakeFramework, "Snake", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority)

UWorld* World;

END_DEFINE_SPEC(FSnakeFramework)

void FSnakeFramework::Define()
{
    using namespace Snake::Test;

    Describe("Framework",
        [this]()
        {
            It("GameMapMightExist",
                [this]()
                {
                    const TArray<FString> SnakeGameMaps = {"GameLevel"};

                    TArray<FString> AllProjectMaps;
                    IFileManager::Get().FindFilesRecursive(AllProjectMaps, *FPaths::ProjectConfigDir(), TEXT("*.umap"), true, false);

                    for (const auto& SnakeGameMap : AllProjectMaps)
                    {
                        const bool SnakeMapExists = AllProjectMaps.ContainsByPredicate(
                            [&](const FString& ProjectMap)
                            {
                                FStringView OutPath, OutName, OutExt;
                                FPathViews::Split(FStringView(ProjectMap), OutPath, OutName, OutExt);
                                return SnakeGameMap.Equals(FString(OutName));
                            });
                        TestTrueExpr(SnakeMapExists);
                    }
                });
        });

    Describe("Framework",
        [this]()
        {
            BeforeEach(
                [this]()
                {
                    AutomationOpenMap("GameLevel");
                    World = GetTestGameWorld();
                });

            It("ClassesMightBeSetupCorrectly",
                [this]()
                {
                    TestNotNull("Snake game mode set up", Cast<ASG_GameMode>(World->GetAuthGameMode()));
                    TestNotNull("Snake pawn set up", Cast<ASG_Pawn>(World->GetFirstPlayerController()->GetPawn()));
                });
            xIt("PawnLocationShouldBeAdjustCorrectly", [this]() { unimplemented(); });
        });
}

#endif