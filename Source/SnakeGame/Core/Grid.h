// SnakeGame. Copyright Elin Denis. All Rights Reserved.
// Developed with Unreal Engine 5.3
#pragma once

#include "CoreMinimal.h"
#include "Core/Types.h"

namespace Snake
{

class Grid
{
public:
    Grid(const Dim& dim);

    Dim dim() const { return c_dim; };

private:
    const Dim c_dim;
    TArray<CellType> m_cells;

    void initWalls();
    void printDebug();
    FORCEINLINE int32 posToIndex(int32 x, int32 y) const;
};

}  // namespace Snake