#include <iostream>

#include "board.hpp"

/*Constructors and destructors*/
Board::Board()
/***********************************************
* Function: Board()
* Description: default constructor for board
* Params: none
* warnings: does not initialize the board
***********************************************/
{
	grid = NULL;
	rows = cols = -1;
}


Board::Board(int r, int c)
/***********************************************
* Function: Board(int, int)
* Description: constructor for board, size r rows and c cols
* Params: int r - rows; int c - cols
* warnings: none
***********************************************/
{
	//intialize the size of the grid
	this->rows = r;
	this->cols = c;
	
	//intialize the grid
	grid = new Cell*[rows];
	for(int i = 0; i < rows; i++)
	{
		grid[i] = new Cell[cols];
	}
}


Board::~Board()
/***********************************************
* Function: ~Board()
* Description: destructor for the board class
* Params: none
* warnings: none
***********************************************/
{
	//free the heap
	for(int i = 0; i < rows; i++)
	{
		delete [] grid[i];
	}

	delete [] grid;
}



/*Setters*/

bool Board::setPicked(struct Coord c)
/************************************************
* Function: setPicked() 
* Description: returns true if successfully set to picked
*  returns false if this cell was already picked
* Params: 
* Warnings:
 ************************************************/
{
	if(grid[c.x][c.y].setPicked())
		return true;

	else
	{
		std::cout << "You have already picked this cell" << std::endl;
		return false;
	}
}


/*Getters*/
char Board::getDisplay(struct Coord c)
/************************************************
* Function: getDisplay() 
* Description: returns the value of the cell at the location
* Params: struct Coord c - a struct of the coordinates
* Warnings: none
 ************************************************/
{
	return grid[c.x][c.y].getDisplay();
}

void Board::displayBoard()
/************************************************
* Function: displayBoard() 
* Description: displays the board in its current state
* Params: none
* Warnings: none
 ************************************************/
{
	struct Coord c;
	

	for(int r = 0; r < rows; r++)
	{
		for(int c = 0; c < cols; c++)
		{

		}
	}
}
