#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Player player, char type, Board* board);
	bool ifLigalMove(int sourceRow, int sourceCol, int destRow, int destCol) const override;
	bool ifMakeCheck(int sourceRow, int sourceCol) const override;
};