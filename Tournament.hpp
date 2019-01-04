/**************************************************************************************************************
** Program name: Project 4
** Author: Derrick Li
** Date: Mar. 5, 2017
** Description:
** This class specification file contains the Tournament class declaration. It represents a Tournament game
** that holds the fighter lineup of each Player with functionality to battle the fighters and keep track of score.
** Its private member funtions consists of a Circular Queue to hold Player 1's fighter lineup, a Circular
** Queue to hold Player 2's fighter lineup, a Stack to hold the list of fighters who lost, an int member to
** hold the battles that have been fought, and int members to hold the number battles player 1 and 2 won.
** Its public member functions includes the constructor, a function to add a Creature to a Player's Queue, a
** function to remove a Creature from a Player's Queue and add it to the loser Stack, a function to print a
** Player's Queue, a function to print the loser Stack, a function to battle two Creatures, and a function
** to play the Tournament. The fighters battle until one Queue has no more Creatures to battle. The final score
** and winning Player is announced. The winning Player is the Player with the most wins. If the number of wins
** are the same between both Players, then a Tie is announced.
***************************************************************************************************************/

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include "CircularQueue.hpp"
#include "Stack.hpp"
#include "Creature.hpp"

#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::cin;
using std::string;

class Tournament
{
private:
	CircularQueue p1Queue;
	CircularQueue p2Queue;
	Stack loserPile;

	int battles;

	int p1Wins;
	int p2Wins;

public:
	Tournament();

	void addToPlayerQueue(int player, Creature *creaturePtr);
	void moveFromPlayerQueueToLoserPile(int player);
	
	void printPlayerQueue(int player);
	void printLoserPile();

	void displayBattleHeadliner();

	void playBattle();
	void playTournament();
};

#endif