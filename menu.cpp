/**************************************************************************************************************
** Program name: Project 4
** Author: Derrick Li
** Date: Mar. 5, 2017
** Description:
** This implementation file contains definitions for menu-related functions, including a function
** that seeds the random number generator.
***************************************************************************************************************/

#include "Tournament.hpp"
#include "Creature.hpp"
#include "menu.hpp"

#include <iostream>
#include <cstdlib>		//for srand and rand functions
#include <ctime>		//for time functions
#include <string>

using std::endl;
using std::cout;
using std::cin;
using std::string;

/***************************************************************************************************************
** Description: setRandomSeed() seeds the random number generator with time(NULL). It should run only once per
** program before any function calls are made to the rand function.
***************************************************************************************************************/
void setRandomSeed()
{
	srand(time(NULL));
}

/***************************************************************************************************************
** Description: mainMenu() function displays the main menu and prompts the user to select an option. The
** input validation ensures a valid option has been chosen. The function returns this integer value.
** It does not take any argument. Revision 06Feb17 to work with inputIntegerValidationV2 function.
***************************************************************************************************************/
int mainMenu()
{
	bool validInteger = false;
	bool validChoice = false;
	int choice = 0;

	do
	{
		cout << endl << "Please select an option:" << endl;
		cout << "1) Play game" << endl;
		cout << "2) Exit" << endl;
		cout << "Choice: ";
		validInteger = inputIntegerValidationV2(choice);

		if (validInteger && choice >= 1 && choice <= 2)
		{
			validChoice = true;
		}
		else
		{
			cout << "Invalid choice. Try again." << endl;
		}

	} while (validChoice == false);

	return choice;
}

/***************************************************************************************************************
** Description: inputIntegerValidationV2() function validates an integer has been entered. If
** it has, the integer is returned as a reference parameter and true is returned as a bool from the function.
** If not, 0 is returned to its reference parameter and false is returned as a bool from the function.
** Based on original function, inputIntegerValidation. New version can validate negative values. Revision 06Feb17.
***************************************************************************************************************/
bool inputIntegerValidationV2(int &num)
{
	num = 0; //initialize 0 as default

	bool validInteger = false;

	string inputString;
	getline(cin, inputString);

	try
	{
		num = stoi(inputString);
		validInteger = true;
	}
	catch (std::exception const &e)
	{
		validInteger = false;
	}

	return validInteger;
}

/***************************************************************************************************************
** Description: pickNumberOfFightersMenu() takes in the player's identifier, an integer, i.e. Player 1 or Player 2.
** It prompts the user to enter the number of fighters they would like that Player to have. It validates it
** is an integer and greater than zero. This integer is returned from the function.
***************************************************************************************************************/
int pickNumberOfFightersMenu(int player)
{
	bool validInteger = false;
	bool validChoice = false;
	int choice = 0;

	do
	{
		cout << endl << "Please enter number of fighters to give to Player " << player << "." << endl;
		cout << "(Enter an integer greater than 0): ";
		validInteger = inputIntegerValidationV2(choice);

		if (validInteger && choice > 0)
		{
			validChoice = true;
		}
		else
		{
			cout << "Invalid choice. Try again." << endl;
		}

	} while (validChoice == false);

	return choice;
}

/***************************************************************************************************************
** Description: chooseFighterMenu() takes in a Player's identifier (an integer, i.e Player 1, Player 2), a double
** pointer to Creature class objects (which points to an array that holds pointers to Creature class objects),
** and an integer, numOfFighters, which represents the number of fighters the user will pick for the Player.
** The function informs the user it will select n number of fighters for the Player, where n = numOfFighters.
** It then iterates a for loop n times that 1) provides the user a list of Creatures for them to choose from, and
** 2) asks the user to select a Creature and provide it a name. The information is used to create a new Creature
** class object and assign it to an available spot in the array of pointers. The function does not have a return type.
***************************************************************************************************************/
void chooseFighterMenu(int player, Creature ** dptr, int numOfFighters)
{
	cout << endl << "***** You will choose " << numOfFighters << " fighters for Player "<< player << ". *****" << endl;
	
	for (int i = 0; i < numOfFighters; i++) {
		Creature *character = nullptr;
		bool validInteger = false;
		bool validChoice = false;
		int choice = 0;

		string inputName = "";

		do
		{
			cout << endl << "Choose character #" << i+1 << " to add to the fighter pool for Player " << player << ":" << endl;
			cout << "1) Vampire" << endl;
			cout << "2) Barbarian" << endl;
			cout << "3) Blue Men" << endl;
			cout << "4) Medusa" << endl;
			cout << "5) Harry Potter" << endl;
			cout << "Choice: ";
			validInteger = inputIntegerValidationV2(choice);

			if (validInteger && choice >= 1 && choice <= 5)
			{
				cout << "Enter a name for the character: ";
				getline(cin, inputName);

				validChoice = true;

				switch (choice)
				{
				case 1: character = new Vampire(inputName);
					break;
				case 2: character = new Barbarian(inputName);
					break;
				case 3: character = new BlueMen(inputName);
					break;
				case 4: character = new Medusa(inputName);
					break;
				case 5: character = new HarryPotter(inputName);
					break;
				}

				cout << endl << inputName << " (";
				printCreatureType(character->getCreatureType());
				cout << ") added to Player " << player << " fighter pool." << endl;

			}
			else
			{
				cout << "Invalid choice. Try again." << endl;
			}

		} while (validChoice == false);

		dptr[i] = character;		//adds character to pool
	}
}

/***************************************************************************************************************
** Description: printCreatureType() function takes in a character, either 'v', 'b', 'x', 'm', or 'h' and prints out
** its string equivalent-- "Vampire", "Barbarian", "Blue Men", "Medusa", and "Harry Potter," respectively.
** The function does not have a return type.
***************************************************************************************************************/
void printCreatureType(char tempCreatureType)
{
	switch (tempCreatureType)
	{
	case 'v': cout << "Vampire";
		break;
	case 'b': cout << "Barbarian";
		break;
	case 'x': cout << "Blue Men";
		break;
	case 'm': cout << "Medusa";
		break;
	case 'h': cout << "Harry Potter";
		break;
	}
}

/***************************************************************************************************************
** Description: displayePool() takes in a double pointer to Creature class objects (which points to an array
** that holds pointers to Creature class objects) and the number of elements of that array. It then iterates
** through the entire array and prints out the name and type of each Creature. The function makes a call to
** printCreatureType() function to convert its character type into a readable string. The function does not have
** a return type.
***************************************************************************************************************/
void displayPool(Creature ** dptr, int count)
{
	char tempCreatureType;

	for (int i = 0; i < count; i++)
	{
		if (dptr[i] != nullptr)
		{
			cout << i + 1 << ") Name: ";
			cout << dptr[i]->getCreatureName() << endl;

			cout << "     Type: ";
			tempCreatureType = dptr[i]->getCreatureType();

			printCreatureType(tempCreatureType);

			cout << endl;

		}

	}

}

/***************************************************************************************************************
** Description: chooseLineUpMenu() takes in 1) a Player's identifier (an integer, i.e Player 1, Player 2),
** 2) a double pointer to Creature class objects (which points to an array that holds pointers to Creature class
** objects), 3) an integer, numOfFighters, which represents the number of fighters in the array, and 4) a
** pointer to a Tournament class object, which represents the game the user/Players are playing.
** The function displays a list of available fighter it has in its array of pointers and prompts the Player
** to select an integer corresponding to a fighter to add it to their Lineup in the Tournament class object.
** The function makes a call to the addToPlayerQueue() function in the Tournament object to queue the Creature
** object in the game. The function removes the Creature object from its array of pointers by assigning
** nullptr in its place. The function iterates the loop until all Creatures have been assigned. The function
** does not have a return type.
***************************************************************************************************************/
void chooseLineUpMenu(int fighter, int numOfFighters, Creature **dptr, Tournament *game)
{
	Creature *tempCreature = nullptr;
	
	bool validInteger = false;
	bool validChoice = false;
	int count = numOfFighters;
	int choice = 0;

	do
	{
		cout << endl << "The available fighters for Player " << fighter << ": " << endl;
		displayPool(dptr, numOfFighters);
		cout << endl << "Choose a fighter to add to Player " << fighter << " lineup. " << endl;
		cout << "(Enter an integer corresponding to a fighter in the list): ";
		validInteger = inputIntegerValidationV2(choice);

		if (validInteger && choice >= 1 && choice <= numOfFighters)
		{
			tempCreature = dptr[choice - 1];

			if (tempCreature == nullptr)
			{
				cout << "Invalid choice. Try again." << endl;
			}
			else
			{
				game->addToPlayerQueue(fighter, tempCreature);
				dptr[choice - 1] = nullptr;
				validChoice = true;
				count--;


				cout << endl << choice << ") " << tempCreature->getCreatureName() << " (";
				printCreatureType(tempCreature->getCreatureType());
				cout << ") added to Player " << fighter << " lineup." << endl;
			}
		}
		else
		{
			cout << "Invalid choice. Try again." << endl;
		}


	} while (count > 0 || validChoice == false);
}

/***************************************************************************************************************
** Description: promptDisplayLoserPile() takes in a pointer to a Tournament class object. It prompts the user
** if they would like to display the pile of fighters who have lost during the tournament battles. If 'Y' is
** chosen then the function makes a call to printLoserPile() function in the Tournament game to print the list.
** The function does not have a return type.
***************************************************************************************************************/
void promptDisplayLoserPile(Tournament *game)
{
	char displayPile;

	do
	{
		cout << endl << "Would you like to display the pile of fighters who lost [Y/N]? ";
		cin >> displayPile;
		displayPile = toupper(displayPile);
		cin.ignore();

		if (displayPile == 'Y')
		{
			game->printLoserPile();

			cout << endl << "-----------------------------------------------------------------------------" << endl;
			cout << "Thank you for playing! Goodbye." << endl;
			cout <<  "-----------------------------------------------------------------------------" << endl;
		}
		else if (displayPile == 'N')
		{
			cout << endl << "-----------------------------------------------------------------------------" << endl;
			cout << "Thank you for playing! Goodbye." << endl;
			cout << "-----------------------------------------------------------------------------" << endl;
		}
		else if (displayPile != 'Y' && displayPile != 'N')
		{
			cout << "Invalid choice. Try again." << endl;
		}

	} while (displayPile != 'Y' && displayPile != 'N');
}