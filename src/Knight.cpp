#include "Knight.h"

Knight::Knight(Player player, char type, Board* board) : Piece(player, type, board)
{}

bool Knight::ifLigalMove(int sourceRow, int sourceCol, int destRow, int destCol) const
{
    return true;
}

bool Knight::ifMakeCheck(int sourceRow, int sourceCol) const
{
    return false;
}