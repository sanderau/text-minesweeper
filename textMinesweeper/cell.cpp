/*Standard libraries*/
#include <iostream>
/*My terribly written libraries*/
#include "cell.hpp"


Cell::Cell()
/******************************************
* Function: default constructor
* description: I will use this, disregard previous comments
* Params: none
* warnings: When initialized all cells will be not bombs. the creation of the board must deal with adding bombs to the game.
*******************************************/
{
	this->hidden = 'o';
	this->picked = DEBUGGER;
	this->mine = false;
	this->shown = 'e'; 
}

Cell::Cell(bool b)
/******************************************
* Function: Cell
* Description: This will initialize the cell
* Params: bool b - is mine
* warnings: none
*******************************************/
{
	hidden = 'o'; // the value to display if cell has not been picked yet
	picked = false; // is just being created there is no way it could have been picked already
	if(b)
	{
		mine = true;
		shown = 'x'; // this is a mine
	}

	else
	{
		mine = false;
		shown = 'e';
	}
}


char Cell::getDisplay()
/******************************************
* Function: getDisplay
* Description: gets the value to display
* Params: bool b - is mine
* warnings: none
*******************************************/
{
	return picked ? shown : hidden;
}

bool Cell::isBomb()
/******************************************
* Function: isBomb
* Description: returns whether or not this cell is a bomb
* Params: none
* warnings: none
*******************************************/
{
	return mine;
}


void Cell::setDisplay(char s)
/******************************************
* Function: setDisplay
* Description: sets the value to display
* Params:  char s - the value to display
* warnings: none
*******************************************/
{
	shown = s;
}

bool Cell::setPicked()
/******************************************
* Function: setPicked
* Description: sets picked to true
* Params: none
* warnings: none
* return: true if set to true, false if already set to true
*******************************************/
{
	if(this->picked)
	//if already picked return an error
	{
		return false;
	}

	else
	{
		this->picked = true;
		return true;
	}
}

void Cell::setBomb()
/******************************************
* Function: setBomb
* Description: when creating the board it will set this value to a bomb
* Params: none
* warnings: none
*******************************************/
{
	this->mine = true;
	this->shown = 'x';
}
