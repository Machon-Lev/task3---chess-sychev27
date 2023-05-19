#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"

Queen::Queen(Player player, char type, Board* board) : Piece(player, type, board)
{}

bool Queen::ifLigalMove(int sourceRow, int sourceCol, int destRow, int destCol) const
{
    return ifLigalRookMove(sourceRow, sourceCol, destRow, destCol, board) || ifLigalBishopMove(sourceRow, sourceCol, destRow, destCol, board);
}

bool Queen::ifMakeCheck(int sourceRow, int sourceCol) const
{
    return ifRookeMakeCheck(sourceRow, sourceCol, board, player) || ifBishopMakeCheck(sourceRow, sourceCol, board, player);
}