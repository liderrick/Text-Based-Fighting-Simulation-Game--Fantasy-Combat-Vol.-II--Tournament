/**************************************************************************************************************
** Program name: Project 4
** Author: Derrick Li
** Date: Mar. 5, 2017
** Description:
** This class implementation file contains the member function definitions for the Die class.
***************************************************************************************************************/

#include "Die.hpp"
#include <cstdlib>		//for srand and rand functions
#include <ctime>		//for time functions

/***************************************************************************************************************
** Description: This Die class constructor takes in the number of sides of the Die and uses it to initialize a
** Die class object.
***************************************************************************************************************/
Die::Die(int inputNumOfSides)
{
	setSides(inputNumOfSides);
}

/***************************************************************************************************************
** Description: setSides() function assigns the numOfSides a value that represents the number of sides the
** Die object has. It takes in an integer as an argument to assign to numOfSides. It does not return anything.
***************************************************************************************************************/
void Die::setSides(int input)
{
	numOfSides = input;
}

/***************************************************************************************************************
** Description: getSides() function returns the number of sides of the Die object (numOfSides) as an integer.
** It does not take any argument.
***************************************************************************************************************/
int Die::getSides()
{
	return numOfSides;
}

/***************************************************************************************************************
** Description: rollDie() function randomly returns an integer value between 1 and the number of sides of the
** Die object - effectively simulating a Die roll. It does not take any argument.
***************************************************************************************************************/
int Die::rollDie()
{
	return rand() % numOfSides + 1;
}
