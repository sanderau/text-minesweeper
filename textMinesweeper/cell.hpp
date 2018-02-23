/************************************************************
* Author: Austin Sanders
* File: cell.hpp
* Date: 2.15.18
* Description: This contains the cell class
* Notes: none
*************************************************************/

#define DEBUGGER true // this will display all true values of board making the debugging process easier. Set to true for all values to be shown.

#ifndef CELL_HPP
#define CELL_HPP

class Cell
{
private:
	char hidden; // this is the value to display if the cell is still in the hidden state
	char shown; // this is the value to display when the player has picked this value 
	bool picked; // this  is the value that will tell us wether the player has picked this cell yet. default is false
	bool mine; // if tile is bomb then return true, else false
public:
	/* constructors */
	Cell(); // default constructor
	Cell(bool); // sets whether or not this cell is a bomb
	
	/* getter function */
	char getDisplay(); // get the diplay value for the cell
	bool isBomb(); // returns true if this value is a bomb, false if it isnt

	/* setters */
	void setDisplay(char); // if the cell is not a bomb this function will set the value of the display (How many bombs are adjecent to it)
	bool setPicked(); // only run once when the value is picked by player, makes it so it will display its true value form now on.
	void setBomb(); //when initializing the board this funciton will be called to set this cell to a mine

};

#endif
