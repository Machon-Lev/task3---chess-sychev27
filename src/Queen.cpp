#include "Queen.h"

Queen::Queen(Player player, char type, Board* board) : Piece(player, type, board)
{}

int Queen::move(int sourceRow, int sourceCol, int destRow, int destCol) const
{
    return 42;
}

bool Queen::ifMakeChess(int sourceRow, int sourceCol) const
{
    return false;
}