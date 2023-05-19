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

    // Check if the move is diagonal
    if (rowDifference != colDifference)
    {
        return false;
    }

    int fromRow, toRow, fromCol;
    if (destRow > sourceRow && destCol > sourceCol)
    {
        // Move is diagonal towards bottom-right
        fromRow = sourceRow + 1;
        toRow = destRow - 1;
        fromCol = sourceCol + 1;

        // Check for obstacles in the diagonal path
        for (int i = 0; i <= toRow - fromRow; i++)
        {
            if (board->getBoard()[fromRow + i][fromCol + i] != nullptr)
                return false;  // Obstacle encountered, move is illegal
        }
    }
    else
    {
        if (destRow < sourceRow && destCol < sourceCol)
        {
            // Move is diagonal towards top-left
            fromRow = destRow + 1;
            toRow = sourceRow - 1;
            fromCol = destCol + 1;

            // Check for obstacles in the diagonal path
            for (int i = 0; i <= toRow - fromRow; i++)
            {
                if (board->getBoard()[fromRow + i][fromCol + i] != nullptr)
                    return false;  // Obstacle encountered, move is illegal
            }
        }
        else
        {
            if (destRow > sourceRow && destCol < sourceCol)
            {
                // Move is diagonal towards bottom-left
                fromRow = sourceRow + 1;
                toRow = destRow - 1;
                fromCol = sourceCol - 1;

                // Check for obstacles in the diagonal path
                for (int i = 0; i <= toRow - fromRow; i++)
                {
                    if (board->getBoard()[fromRow + i][fromCol - i] != nullptr)
                        return false;   // Obstacle encountered, move is illegal
                }
            }
            else
            {
                // Move is diagonal towards top-right
                fromRow = sourceRow - 1;
                toRow = destRow + 1;
                fromCol = sourceCol + 1;

                // Check for obstacles in the diagonal path
                for (int i = 0; i <= toRow - fromRow; i++)
                {
                    if (board->getBoard()[fromRow - i][fromCol + i] != nullptr)
                        return false;  // Obstacle encountered, move is illegal
                }
            }
        }
    }

    // No obstacles encountered, move is legal
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
        // Check diagonal towards bottom-right
        fromRow = sourceRow + 1;
        fromCol = sourceCol + 1;
        for (int i = 0; i < 7; i++)
        {
            if (fromRow + i <= 7 && fromCol + i <= 7)
            {
                if (board->getBoard()[fromRow + i][fromCol + i] != nullptr)
                {
                    if (board->getBoard()[fromRow + i][fromCol + i]->getType() == 'k' && board->getBoard()[fromRow + i][fromCol + i]->getPlayer() != player)
                        return true;  // King found, bishop makes check
                    else
                        break;       // Obstacle encountered, stop searching in this direction
                }
            }
            else
                break;   // Reached the board edge, stop searching in this direction
        }
    }
    if (sourceRow > 0 && sourceCol > 0)
    {
        // Check diagonal towards top-left
        fromRow = sourceRow - 1;
        fromCol = sourceCol - 1;
        for (int i = 0; i < 7; i++)
        {
            if (fromRow - i >= 0 && fromCol - i >= 0)
            {
                if (board->getBoard()[fromRow - i][fromCol - i] != nullptr)
                {
                    if (board->getBoard()[fromRow - i][fromCol - i]->getType() == 'k' && board->getBoard()[fromRow - i][fromCol - i]->getPlayer() != player)
                        return true;  // King found, bishop makes check
                    else
                        break;  // Obstacle encountered, stop searching in this direction
                }
            }
            else
                break;  // Reached the board edge, stop searching in this direction
        }
    }
    if (sourceRow < 7 && sourceCol > 0)
    {
        // Check diagonal towards bottom-left
        fromRow = sourceRow + 1;
        fromCol = sourceCol - 1;
        for (int i = 0; i < 7; i++)
        {
            if (fromRow + i <= 7 && fromCol - i >= 0)
            {
                if (board->getBoard()[fromRow + i][fromCol - i] != nullptr)
                {
                    if (board->getBoard()[fromRow + i][fromCol - i]->getType() == 'k' && board->getBoard()[fromRow + i][fromCol - i]->getPlayer() != player)
                        return true;  // King found, bishop makes check
                    else
                        break;  // Obstacle encountered, stop searching in this direction
                }
            }
            else
                break;  // Reached the board edge, stop searching in this direction
        }
    }
    if (sourceRow > 0 && sourceCol < 7)
    {
        // Check diagonal towards top-right
        fromRow = sourceRow - 1;
        fromCol = sourceCol + 1;
        for (int i = 0; i < 7; i++)
        {
            if (fromRow - i >= 0 && fromCol + i <= 7)
            {
                if (board->getBoard()[fromRow - i][fromCol + i] != nullptr)
                {
                    if (board->getBoard()[fromRow - i][fromCol + i]->getType() == 'k' && board->getBoard()[fromRow - i][fromCol + i]->getPlayer() != player)
                        return true;  // King found, bishop makes check
                    else
                        break;   // Obstacle encountered, stop searching in this direction
                }
            }
            else
                break;  // Reached the board edge, stop searching in this direction
        }
    }
    return false;  // No king found in any diagonal direction
}