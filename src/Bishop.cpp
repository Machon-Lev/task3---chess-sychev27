#include "Bishop.h"
 
Bishop::Bishop(Player player, char type, Board* board) : Piece(player, type, board)
{}

int Bishop::move(int sourceRow, int sourceCol, int destRow, int destCol) const
{
    return 42;
}