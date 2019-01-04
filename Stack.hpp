/**************************************************************************************************************
** Program name: Project 4
** Author: Derrick Li
** Date: Mar. 5, 2017
** Description:
** This class specification file contains the Stack class declaration. It represents a dynamic stack class.
** It has a StackNode structure (which holds a pointer to a Creature class object as its data value and a next
** pointer to another StackNode), a pointer to the top (StackNode) of the stack, and a counter variable, count,
** to keep track of the number of StackNodes in the Stack.
** The public member functions include the constructor, destructor, a function to add a Creature pointer to the
** Stack, and a function to print the StackNode (specifically it prints to screen the Creature name and type
** data members pointed to by the Creature pointer).
***************************************************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include "Creature.hpp"
#include <string>

using std::string;

class Stack
{
private:
	struct StackNode
	{
		Creature* fighter;
		StackNode* next;

		StackNode(Creature* inputFighter = nullptr, StackNode* inputNext = nullptr)
		{
			fighter = inputFighter;
			next = inputNext;
		}
	};
	StackNode* top;

	int count;

public:
	Stack();
	~Stack();

	void add(Creature* inputFighter);

	void printStack();
};

#endif