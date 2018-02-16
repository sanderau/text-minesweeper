/************************************************************
* Author: Austin Sanders
* File: game.hpp
* Date: 2.16.18
* Description: This contains the game class
* Notes: none
*************************************************************/
/*standard libs*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

/*My libraries*/
#include "board.hpp"

#ifndef GAME_HPP
#define GAME_HPP

enum gameState {won, lost};

/*Helper functions*/
struct Coord toCoord(int,int);
int numRows();
int numCols();
bool isNum(std::string);


class Game 
{
private:
	/*data*/
	Board *board;

	int highScore;
	int currentScore;

	bool gameOver;
	enum gameState gs;

public:
	/*Constructor Destructor*/
	Game();
	Game(int,int);
	~Game();
	
	//setter
	bool pickCell(struct Coord c);
	void playerMove();

	//getter
	void displayBoard();
	bool isMine(struct Coord);
	bool isGameOver();

	//helper
	struct Coord validMove(std::string);
};

#endif
