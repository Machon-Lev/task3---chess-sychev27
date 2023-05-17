#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Player player, char type, Board* board);
	int move(int sourceRow, int sourceCol, int destRow, int destCol) const override;
};