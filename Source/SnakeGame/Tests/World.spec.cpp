// SnakeGame. Copyright Elin Denis. All Rights Reserved.
// Developed with Unreal Engine 5.3
#if WITH_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"

// Engine class include
#include "Kismet/GameplayStatics.h"

// Project class include
#include "Tests/Utils/TestUtils.h"
#include "World/SG_Grid.h"

BEGIN_DEFINE_SPEC(
    FSnakeWorld, "Category", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority)

UWorld* World;

END_DEFINE_SPEC(FSnakeWorld)

void FSnakeWorld::Define()
{
    using namespace Snake::Test;

    Describe("WorldGrid",
        [this]()
        {
            BeforeEach(
                [this]()
                {
                    AutomationOpenMap("GameLevel");
                    World = GetTestGameWorld();
                });

            It("OnlyOneValidGridActorShouldExists",
                [this]()
                {
                    TArray<AActor*> Grids;
                    UGameplayStatics::GetAllActorsOfClass(World, ASG_Grid::StaticClass(), Grids);
                    TestTrueExpr(Grids.Num() == 1);
                    TestNotNull("Grid actro exists", Grids[0]);
                });
        });
}

#endif