#include "Bishop.h"
 
Bishop::Bishop(Player player, char type, Board* board) : Piece(player, type, board)
{}

bool Bishop::ifLigalMove(int sourceRow, int sourceCol, int destRow, int destCol) const
{
    return true;
}

bool Bishop::ifMakeCheck(int sourceRow, int sourceCol) const
{
    return false;
}