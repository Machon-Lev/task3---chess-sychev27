#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(Player player, char type, Board* board);
	int move(int sourceRow, int sourceCol, int destRow, int destCol) const override;
	bool ifMakeChess(int sourceRow, int sourceCol) const override;
};