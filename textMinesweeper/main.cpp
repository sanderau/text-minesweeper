/************************************************************
* Author: Austin Sanders
* File: main.cpp
* Date: 2.15.18
* Description: This contains the actual game
* Notes: Minesweeper is now my original intellectual property
 ** (It was a joke please dont sue me whoever actually owns it :*) )
*************************************************************/

#include <iostream>

/*I'm sorry for how poorly written these are */
#include "board.hpp"

int main(int argc, char *argv[])
{
	Board b(10,11);
	
	b.displayBoard();

	return 0;
}
