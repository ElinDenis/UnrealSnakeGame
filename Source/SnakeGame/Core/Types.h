// SnakeGame. Copyright Elin Denis. All Rights Reserved.
// Developed with Unreal Engine 5.3
#pragma once

#include "CoreMinimal.h"

namespace SnakeGame
{
struct Dim
{
    uint32 width;
    uint32 height;
};

enum class CellType
{
    Empty = 0,
    Wall
    // Food
    // Snake
};

struct Settings
{
    Dim gridDims;
};

}  // namespace SnakeGame