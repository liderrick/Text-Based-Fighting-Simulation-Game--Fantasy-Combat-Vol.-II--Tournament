/**************************************************************************************************************
** Program name: Project 4
** Author: Derrick Li
** Date: Mar. 5, 2017
** Description:
** This class implementation file contains the member function definitions for the Stack class.
***************************************************************************************************************/

#include "Stack.hpp"
#include "menu.hpp"

#include <iostream>

using std::endl;
using std::cout;

/***************************************************************************************************************
** Description: Stack class contructor. Initialize top pointer to nullptr and count to zero.
***************************************************************************************************************/
Stack::Stack()
{
	top = nullptr;
	count = 0;
}

/***************************************************************************************************************
** Description: Stack class destructor. Starting from the top and ending at the bottom, the destructor first
** deletes the Creature class object being pointed to by the Creature pointer held by each StackNode then it
** deletes the StackNode itself.
***************************************************************************************************************/
Stack::~Stack()
{
	while (count != 0)
	{
		StackNode* garbage = top;

		while (garbage != nullptr)
		{
			top = top->next;
			garbage->next = nullptr;
			delete garbage->fighter; //deletes Creature object held in StackNode
			garbage->fighter = nullptr;

			delete garbage;	//deletes StackNode
			garbage = top;

			count--;
		}
	}
}

/***************************************************************************************************************
** Description: add() function takes in a Creature pointer as an argument and allocates a new StackNode at the
** top of the Stack with a pointer to this Creature class object as its data member. Count is incremented.
** The function does not have a return type.
***************************************************************************************************************/
void Stack::add(Creature * inputFighter)
{
	top = new StackNode(inputFighter, top);
	count++;
}

/***************************************************************************************************************
** Description: printStack() goes through the entire Stack, starting at the top and ending at the bottom, and
** prints out the Creature name and type data members held by the Creature object of each StackNode. The function
** makes a call the printCreatureType() function to convert the char data type to a readable string object that
** makes sense to the user. The function does not take in an argument and does not have a return type.
***************************************************************************************************************/
void Stack::printStack()
{
	int functionCount = count;
	char tempCreatureType;

	int countUp = 1;

	StackNode *nodePtr = top;

	if (nodePtr == nullptr)
	{
		cout << endl << "Stack is empty!" << endl;
	}
	else
	{
		do
		{
			cout << countUp << ") Name: ";
			cout << nodePtr->fighter->getCreatureName() << endl;

			cout << "     Type: ";
			tempCreatureType = nodePtr->fighter->getCreatureType();
			printCreatureType(tempCreatureType);	//function prints out string equivalent of char type
			cout << endl;

			nodePtr = nodePtr->next;
			functionCount--;

			countUp++;

		} while (functionCount > 0);
	}
}
