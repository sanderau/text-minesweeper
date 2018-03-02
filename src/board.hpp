/************************************************************
* Author: Austin Sanders
* File: board.hpp
* Date: 2.16.18
* Description: This contains the board class
* Notes: none
*************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

//the one library i have to include
#include "cell.hpp"

/*helper funcitons*/
void getSpace(int); // writes the correct amount of space to the board
int numDigits(int); // returns the amount of digits an integer has.


struct Coord
{
	int x;
	int y;
};

//enums to make setting the difficulty easier

enum Difficulty {Easy=0, Medium, Hard};

class Board
{
private:
	Cell **grid;
	int rows;
	int cols;
	double difficulty; // diffuclty of the game

	std::string space;

	/*internal functions*/

	/*setters*/

	/*getters*/
	int numOfBombsAround(struct Coord); // returns the number of bombs around the passed location
	char getDisplay(struct Coord);


public:
	/* Constuctors destructors*/
	Board(); // default constructor
	Board(int, int); // creates the board with a user defined number of rows and 
	Board(int, int, Difficulty);
	~Board();

	//setters
	bool setPicked(struct Coord c);
	//getters
	int numBombs(); // debugging function to make sure that the board has the correct number of bombs
	void displayBoard();
	int getRows();
	int getCols();
	bool isMine(struct Coord);
};

#endif
