// SnakeGame. Copyright Elin Denis. All Rights Reserved.
// Developed with Unreal Engine 5.3
#include "Framework/SG_GameMode.h"

// Project class include
#include "Core/Types.h"
#include "Core/Grid.h"
#include "World/SG_Grid.h"
#include "Framework/SG_Pawn.h"

void ASG_GameMode::StartPlay()
{
    Super::StartPlay();

    // Init core game
    const Snake::Settings GS{GridDims.X, GridDims.Y};
    Game = MakeUnique<Snake::Game>(GS);
    check(Game.IsValid());

    // Init world grid
    const FTransform GridOrigin = FTransform::Identity;
    check(GetWorld());
    GridVisual = GetWorld()->SpawnActorDeferred<ASG_Grid>(GridVisualClass, GridOrigin);
    check(GridVisual);
    GridVisual->SetModel(Game->grid(), CellSize);
    GridVisual->FinishSpawning(GridOrigin);

    // Set pawn location fitting frid in viewport
    auto* PC = GetWorld()->GetFirstPlayerController();
    check(PC);

    auto* Pawn = Cast<ASG_Pawn>(PC->GetPawn());
    check(Pawn);
    check(Game->grid().IsValid());
    Pawn->UpdateLocation(Game->grid()->dim(), CellSize, GridOrigin);
}