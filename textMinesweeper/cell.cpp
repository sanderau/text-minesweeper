/*Standard libraries*/
#include <iostream>
/*My terribly written libraries*/
#include "cell.hpp"


Cell::Cell()
/******************************************
* Function: default constructor
* description: I will never use this
* Params: none
* warnings: none
*******************************************/
{
	std::cout << "This is from inside the cell classes default constructor. If you see this my creator messed up somewhere" << std::endl;
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

void Cell::isPicked()
/******************************************
* Function: isPicked
* Description: sets picked to true
* Params: none
* warnings: none
*******************************************/
{
	picked = true;
}
