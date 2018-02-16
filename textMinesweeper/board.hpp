/************************************************************
* Author: Austin Sanders
* File: board.hpp
* Date: 2.16.18
* Description: This contains the board class
* Notes: none
*************************************************************/
/*Standard libraries*/
#include <iostream>
#include <string>
/*Mine*/
#include "cell.hpp"

#ifndef BOARD_HPP
#define BOARD_HPP

/*helper funcitons*/
void getSpace(int); // writes the correct amount of space to the board
int numDigits(int); // returns the amount of digits an integer has.


struct Coord
{
	int x;
	int y;
};

class Board
{
private:
	Cell **grid;
	int rows;
	int cols;

	std::string space;

	/*internal functions*/

	/*setters*/

	/*getters*/
	char getDisplay(struct Coord);


public:
	/* Constuctors destructors*/
	Board(); // default constructor
	Board(int, int); // creates the board with a user defined number of rows and 
	~Board();

	//setters
	bool setPicked(struct Coord c);
	//getters
	void displayBoard();
};

#endif
