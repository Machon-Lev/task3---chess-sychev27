#include "Board.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"


Board::Board()
{
	Rook* white_rook = new Rook(player_1, 'r', this);
	Knight* white_knight = new Knight(player_1, 'n', this);
	Bishop* white_bishop = new Bishop(player_1, 'b', this);
	Queen* white_queen = new Queen(player_1, 'q', this);
	King* white_king = new King(player_1, 'k', this);
	Pawn* white_pawn = new Pawn(player_1, 'p', this);

	Rook* black_rook = new Rook(player_2, 'r', this);
	Knight* black_knight = new Knight(player_2, 'n', this);
	Bishop* black_bishop = new Bishop(player_2, 'b', this);
	Queen* black_queen = new Queen(player_2, 'q', this);
	King* black_king = new King(player_2, 'k', this);
	Pawn* black_pawn = new Pawn(player_2, 'p', this);

	board = {{white_rook, white_knight,white_bishop,white_queen,white_king,white_bishop,white_knight,white_rook},
		     {white_pawn,white_pawn,white_pawn,white_pawn,white_pawn,white_pawn,white_pawn,white_pawn},
		     {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr}, 
	         {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr}, 
	         {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr}, 
	         {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr}, 
		     {black_pawn,black_pawn,black_pawn,black_pawn,black_pawn,black_pawn,black_pawn,black_pawn},
		     {black_rook,black_knight,black_bishop,black_queen,black_king,black_bishop,black_knight,black_rook}};

	torn = player_1;
	whiteKingPlace = { 0 , 4};
	blackKingPlace = { 7, 4 };
}

int Board::move(string sourceAndDest)
{
	int sourceRow = (sourceAndDest[0] - 'a');
	int sourceCol = (sourceAndDest[1] - '1');
	int destRow = (sourceAndDest[2] - 'a');
	int destCol = (sourceAndDest[3] - '1');

	if (board[sourceRow][sourceCol] == nullptr)
		return 11;
	if (board[sourceRow][sourceCol]->getPlayer() != torn)
		return 12;
	if (board[destRow][destCol] != nullptr && board[destRow][destCol]->getPlayer() == torn)
		return 13;

	if (board[sourceRow][sourceCol]->ifLigalMove(sourceRow, sourceCol, destRow, destCol))
	{
		Piece* tempPiece = board[destRow][destCol];
		moveOfPiece(sourceRow, sourceCol, destRow, destCol);
		if (ifCheck(getNewTorn()))
		{
			board[sourceRow][sourceCol] = board[destRow][destCol];
			board[destRow][destCol] = tempPiece;
			return 31;
		}

		if (ifCheck(torn))
		{
			changeTorn();
			return 41;
		}

		changeTorn();
		return 42;
	}

	return 21; 
}

bool Board::ifCheck(Player player)
{
	for (size_t row = 0; row < 8; row++)
	{
		for (size_t col = 0; col < 8; col++)
		{
			if (board[row][col] != nullptr && board[row][col]->getPlayer() == player)
				if (board[row][col]->ifMakeCheck(row, col))
					return true;
		}

	}
	return false;
}

void Board::changeTorn()
{
	if (torn == player_1)
		torn = player_2;
	else
		torn = player_1;		
}

Player Board::getNewTorn()
{
	if (torn == player_1)
		return player_2;
	else
		return player_1;
}

void Board::moveOfPiece(int sourceRow, int sourceCol, int destRow, int destCol)
{
	board[destRow][destCol] = board[sourceRow][sourceCol];
	board[sourceRow][sourceCol] = nullptr;
}

vector<vector<Piece*>> Board::getBoard()
{
	return board;
}