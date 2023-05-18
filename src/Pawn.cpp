#include "Pawn.h"

Pawn::Pawn(Player player, char type, Board* board) : Piece(player, type, board)
{}

bool Pawn::ifLigalMove(int sourceRow, int sourceCol, int destRow, int destCol) const
{
    return true;
}

bool Pawn::ifMakeCheck(int sourceRow, int sourceCol) const
{
    return false;
}