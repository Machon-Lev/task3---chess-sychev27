#include "Queen.h"

Queen::Queen(Player player, char type, Board* board) : Piece(player, type, board)
{}

bool Queen::ifLigalMove(int sourceRow, int sourceCol, int destRow, int destCol) const
{
    return true;
}

bool Queen::ifMakeCheck(int sourceRow, int sourceCol) const
{
    return false;
}