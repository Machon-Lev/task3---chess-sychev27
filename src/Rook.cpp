#include "Rook.h"

Rook::Rook(Player player, char type, Board* board) : Piece(player, type, board)
{}

int Rook::move(int sourceRow, int sourceCol, int destRow, int destCol) const
{
    if (sourceRow != destRow && sourceCol != destCol)
        return 21;

    int from, to;
    if (sourceRow == destRow)
    {
        if (sourceCol < destCol)
        {
            from = sourceCol + 1;
            to = destCol - 1;
        }
        else
        {
            from = destCol + 1;
            to = sourceCol - 1;
        }

        for (from; from <= to; from++)
        {
            if (board->getBoard()[sourceRow][from] != nullptr)
                return 21;
        }
    }
    else
    {
        if (sourceRow < destRow)
        {
            from = sourceRow + 1;
            to = destRow - 1;
        }
        else
        {
            from = destRow + 1;
            to = sourceRow - 1;
        }

        for (from; from <= to; from++)
        {
            if (board->getBoard()[from][sourceCol] != nullptr)
                return 21;
        }
    }
    
    board->changeTorn();
    board->moveOfPiece(sourceRow, sourceCol, destRow, destCol);
    return 42;
}