#include "Bishop.h"
 
Bishop::Bishop(Player player, char type, Board* board) : Piece(player, type, board)
{}

bool Bishop::ifLigalMove(int sourceRow, int sourceCol, int destRow, int destCol) const
{
    return ifLigalBishopMove(sourceRow, sourceCol, destRow, destCol, board);
}

bool ifLigalBishopMove(int sourceRow, int sourceCol, int destRow, int destCol, Board* board)
{
    int rowDifference = abs(sourceRow - destRow);
    int colDifference = abs(sourceCol - destCol);

    if (rowDifference != colDifference)
    {
        return false;
    }

    int fromRow, toRow, fromCol;
    if (destRow > sourceRow && destCol > sourceCol)
    {
        fromRow = sourceRow + 1;
        toRow = destRow - 1;
        fromCol = sourceCol + 1;

        for (int i = 0; i <= toRow - fromRow; i++)
        {
            if (board->getBoard()[fromRow + i][fromCol + i] != nullptr)
                return false;
        }
    }
    else
    {
        if (destRow < sourceRow && destCol < sourceCol)
        {
            fromRow = destRow + 1;
            toRow = sourceRow - 1;
            fromCol = destCol + 1;

            for (int i = 0; i <= toRow - fromRow; i++)
            {
                if (board->getBoard()[fromRow + i][fromCol + i] != nullptr)
                    return false;
            }
        }
        else
        {
            if (destRow > sourceRow && destCol < sourceCol)
            {
                fromRow = sourceRow + 1;
                toRow = destRow - 1;
                fromCol = sourceCol - 1;

                for (int i = 0; i <= toRow - fromRow; i++)
                {
                    if (board->getBoard()[fromRow + i][fromCol - i] != nullptr)
                        return false;
                }
            }
            else
            {
                fromRow = sourceRow - 1;
                toRow = destRow + 1;
                fromCol = sourceCol + 1;

                for (int i = 0; i <= toRow - fromRow; i++)
                {
                    if (board->getBoard()[fromRow - i][fromCol + i] != nullptr)
                        return false;
                }
            }
        }
    }

    return true;
}

bool Bishop::ifMakeCheck(int sourceRow, int sourceCol) const
{
    return ifBishopMakeCheck(sourceRow, sourceCol, board, player);
}

bool ifBishopMakeCheck(int sourceRow, int sourceCol, Board* board, Player player)
{
    int fromRow, fromCol;
    if (sourceRow < 7 && sourceCol < 7)
    {
        fromRow = sourceRow + 1;
        fromCol = sourceCol + 1;
        for (int i = 0; i < 7; i++)
        {
            if (fromRow + i <= 7 && fromCol + i <= 7)
            {
                if (board->getBoard()[fromRow + i][fromCol + i] != nullptr)
                {
                    if (board->getBoard()[fromRow + i][fromCol + i]->getType() == 'k' && board->getBoard()[fromRow + i][fromCol + i]->getPlayer() != player)
                        return true;
                    else
                        break;
                }
            }
            else
                break;
        }
    }
    if (sourceRow > 0 && sourceCol > 0)
    {
        fromRow = sourceRow - 1;
        fromCol = sourceCol - 1;
        for (int i = 0; i < 7; i++)
        {
            if (fromRow - i >= 0 && fromCol - i >= 0)
            {
                if (board->getBoard()[fromRow - i][fromCol - i] != nullptr)
                {
                    if (board->getBoard()[fromRow - i][fromCol - i]->getType() == 'k' && board->getBoard()[fromRow - i][fromCol - i]->getPlayer() != player)
                        return true;
                    else
                        break;
                }
            }
            else
                break;
        }
    }
    if (sourceRow < 7 && sourceCol > 0)
    {
        fromRow = sourceRow + 1;
        fromCol = sourceCol - 1;
        for (int i = 0; i < 7; i++)
        {
            if (fromRow + i <= 7 && fromCol - i >= 0)
            {
                if (board->getBoard()[fromRow + i][fromCol - i] != nullptr)
                {
                    if (board->getBoard()[fromRow + i][fromCol - i]->getType() == 'k' && board->getBoard()[fromRow + i][fromCol - i]->getPlayer() != player)
                        return true;
                    else
                        break;
                }
            }
            else
                break;
        }
    }
    if (sourceRow > 0 && sourceCol < 7)
    {
        fromRow = sourceRow - 1;
        fromCol = sourceCol + 1;
        for (int i = 0; i < 7; i++)
        {
            if (fromRow - i >= 0 && fromCol + i <= 7)
            {
                if (board->getBoard()[fromRow - i][fromCol + i] != nullptr)
                {
                    if (board->getBoard()[fromRow - i][fromCol + i]->getType() == 'k' && board->getBoard()[fromRow - i][fromCol + i]->getPlayer() != player)
                        return true;
                    else
                        break;
                }
            }
            else
                break;
        }
    }
    return false;
}