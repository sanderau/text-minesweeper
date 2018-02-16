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
* Function:
* Description:
* Params:
* Warnings: 
**************************************************/
{
	
}

Game::Game(int r, int c)
{
	board = new Board(r,c);
}

Game::~Game()
{

}
