// SnakeGame. Copyright Elin Denis. All Rights Reserved.
// Developed with Unreal Engine 5.3
#include "Core/Game.h"

// Project class include
#include "Core/Grid.h"

DEFINE_LOG_CATEGORY_STATIC(LogGame, All, All);

using namespace SnakeGame;

Game::Game(const Settings& settings) : c_settings(settings)
{
    m_grid = MakeShared<Grid>(settings.gridDims);
}