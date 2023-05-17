#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Player player, char type, Board* board);
	int move(int sourceRow, int sourceCol, int destRow, int destCol) const override;
};