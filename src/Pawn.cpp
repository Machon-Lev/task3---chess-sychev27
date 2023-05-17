#include "Pawn.h"

Pawn::Pawn(Player player, char type, Board* board) : Piece(player, type, board)
{}

int Pawn::move(int sourceRow, int sourceCol, int destRow, int destCol) const
{
    return 42;
}

bool Pawn::ifMakeChess(int sourceRow, int sourceCol) const
{
    return false;
}