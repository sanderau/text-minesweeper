/************************************************************
* Author: Austin Sanders, William Crumpton
* File: board.cpp
* Date: 2.16.18
* Description: This contains the implementation for the board class
* Notes: none
*************************************************************/

/*well written libraries*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
/*Mine*/
#include "board.hpp"
#include "cell.hpp"
#include "rngs.h"



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

Board::Board(int r, int c, Difficulty diff)
/***********************************************
* Function: Board(int, int, Difficulty)
* Description: constructor for board, size r rows and c cols, and populates the board according to difficulty
* Params: int r - rows; int c - cols
* warnings: none
***********************************************/
{

	switch(diff)
	//diff is the variable that refers to what percent of the board
	//is going to be mines. 
	//Example: 10x10 board = 100 possible spaces; Easy difficulty = 15% bombs; therefore the board will have 15 random bomb spaces
	{
		case Easy:
			difficulty = .15;
			break;
		case Medium:
			difficulty = .20;
			break;
		case Hard:
			difficulty = .25;
			break;
	}
	
	//Initialize size and format variables.
	space = "   ";
	this->rows = r;
	this->cols = c;
	
	//Initialize the 2D grid array with Cell objects.
	grid = new Cell*[rows];
	for(int i = 0; i < rows; i++) {
		grid[i] = new Cell[cols];
	}
	
	//The number of bombs is calculated by taking the total number of cells and multiplying it by the difficulty ratio
	int bombs = r*c*difficulty;
	
	//PlantSeeds(rand() % 696969); //this plants a random ammount of magic random number beans
	//possible methods of randomizing bomb placement.
//	std::cout << "Bombs at: [";
	while(bombs > 0){
		//SelectStream(rand() % 256); //I decided to use both just to make things extra random.
		int randRow = fmod(rand(),r);
		int randCol = fmod(rand(),c);
		if(!(grid[randCol][randRow].isBomb())){
//			std::cout << " (" << randCol << ", "<< randRow << ") ";
			grid[randCol][randRow].setBomb();
			bombs--;
		}
	}
	
//		std::cout << "] " << std::endl;

	/*
	* Task: difficulty will contain the percentage of the board that is bombs
	* find out how many bombs that is, then program an algorithm that will
	* populate the board with that many bombs. Each bomb must contain a 
	* unique position, so the board will always be populated with that many
	* bombs
	*/

	/*
	* Extra task: As you may or may not know the included "random" functions
	* inside of c++ are psuedorandom, as in they are not truly random, and if
	* someone really wanted to, they could predict where the bombs will be using a set
	* of knowns. To prevent this hypothetical hacker from making our game ez. I have
	* included two files rngs.h rngs.c that include function that make random 
	* numbers that are closer to truly random. Use their random functions when making the board, to make the positions
	* truly random. Do not worry too much about implementation, just learn how to use the
	* functions. These programs have been around since the 90's so they are pretty well documented on the internet.
	* They are written in C however, so when using them use C's nomenclature.
	* Also don't worry about compilation and linking, I will update the makefile accordingly. Good luck.
	*/


	for(int i = 0; i < this->rows; i++)
	{
		for(int j = 0; j < this->cols; j++)
		{
			if(!(grid[i][j].isBomb()))
			{
			//	std::cout << "Setting up cell @ " << i << ", " << j;
				struct Coord c;
				c.x = i;
				c.y = j;
				grid[i][j].setDisplay(numOfBombsAround(c)+48);
			//	std:: cout << " | Here is the display char: " << disChar << std::endl;
			}
		}
	}

//	std::cout << "All done!" << std::endl;
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
	c.x--;
	c.y--; // fixing and error the wrong way because I am too lazy to find the real culprit rn

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

int Board::numOfBombsAround(struct Coord coord)
/****************************************************
 * Function numOfBombsAround()
 * Description: returns the number of bombs around passed Coord
 * Params: struct Coord c - the cell to eval
 * Warnings: none
 ****************************************************/
{
	int numBombs=0;
//	std::cout << "Coordinates to test @ (" << coord.x << " , " << coord.y << ")" << ": [";

	for(int r = coord.x-1; r <= coord.x+1; r++)
	{
		for(int c = coord.y-1; c <= coord.y+1; c++)
		{
			if((r >= 0 && c >= 0) && ( r < this->rows && c < this->cols ))
			{
//				std::cout << "( " << r << ", " << c << ")";
				if(this->grid[r][c].isBomb())
				{
//					std::cout << ", B ";
					numBombs++;
				}
			}
		}
	}

//	std::cout << "]" << std::endl;

	return numBombs;

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

int Board::numBombs()
/**********************************************
 * function: numBombs()
 * description: returns the number of bombs on the board 
  **using for debugging
 * params: none
 * warnings: none
 *********************************************/
 {
	int numBombs = 0;
	for(int r = 0; r < this->rows; r++)
	{
		for(int c = 0; c < this->cols; c++)
		{
			if(this->grid[r][c].isBomb())
				numBombs++;
		}
	}

	return numBombs;
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
