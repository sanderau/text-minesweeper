/************************************************************
* Author: Austin Sanders
* File: board.cpp
* Date: 2.16.18
* Description: This contains the implementation for the board class
* Notes: none
*************************************************************/

/*well written libraries*/
#include <iostream>
/*My libraries*/
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
	space = "   ";
}


Board::Board(int r, int c)
/***********************************************
* Function: Board(int, int)
* Description: constructor for board, size r rows and c cols
* Params: int r - rows; int c - cols
* warnings: none
***********************************************/
{
	space = "   ";
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
	getSpace(0);

	for(int c = 1; c <= cols; c++)
	//print the number of cols
	{
		std::cout << c;
		getSpace(c);
	}
	
	std::cout << "\n";
	getSpace(0);

	for (int i = 0; i < cols; i++)
	//print the top border
	{
		std::cout << "----";
	}

	std::cout << "\n";

	for(int r = 0; r < rows; r++)
	{
		std::cout << r+1;
		getSpace(r+1);
		std::cout << "|";

		for(int c = 0; c < cols; c++)
		{
			std::cout << grid[r][c].getDisplay() << space;
		}
		std::cout << "\n";
	}
}

int Board::getRows()
/*********************************************
* function: get rows
* Description: get the number of rows board has
* Params: none
* Warnings: none
**********************************************/
{
	return this->rows;
}


int Board::getCols()
/*********************************************
* function: getCols()
* Description: get the number of cols board has
* Params: none
* Warnings: none
**********************************************/
{
	return this->cols;
}

bool Board::isMine(struct Coord c)
/*********************************************
* function: isMine()
* Description: returns wether or not the cell is a mine
* Params: none
* Warnings: none
**********************************************/
{
	return grid[c.x][c.y].isBomb();
}

/* Helper functions*/

void getSpace(int v)
/************************************************
* Function: getSpace
* Description: this prints the correct amount of space to the board
 ** since the grid can be dynamically allocated there is no way to tell
 ** how big numbers will get and this will ensure everything that gets 
 **printed will have a total of four spaces to occupy
* Params: the value about to be printed
* Warnings: this only works for grid numbers rn
 ************************************************/
{
	int digits = 4 - numDigits(v);
	for(int i = 0; i < digits; i++)
	{
		std::cout << " ";
	}
}


int numDigits(int v)
/***********************************************************
* Function: numDigits 
* Description: returns the number of digits an integer has
* Params: int v - the number to analyze
* Warnings: expects a type of positive integer
************************************************************/
{
	int digits = 0;

	while(v > 0)
	{
		digits++;
		v = v / 10;
	}

	return digits;
}
