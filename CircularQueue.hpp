/**************************************************************************************************************
** Program name: Project 4
** Author: Derrick Li
** Date: Mar. 5, 2017
** Description:
** This class specification file contains the CircularQueue class declaration. It represents a Circular Queue
** class of Creature class objects. It has a QueueNode structure (which holds a pointer to a Creature class
** object as its data value and a next pointer to another QueueNode), pointers to the front and rear
** QueueNodes of the CircularQueue object, and a counter variable (count) to keep track of the number of
** QueueNodes in its Queue.
** The public member functions include the constructor, destructor, a function to add a new QueueNode to its
** Queue, a function to get the Creature held in the front QueueNode, a function to remove the front QueueNode,
** a function to advance the front and rear pointers one QueueNode forward, and a function to print the name and
** type of the Creatures held in its QueueNodes.
***************************************************************************************************************/

#ifndef CIRCULARQUEUE_HPP
#define CIRCULARQUEUE_HPP

#include "Creature.hpp"
#include <string>

using std::string;

class CircularQueue
{
private:
	struct QueueNode
	{
		Creature* fighter;
		QueueNode* next;

		QueueNode(Creature* inputFighter = nullptr, QueueNode* inputNext = nullptr)
		{
			fighter = inputFighter;
			next = inputNext;
		}
	};
	QueueNode* front;
	QueueNode* rear;

	int count;

public:
	CircularQueue();
	~CircularQueue();

	void addBack(Creature* inputFighter);

	Creature* getFrontFighter();
	Creature* removeFront();

	void advanceFrontAndRear();

	void printQueue();
};

#endif