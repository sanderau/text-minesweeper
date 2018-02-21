/************************************************************
* Author: Austin Sanders
* File: main.cpp
* Date: 2.15.18
* Description: This contains the actual game
* Notes: Minesweeper is now my original intellectual property
 ** (It was a joke please dont sue me whoever actually owns it :*) )
*************************************************************/

#include <iostream>

/*I'm sorry for how poorly written these are*/
#include "game.hpp"

int main(int argc, char *argv[])
{
	//initialize the first game
	Game game(numRows(), numCols());	
	
	while(!(game.isGameOver()))
	{
		game.displayBoard();
		game.playerMove(); // implement this next
		//game.checkGame(); // implement this after
	}

	return 0;
}
