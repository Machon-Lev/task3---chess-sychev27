#pragma once
#include "Piece.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Piece;
enum Player;

struct KingPlace
{
	int row;
	int col;
};

class Board
{
	Player torn;
	vector<vector<Piece*>> board;
	KingPlace whiteKingPlace;
	KingPlace blackKingPlace;

public:
	Board();
	vector<vector<Piece*>> getBoard();
	void changeTorn();
	void moveOfPiece(int sourceRow, int sourceCol, int destRow, int destCol);
	int move(string sourceAndDest);
	bool ifCheck(Player player);
	Player getNewTorn();
};