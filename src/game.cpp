/************************************************************
* Author: Austin Sanders 
* File: game.cpp
* Date: 2.16.18
* Description: This is the implementation for the game class
* Notes: none 
*************************************************************/

/*Well written libraries*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

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

void Game::initialize()
/**************************************************
* Function: initialize
* Description: initializes a game
* params: none
* Warnings: none, yet.
**************************************************/
{
	std::string input;
	do {
		std::cout << "1. Easy\n2. Medium\n3. Hard\nWhat difficulty would you like: ";
		std::getline(std::cin, input);
	}while(input.at(0) != 49 && input.at(0) != 50 && input.at(0)); // keep asking for input while it doesnt equal 1, 2, 3

	int c = numCols();
	int r = numRows();


	board = new Board(r, c, toEnum(atoi(input.c_str())-1)); //oh boy this really isn't needed, but I sure do like bells and whistles
	//also I think I remember someone telling me dont put function calls in parameters, but what do they know?
	//it looks cool and that is all that matters in programming.

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

void Game::playerMove()
/***************************************************
* Function: playerMove
* Description: gets a move from the player
* params: none
* warnings: I need to flush something because once this
 ** is called after initializing the game the first time
 ** there is already something in the dang buffer.
***************************************************/
{
	fflush(stdin);
	fflush(stdout);
	std::cout << "\n" << std::flush;//flush input output to avoid getline error

	std::string input;
	struct Coord c;
	c.x = c.y = -1;
	
	while(c.x == -1 and c.y == -1)
	//keep prompting the user for which cell they want until they give valid input
	{
		std::cout << "Which cell: ";
		std::getline(std::cin, input); // get input from user

		c = validMove(input); // see if it is a valid move

	}


	this->board->setPicked(c);

	if(this->board->isMine(c))
	{
		this->gameOver = true;
	}

	std::cout << std::string(100, '\n');
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


/**********************HELPER FUNCTIONS*************************/

enum Difficulty Game::toEnum(int d)
/******************************************************
 * Function: toEnum(int)
 * Description: takes an int and turns it into its corresponding enum
 * Param: int to turn into enum
 * Warnings: This is probably not needed
 ******************************************************/
{
	Difficulty diff;

	switch(d) // turn the input into a enum that the board class will understand
	{
		case 0: 
			diff = Easy;
			break;
		case 1:
			diff = Medium;
			break;
		case 2:
			diff = Hard;
			break;
	}


	return diff;
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

//	std::cout << std::string(100, '\n');

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
	for(unsigned int i = 0; i < in.length(); i++) //unsigned int so the compiler doesnt lose its mind
	{
		if(in.at(i) > 57 or in.at(i) < 48)
		{
			return false;
		}
	}

	return true;
}


struct Coord Game::validMove(std::string in)
{
	struct Coord c;
	for(unsigned int i = 0; i < in.length(); i++)
	{
		if((in.at(i) > 57 or in.at(i) < 48) and (in.at(i) != 32))
		// if the value isnt a number or a space
		{
			std::cout << "Unexpected value in string" << std::endl;
			c.x = c.y = -1;
			return c; // return a failure
		}
	}

	std::istringstream iss(in);

	int tok = 0; // number of tokens should not exceed 2

	do
	//convert the string into numbers I can interpret
	{
	//	std::cout << "number of tokens: " << tok << std::endl;

		std::string sub;
		iss >> sub;

	//	std::cout << "Current substring: " << sub << std::endl;

		if(tok == 0)
		{
			c.x = atoi(sub.c_str());
		}

		else if(tok == 1)
		{
			c.y = atoi(sub.c_str());
		}

		else if(tok >= 3)
		{
	//		std::cout << "Unexpected amount of values" << std::endl;
			c.x = c.y = -1; // return an error
			return c; // too many values
		}
		
		tok++;

	}while(iss);


	if(c.x-1 > board->getRows() or c.y-1 > board->getCols())
	// if an out of bounds error return error
	{
		std::cout << "Out of bounds error" << std::endl;
		c.x = c.y = -1;
		return c;
	}

	else if(c.x-1 < 0 or c.y-1 < 0)
	//other out of bounds case
	{
		std::cout << "Out of bounds error" << std::endl;
		c.x = c.y = -1;
		return c;
	}

	c.x -= 1;
	c.y -= 1;


	return c; // passes all tests return valid value
}
