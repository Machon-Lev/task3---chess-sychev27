#include "King.h"

King::King(Player player, char type, Board* board) : Piece(player, type, board)
{}

bool King::ifLigalMove(int sourceRow, int sourceCol, int destRow, int destCol) const
{
    int rowDifference = abs(sourceRow - destRow);
    int colDifference = abs(sourceCol - destCol);

    if (rowDifference > 1 || colDifference > 1)
        return false;

    return true;
}

bool King::ifMakeCheck(int sourceRow, int sourceCol) const
{
    return false;
}