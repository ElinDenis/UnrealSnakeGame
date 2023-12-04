// SnakeGame. Copyright Elin Denis. All Rights Reserved.
// Developed with Unreal Engine 5.3
#pragma once

#include "CoreMinimal.h"
#include "Core/Types.h"

namespace SnakeGame
{

class Grid
{
public:
    Grid(const Dim& dim);

    /**
     * Returns grid dimensions including walls (width + 2; height + 2)
     * @return Dim  grid dimensions
     */
    Dim dim() const { return c_dim; };
    void printDebug();
    void update(const TPositionPtr* links, CellType cellType);
    bool hitTest(const Position& position, CellType cellType) const;

private:
    const Dim c_dim;
    TArray<CellType> m_cells;
    TMap<CellType, TArray<uint32>> m_idtByType{
        {CellType::Snake, {}},  //
        {CellType::Wall, {}},   //
    };

    void initWalls();
    FORCEINLINE uint32 posToIndex(uint32 x, uint32 y) const;
    FORCEINLINE uint32 posToIndex(const Position& position) const;
    void freeCellsByType(CellType cellType);
};

}  // namespace SnakeGame