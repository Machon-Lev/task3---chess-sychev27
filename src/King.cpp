#include "King.h"

King::King(Player player, char type, Board* board) : Piece(player, type, board)
{}

int King::move(int sourceRow, int sourceCol, int destRow, int destCol) const
{
    int rowDifference = abs(sourceRow - destRow);
    int colDifference = abs(sourceCol - destCol);

    if (rowDifference > 1 || colDifference > 1)
        return 21;

    board->changeTorn();
    board->moveOfPiece(sourceRow, sourceCol, destRow, destCol);
    return 42;
}