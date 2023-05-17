#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Player player, char type, Board* board);
	int move(int sourceRow, int sourceCol, int destRow, int destCol) const override;
};