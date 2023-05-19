#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Player player, char type, Board* board);
	bool ifLigalMove(int sourceRow, int sourceCol, int destRow, int destCol) const override;
	bool ifMakeCheck(int sourceRow, int sourceCol) const override;
};