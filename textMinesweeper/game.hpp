/************************************************************
* Author: Austin Sanders
* File: game.hpp
* Date: 2.16.18
* Description: This contains the game class
* Notes: none
*************************************************************/
/*My libraries*/
#include "board.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game 
{
private:
	/*data*/
	Board *board;

public:
	/*Constructor Destructor*/
	Game();
	Game(int,int);
	~Game();
};

#endif
