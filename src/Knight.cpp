#include "Knight.h"

Knight::Knight(Player player, char type, Board* board) : Piece(player, type, board)
{}

int Knight::move(int sourceRow, int sourceCol, int destRow, int destCol) const
{
    return 42;
}

bool Knight::ifMakeChess(int sourceRow, int sourceCol) const
{
    return false;
}