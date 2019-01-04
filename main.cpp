/**************************************************************************************************************
** Program name: Project 4
** Author: Derrick Li
** Date: Mar. 5, 2017
** Description:
** This program is a fighting game stimulation that involves 1 user and 2 Players. The user chooses the number
** of fighters to assign to each Player and chooses the fighter types (and their names). The Player chooses their
** lineup from the list of available fighters that the user assigned to them. The game runs automatically. In each
** battle, the fighters at the front of the Queue fight. They fight until one Creature has no more (or negative) strength.
** The winning fighter has some of its strength regenerated and placed in the back of the winning Player's Queue. 
** The losing fighter is removed from the losing Player's Queue and placed into the loserPile Stack, the stack
** of fighters who lost. The fighters battle until one Queue has no more Creatures to battle. The final score
** and winning Player is announced. The winning Player is the Player with the most wins. If the number of wins
** are the same between both Players, then a Tie is announced. At the end, there is an option to display the
** list of fighters who lost.
***************************************************************************************************************/

#include "Tournament.hpp"
#include "CircularQueue.hpp"
#include "Stack.hpp"
#include "Creature.hpp"
#include "Die.hpp"
#include "menu.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::endl;
using std::cout;
using std::cin;

/***************************************************************************************************************
** Description: main() is the function that makes the necessary function calls to run a Tournament game. It
** first prompts the user to enter the number of fighter for each player, creates the necessary array of Creature
** object pointers, prompt user to populate the arrays, prompt Players to form their lineup from the available
** Creatures, and battles the Creatures until one Player has exhausted their Queue. The winner or tie is
** announced and the user is prompted with an option to display the list of fighters who lost.
***************************************************************************************************************/
int main()
{
	setRandomSeed();
	
	Tournament *game = new Tournament;
	
	Creature** p1Pool = nullptr;
	Creature** p2Pool = nullptr;

	int numOfFightersForP1 = 0;
	int numOfFightersForP2 = 0;

	int userChoice = 0;

	system("clear");
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "Welcome to FANTASY COMBAT VOL. II: TOURNAMENT" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;

	userChoice = mainMenu();

	if (userChoice == 1)
	{
		cout << endl << "-----------------------------------------------------------------------------" << endl;
		cout << "You will first enter the number of fighters for each Player." << endl;
		cout << "-----------------------------------------------------------------------------" << endl;

		numOfFightersForP1 = pickNumberOfFightersMenu(1);
		numOfFightersForP2 = pickNumberOfFightersMenu(2);

		p1Pool = new Creature*[numOfFightersForP1];
		p2Pool = new Creature*[numOfFightersForP2];

		cout << endl << "-----------------------------------------------------------------------------" << endl;
		cout << "Now you will choose the fighters and the name of those fighters for each Player." << endl;
		cout << "-----------------------------------------------------------------------------" << endl;

		chooseFighterMenu(1, p1Pool, numOfFightersForP1);
		chooseFighterMenu(2, p2Pool, numOfFightersForP2);

		cout << endl << "-----------------------------------------------------------------------------" << endl;
		cout << "Now Player 1 chooses their Fighter lineup." << endl;
		cout << "-----------------------------------------------------------------------------" << endl;

		chooseLineUpMenu(1, numOfFightersForP1, p1Pool, game);

		cout << endl << "-----------------------------------------------------------------------------" << endl;
		cout << "Now Player 2 chooses their Fighter lineup." << endl;
		cout << "-----------------------------------------------------------------------------" << endl;

		chooseLineUpMenu(2, numOfFightersForP2, p2Pool, game);

		cout << endl << "-----------------------------------------------------------------------------" << endl;
		cout << "The following is the starting lineup for each Player. " << endl;

		cout << "-----------------------------------------------------------------------------" << endl;
		game->printPlayerQueue(1);

		cout << endl << "-----------------------------------------------------------------------------" << endl;
		game->printPlayerQueue(2);

		cout << endl << "-----------------------------------------------------------------------------" << endl;
		cout << "Press [Enter] start the Tournament!";
		cin.ignore();

		game->playTournament();

		cout << endl << "-----------------------------------------------------------------------------" << endl;
		promptDisplayLoserPile(game);

		delete[] p1Pool;
		p1Pool = nullptr;

		delete[] p2Pool;
		p2Pool = nullptr;
	}
	else
	{
		cout << endl << "Goodbye." << endl << endl;
	}

	delete game;		//deletes Tournament object

	return 0;
}