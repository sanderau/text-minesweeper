#include "cell.hpp"

#ifndef BOARD_HPP
#define BOARD_HPP

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
