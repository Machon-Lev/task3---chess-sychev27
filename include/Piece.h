#pragma once
#include "Board.h"


class Board;

enum Player
{
    player_1,
    player_2
};

class Piece
{
protected:
    Player player;
    char type;
    Board* board;

public:
    Piece(Player player, char type, Board* board);
    Player getPlayer();
    char getType();
    virtual bool ifLigalMove(int sourceRow, int sourceCol, int destRow, int destCol) const = 0;
    virtual bool ifMakeCheck(int sourceRow, int sourceCol) const = 0;
};