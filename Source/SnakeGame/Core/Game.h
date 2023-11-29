// SnakeGame. Copyright Elin Denis. All Rights Reserved.
// Developed with Unreal Engine 5.3
#pragma once

#include "CoreMinimal.h"
#include "Core/Types.h"

namespace Snake
{

class Grid;

class Game
{
public:
    Game(const Settings& settings);

    /**
    * Returns the pointer to the grid object
    * @return TSharedPtr<Grid>  pointer to the grid object
    */
    TSharedPtr<Grid> grid() const { return m_grid; };

private:
    const Settings c_settings;
    TSharedPtr<Grid> m_grid;
};

}  // namespace Snake