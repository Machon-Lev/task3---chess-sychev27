#include "Rook.h"

Rook::Rook(Player player, char type, Board* board) : Piece(player, type, board)
{}

bool Rook::ifLigalMove(int sourceRow, int sourceCol, int destRow, int destCol) const
{   
    return ifLigalRookMove(sourceRow, sourceCol, destRow, destCol, board);
}

bool ifLigalRookMove(int sourceRow, int sourceCol, int destRow, int destCol, Board* board)
{
    // Check if the move is horizontal or vertica
    if (sourceRow != destRow && sourceCol != destCol)
        return false;

    int from, to;
    if (sourceRow == destRow)
    {
        // Move is horizontal, determine the range of columns to check
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

        // Check for obstacles in the horizontal path
        for (from; from <= to; from++)
        {
            if (board->getBoard()[sourceRow][from] != nullptr)
                return false;
        }
    }
    else
    {
        // Move is vertical, determine the range of rows to check
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

        // Check for obstacles in the vertical path
        for (from; from <= to; from++)
        {
            if (board->getBoard()[from][sourceCol] != nullptr)
                return false;
        }
    }
    // No obstacles encountered, move is legal
    return true;
}

bool Rook::ifMakeCheck(int sourceRow, int sourceCol) const
{
    return ifRookeMakeCheck(sourceRow, sourceCol, board, player);
}

bool ifRookeMakeCheck(int sourceRow, int sourceCol, Board* board, Player player)
{
    int from;
    if (sourceRow < 7)
    {
        from = sourceRow + 1;
        // Check for opponent's king in the downward direction
        for (from; from <= 7; from++)
        {
            if (board->getBoard()[from][sourceCol] != nullptr)
            {
                if (board->getBoard()[from][sourceCol]->getType() == 'k' && board->getBoard()[from][sourceCol]->getPlayer() != player)
                    return true;  // Opponent's king is in check
                else
                    break;        // Obstacle encountered, stop checking further
            }
        }
    }
    if (sourceRow > 0)
    {
        from = sourceRow - 1;
        // Check for opponent's king in the upward direction
        for (from; from >= 0; from--)
        {
            if (board->getBoard()[from][sourceCol] != nullptr)
            {
                if (board->getBoard()[from][sourceCol]->getType() == 'k' && board->getBoard()[from][sourceCol]->getPlayer() != player)
                    return true;  // Opponent's king is in check
                else
                    break;       // Obstacle encountered, stop checking further
            }
        }
    }
    if (sourceCol < 7)
    {
        from = sourceCol + 1;
        // Check for opponent's king in the rightward direction
        for (from; from <= 7; from++)
        {
            if (board->getBoard()[sourceRow][from] != nullptr)
            {
                if (board->getBoard()[sourceRow][from]->getType() == 'k' && board->getBoard()[sourceRow][from]->getPlayer() != player)
                    return true;  // Opponent's king is in check
                else
                    break;       // Obstacle encountered, stop checking further
            }
        }
    }
    if (sourceCol > 0)
    {
        from = sourceCol - 1;
        // Check for opponent's king in the leftward direction
        for (from; from >= 0; from--)
        {
            if (board->getBoard()[sourceRow][from] != nullptr)
            {
                if (board->getBoard()[sourceRow][from]->getType() == 'k' && board->getBoard()[sourceRow][from]->getPlayer() != player)
                    return true;   // Opponent's king is in check
                else
                    break;        // Obstacle encountered, stop checking further
            }
        }
    }
    return false;   // Opponent's king is not in check
}