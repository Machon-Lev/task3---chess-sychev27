#include "Piece.h"

Piece::Piece(Player player, char type, Board* board)
{
	this->player = player;
	this->type = type;
	this->board = board;
}

Player Piece::getPlayer()
{
	return player;
}

char Piece::getType()
{
	return type;
}