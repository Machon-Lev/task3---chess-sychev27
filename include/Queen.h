#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(Player player, char type, Board* board);
	int move(int sourceRow, int sourceCol, int destRow, int destCol) const override;
	bool ifMakeChess(int sourceRow, int sourceCol) const override;
};