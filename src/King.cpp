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
    if ((sourceRow + 1 <= 7 && sourceCol + 1 <= 7 && board->getBoard()[sourceRow + 1][sourceCol + 1] != nullptr && board->getBoard()[sourceRow + 1][sourceCol + 1]->getType() == 'k') ||
        (sourceRow - 1 >= 0 && sourceCol - 1 >= 0 && board->getBoard()[sourceRow - 1][sourceCol - 1] != nullptr && board->getBoard()[sourceRow - 1][sourceCol - 1]->getType() == 'k') ||
        (sourceRow + 1 <= 7 && sourceCol - 1 >= 0 && board->getBoard()[sourceRow + 1][sourceCol - 1] != nullptr && board->getBoard()[sourceRow + 1][sourceCol - 1]->getType() == 'k') ||
        (sourceRow - 1 >= 0 && sourceCol + 1 <= 7 && board->getBoard()[sourceRow - 1][sourceCol + 1] != nullptr && board->getBoard()[sourceRow - 1][sourceCol + 1]->getType() == 'k') ||
        (sourceRow + 1 <= 7 && board->getBoard()[sourceRow + 1][sourceCol] != nullptr && board->getBoard()[sourceRow + 1][sourceCol]->getType() == 'k') ||
        (sourceRow - 1 >= 0 && board->getBoard()[sourceRow - 1][sourceCol] != nullptr && board->getBoard()[sourceRow - 1][sourceCol]->getType() == 'k') ||
        (sourceCol + 1 <= 7 && board->getBoard()[sourceRow][sourceCol + 1] != nullptr && board->getBoard()[sourceRow][sourceCol + 1]->getType() == 'k') ||
        (sourceCol - 1 >= 0 && board->getBoard()[sourceRow][sourceCol - 1] != nullptr && board->getBoard()[sourceRow][sourceCol - 1]->getType() == 'k'))
    {
        return true;
    }
    return false;
}