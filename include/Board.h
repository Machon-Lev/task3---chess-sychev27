#pragma once
#include "Piece.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Piece;
enum Player;


class Board
{
	Player torn;
	vector<vector<Piece*>> board;

public:
	Board();
	vector<vector<Piece*>> getBoard();
	void changeTorn();
	void moveOfPiece(int sourceRow, int sourceCol, int destRow, int destCol);
	int move(string sourceAndDest);
};