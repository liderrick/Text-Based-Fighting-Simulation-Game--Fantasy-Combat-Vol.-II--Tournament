/**************************************************************************************************************
** Program name: Project 4
** Author: Derrick Li
** Date: Mar. 5, 2017
** Description:
** This class implementation file contains the member function definitions for the CircularQueue class.
***************************************************************************************************************/

#include "CircularQueue.hpp"
#include "menu.hpp"

#include <iostream>

using std::endl;
using std::cout;

/***************************************************************************************************************
** Description: CircularQueue class contructor. Initialize front and rear pointers to nullptr and count to zero.
***************************************************************************************************************/
CircularQueue::CircularQueue()
{
	front = nullptr;
	rear = nullptr;
	count = 0;
}

/***************************************************************************************************************
** Description: CircularQueue class destructor. Starting from the front and ending at the rear, the destructor first
** deletes the Creature class object being pointed to by the Creature pointer held by each QueueNode then it
** deletes the QueueNode itself.
***************************************************************************************************************/
CircularQueue::~CircularQueue()
{
	while (count != 0)
	{
		QueueNode* garbage = front;

		rear->next = nullptr; //to indicate stopping point

		while (garbage != nullptr)
		{
			front = front->next;
			garbage->next = nullptr;

			delete garbage->fighter; //deletes Creature object held in QueueNode
			garbage->fighter = nullptr;

			delete garbage;	//deletes QueueNode
			garbage = front;

			count--;
		}
	}
}

/***************************************************************************************************************
** Description: addBack() function takes in a Creature pointer as an argument and allocates a new QueueNode at the
** rear of the Queue with a pointer to this Creature class object as its data member. The next pointer of this
** newly allocated QueueNode will point to the front QueueNode so it retains its Circular Queue structure.
** If just one QueueNode is in its Queue, then the QueueNode points to itself. Count is incremented.
** The function does not have a return type.
***************************************************************************************************************/
void CircularQueue::addBack(Creature *inputFighter)
{
	if (count == 0)
	{
		front = new QueueNode(inputFighter); 
		front->next = front; //next pointer on only node points to itself for circular queue
		rear = front;
		count++;
	}
	else
	{
		rear->next = new QueueNode(inputFighter, front); //next pointer is front for circular queue
		rear = rear->next;
		count++;
	}

}

/***************************************************************************************************************
** Description: getFrontFighter() function returns the Creature pointer held in its front QueueNode if there is
** a QueueNode available. The function does not take in an argument.
***************************************************************************************************************/
Creature * CircularQueue::getFrontFighter()
{
	Creature* frontFighter = nullptr;

	if (count != 0)
	{
		frontFighter = front->fighter;
	}

	return frontFighter;
}

/***************************************************************************************************************
** Description: removeFront() function first returns the Creature pointer held in its front QueueNode if there
** is a QueueNode available, then it deletes the QueueNode from its Queue. The function does not take in an argument.
***************************************************************************************************************/
Creature * CircularQueue::removeFront()
{
	Creature* tempCreature = nullptr;
	QueueNode* tempQueueNode = nullptr;

	if (count != 0)
	{
		tempCreature = front->fighter;
		tempQueueNode = front;

		if (count == 1)
		{
			front = nullptr;
			rear = nullptr;
		}
		else
		{
			front = front->next;
			rear->next = front;
		}

		tempQueueNode->next = nullptr;

		delete tempQueueNode;

		--count;
	}

	return tempCreature;
}

/***************************************************************************************************************
** Description: advanceFrontAndRear() function advance the front and rear QueueNode pointers one QueueNode
** forward. If there is only one QueueNode in its Queue, the pointer will remain pointing to the same QueueNode
** after function is called. The function does not take in any argument and does not have a return type.
***************************************************************************************************************/
void CircularQueue::advanceFrontAndRear()
{
	front = front->next;
	rear = rear->next;
}

/***************************************************************************************************************
** Description: printQueue() goes through the entire CircularQueue, starting at the front and ending at the rear, and
** prints out the Creature name and type data members held by the Creature object of each QueueNode. The function
** makes a call the printCreatureType() function to convert the char data type to a readable string object that
** makes sense to the user. The function does not take in an argument and does not have a return type.
***************************************************************************************************************/
void CircularQueue::printQueue()
{
	int functionCount = count;
	char tempCreatureType;

	int countUp = 1;

	QueueNode *nodePtr = front;

	if (nodePtr == nullptr)
	{
		cout << endl << "Queue is empty!" << endl;
	}
	else
	{
		do
		{
			cout << countUp <<") Name: ";
			cout << nodePtr->fighter->getCreatureName() << endl;

			cout << "      Type: ";
			tempCreatureType = nodePtr->fighter->getCreatureType();
			printCreatureType(tempCreatureType);
			cout << endl;

			nodePtr = nodePtr->next;
			functionCount--;

			countUp++;

		} while (functionCount > 0);

	}
}
