/**************************************************************************************************************
** Program name: Project 4
** Author: Derrick Li
** Date: Mar. 5, 2017
** Description:
** This class implementation file contains the member function definitions for the Tournament class.
***************************************************************************************************************/

#include "Tournament.hpp"
#include "menu.hpp"

/***************************************************************************************************************
** Description: Tournament class constructors. Initializes its int data members to zero.
***************************************************************************************************************/
Tournament::Tournament()
{
	battles = 0;
	
	p1Wins = 0;
	p2Wins = 0;
}

/***************************************************************************************************************
** Description: addToPlayerQueue() function takes in a Player's identifier (an integer, i.e Player 1, Player 2),
** and a pointer to a Creature object. It adds the Creature to the corresponding Player's Circular Queue by
** calling the addBack() member function on the Circular Queue object. The function does not have a return type.
***************************************************************************************************************/
void Tournament::addToPlayerQueue(int player, Creature *creaturePtr)
{
	if (player == 1)
	{
		p1Queue.addBack(creaturePtr);
	}
	else if (player == 2)
	{
		p2Queue.addBack(creaturePtr);
	}
}

/***************************************************************************************************************
** Description: moveFromPlayerQueueToLoserPile() function takes in a Player's identifier (an integer, i.e Player 1,
** Player 2). It removes the front QueueNode of the corresponding Player's CircularQueue and add the Creature
** that was held in the QueueNode to the loserPile (a Stack of fighters who lost). The function does not have
** a return type.
***************************************************************************************************************/
void Tournament::moveFromPlayerQueueToLoserPile(int player)
{
	Creature* tempCreature = nullptr;

	if (player == 1)
	{
		tempCreature = p1Queue.removeFront();
	}
	else if (player == 2)
	{
		tempCreature = p2Queue.removeFront();
	}

	if (tempCreature != nullptr)
	{
		loserPile.add(tempCreature);
	}
	
}

/***************************************************************************************************************
** Description: printPlayerQueue() function takes in a Player's identifier (an integer, i.e Player 1,
** Player 2) and prints the Player's Creature lineup in its Queue. The function does not have a return type.
***************************************************************************************************************/
void Tournament::printPlayerQueue(int player)
{
	cout << endl << "The lineup for Player " << player << " is:" << endl << endl;
	
	if (player == 1)
	{
		p1Queue.printQueue();
	}
	else if (player == 2)
	{
		p2Queue.printQueue();
	}
}

/***************************************************************************************************************
** Description: printLoserPile() function prints the stack of fighters who lost (loserPile). The function
** does not take in an argument and does not have a return type.
***************************************************************************************************************/
void Tournament::printLoserPile()
{
	cout << endl << "The fighters who lost are:" << endl;
	loserPile.printStack();
}

/***************************************************************************************************************
** Description: displayBattleHeadliner() function prints to screen the details of the Creatures who will fight,
** i.e. the Creature held in the front QueueNode of each of the Player's CircularQueue. The function does not
** take in an argument and does not have a return type.
***************************************************************************************************************/
void Tournament::displayBattleHeadliner()
{
	char tempCreatureType;

	Creature * p1creature = p1Queue.getFrontFighter();
	Creature * p2creature = p2Queue.getFrontFighter();

	cout << "PLAYER 1 -- Name: ";
	cout << p1creature->getCreatureName();

	cout << " (";
	tempCreatureType = p1creature->getCreatureType();
	printCreatureType(tempCreatureType);
	cout << ")" << endl;

	cout << "  V.S." << endl;

	cout << "PLAYER 2 -- Name: ";
	cout << p2creature->getCreatureName();

	cout << " (";
	tempCreatureType = p2creature->getCreatureType();
	printCreatureType(tempCreatureType);
	cout << ")" << endl;

}

/***************************************************************************************************************
** Description: playBattle() function battles the Creature held in the front QueueNode of each of the Player's
** CircularQueue to each other. The battle is over when one of the Creature has zero or less strength points.
** The method of battle only allows for one winner and one loser, there are no ties. The winner is announced
** to screen, the winning creature regenerates some of its strength points lost overall, and the fighter is placed
** to the rear of the winning Player's Queue. The Creature who lost is remove from the losing Player's Queue
** and added to the loser Stack. The function does not take in an argument and does not have a return type.
***************************************************************************************************************/
void Tournament::playBattle()
{
	Creature * p1creature = p1Queue.getFrontFighter();
	Creature * p2creature = p2Queue.getFrontFighter();

	int playerTurn = rand() % 2 + 1;   //random player turn
	//int round = 1;


	while (p1creature->getStrength() > 0 && p2creature->getStrength() > 0)
	{
		if (playerTurn == 1)
		{
			//cout << endl << "Round " << round << ":" << endl;

			//cout << endl << "   Player 1:" << endl;
			int attackDamage = p1creature->attack();
			//cout << "   Player 1 dealt " << attackDamage << " total damage points." << endl;

			//cout << endl << "   Player 2:" << endl;
			p2creature->defend(attackDamage);

			//if (p2creature->getStrength() > 0)
			//{
			//	cout << "   Player 2 strength after receiving attack is " << p2creature->getStrength() << "." << endl;
			//}
			//else
			//{
			//	cout << "   Player 2 has no more strength." << endl;
			//}

			playerTurn = 2;		//increment player turn
		}
		else if (playerTurn == 2)
		{
			//cout << endl << "Round " << round << ":" << endl;

			//cout << endl << "   Player 2:" << endl;
			int attackDamage = p2creature->attack();
			//cout << "   Player 2 dealt " << attackDamage << " total damage points." << endl;

			//cout << endl << "   Player 1:" << endl;
			p1creature->defend(attackDamage);

			//if (p1creature->getStrength() > 0)
			//{
			//	cout << "   Player 1 strength after receiving attack is " << p1creature->getStrength() << "." << endl;
			//}
			//else
			//{
			//	cout << "   Player 1 has no more strength." << endl;
			//}

			playerTurn = 1;		//increment player turn
		}
		//round++;
	}

	if (p1creature->getStrength() > 0)
	{
		cout << endl << "PLAYER 1 -- ";
		cout << p1creature->getCreatureName();

		cout << " (";
		printCreatureType(p1creature->getCreatureType());
		cout << ") is the WINNER!" << endl;

		p1Wins++;

		cout << endl << "SCORE   --   PLAYER 1: " << p1Wins << "   --   PLAYER 2: " << p2Wins << endl;

		cout << endl << "Player 1 creature's (" << p1creature->getCreatureName() << ") strength is " << p1creature->getStrength() << " point(s) at end of battle." << endl;
		p1creature->recoverStrength();
		cout << "The creature recovered some strength from any damage inflicted. Its new strength level is now at " << p1creature->getStrength() << " point(s)." << endl;

		moveFromPlayerQueueToLoserPile(2);

		p1Queue.advanceFrontAndRear();

	}
	else if (p2creature->getStrength() > 0)
	{
		cout << endl << "PLAYER 2 -- ";
		cout << p2creature->getCreatureName();

		cout << " (";
		printCreatureType(p2creature->getCreatureType());
		cout << ") is the WINNER!" << endl;

		p2Wins++;

		cout << endl << "SCORE   --   PLAYER 1: " << p1Wins << "   --   PLAYER 2: " << p2Wins << endl;

		cout << endl << "Player 2 creature's (" << p2creature->getCreatureName() << ") strength is " << p2creature->getStrength() << " point(s) at end of battle." << endl;
		p2creature->recoverStrength();
		cout << "The creature recovered some strength from any damage inflicted. Its new strength level is now at " << p2creature->getStrength() << " point(s)." << endl;

		moveFromPlayerQueueToLoserPile(1);

		p2Queue.advanceFrontAndRear();
	}

}

/***************************************************************************************************************
** Description: playTournament() function battles the Creatures held in each Player's Queue until one Queue
** has no more Creatures to battle. The final score and winning Player is announced. The winning Player is the
** Player with the most wins. If the number of wins are the same between both Players, then a Tie is announced.
** The function does not take in an argument and does not have a return type.
***************************************************************************************************************/
void Tournament::playTournament()
{
	while (p1Queue.getFrontFighter() != nullptr && p2Queue.getFrontFighter() != nullptr)
	{
		battles++;
		cout << endl << "Battle #" << battles << ": " << endl;
		displayBattleHeadliner();
		playBattle();

		cout << endl << "-----------------------------------------------------------------------------" << endl;
		cout << "Press [Enter] to continue.";
		cin.ignore();
	}

	cout << endl << "The FINAL SCORE is :" << endl;
	cout << "PLAYER 1: " << p1Wins << "   --   PLAYER 2: " << p2Wins << endl;

	if (p1Wins > p2Wins)
	{
		cout << endl << "PLAYER 1 is the WINNER of the TOURNAMENT!" << endl;
	}
	else if (p1Wins < p2Wins)
	{
		cout << endl << "PLAYER 2 is the WINNER of the TOURNAMENT!" << endl;
	}
	else   //tie
	{
		cout << endl << "TIE! Neither player won." << endl;
	}
}
