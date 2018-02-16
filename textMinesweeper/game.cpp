/************************************************************
* Author: Austin Sanders
* File: game.cpp
* Date: 2.16.18
* Description: This is the implementation for the game class
* Notes: none
*************************************************************/

/*Well written libraries*/
#include <iostream>

/*I'm sorry*/
#include "game.hpp"

/*Constructor destructors*/
Game::Game()
/*************************************************
* Function: Game
* Description: default constructor for the game
* Params: none
* Warnings: none
**************************************************/
{
	//set scores down to zero
	highScore = currentScore = 0;
	gameOver = false;

	//with no constructor the game will automatically set the 
	// rows and cols to 10
	board = new Board(10,10);
}

Game::Game(int r, int c)
/**************************************************
* Function: Game(int, int)
* Description: constructor for the game that makes the board r rows and c cols
* params: r - num of rows; c - num of cols
* Warnings: none
**************************************************/
{
	//set scores
	highScore = currentScore = 0;
	gameOver = false;

	//user specified length
	board = new Board(r,c);
}

Game::~Game()
/***************************************************
* Function: ~Game
* Description: frees all the memory when the function is done
* params: none
* warnings: none
***************************************************/
{
	delete board;
}

/*Setters*/

bool Game::pickCell(struct Coord c)
/***************************************************
* Function: pickCell
* Description: user pickes a cell. Returns true if can be picked
 ** false if it cannot
* params: Coord c - coordinates of the cell
* warnings: none
***************************************************/
{
	return board->setPicked(c);
}

/*Getters*/
void Game::displayBoard()
/***************************************************
* Function: displayBoard
* Description: displays the board in its current state
* params: none
* warnings: none
***************************************************/
{
	board->displayBoard();
}

bool Game::isMine(struct Coord c)
/*********************************************
* function: isMine()
* Description: returns whether or not the cell is a mine
* Params: struct Coord c - coordinates of the cell
* Warnings: none
**********************************************/
{
	if(board->isMine(c))
	{
		this->gameOver = true;
	}	

	return board->isMine(c);
}

bool Game::isGameOver()
/*********************************************
* function: isMine()
* Description: returns whether or not the cell is a mine
* Params: struct Coord c - coordinates of the cell
* Warnings: none
**********************************************/
{
	return this->gameOver;
}


/*helpers*/
struct Coord toCoord(int r, int c)
/***************************************************
* Function: toCoord
* Description: takes in the coord as two seperate int vals
 ** and returns a Coord struct with those values
* params: int r - rows; int c - cols
* warnings: this function reindexes the user input values
 ** from values that make sense to the user to values
 ** the 2d array can recognize (0 indexed)
***************************************************/
{
	struct Coord temp;
	temp.x = r-1;
	temp.y = c-1;

	return temp;
}

int numRows()
{
	std::string input = "abc";

	while(!(isNum(input)))
	{
		std::cout << "How many rows in this game: ";
		std::cin >> input;
	}

	int r = atoi(input.c_str());

	return r;
}

int numCols()
{	
	std::string input = "abc";

	while(!(isNum(input)))
	{
		std::cout << "How many cols in this game: ";
		std::cin >> input;
	}

	int c = atoi(input.c_str());

	return c;
}

bool isNum(std::string in)
{
	for(int i = 0; i < in.length(); i++)
	{
		if(in.at(i) > 57 or in.at(i) < 48)
		{
			return false;
		}
	}

	return true;
}
