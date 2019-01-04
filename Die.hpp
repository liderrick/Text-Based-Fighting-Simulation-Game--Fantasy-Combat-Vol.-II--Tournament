/**************************************************************************************************************
** Program name: Project 4
** Author: Derrick Li
** Date: Mar. 5, 2017
** Description:
** This class specification file contains the Die class declaration. It represents an Die object.
** It is designed to be a Base class. However, in this program, there is no Derived class.
** It has a protected data member, numOfSides, which represents the number of sides the Die object has. The
** member functions includes a constructor, destructor, functions to set and get the number of sides (numOfSides),
** and a function that simulates the rolling of the Die.
***************************************************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
protected:
	int numOfSides;

public:
	Die(int inputNumOfSides);
	virtual ~Die() {};

	void setSides(int input);
	int getSides();

	virtual int rollDie();
};

#endif