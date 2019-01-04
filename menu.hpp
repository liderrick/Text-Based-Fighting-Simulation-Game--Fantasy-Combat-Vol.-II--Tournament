/**************************************************************************************************************
** Program name: Project 4
** Author: Derrick Li
** Date: Mar. 5, 2017
** Description:
** This header file contains various function prototypes for the menu-related functions, including a function
** that seeds the random number generator.
***************************************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "Tournament.hpp"
#include "Creature.hpp"

void setRandomSeed();
int mainMenu();
bool inputIntegerValidationV2(int &num);

int pickNumberOfFightersMenu(int player);
void chooseFighterMenu(int player, Creature ** dptr, int numOfFighters);

void printCreatureType(char tempCreatureType);

void displayPool(Creature ** dptr, int count);
void chooseLineUpMenu(int fighter, int numOfFighters, Creature **dptr, Tournament *game);

void promptDisplayLoserPile(Tournament *game);

#endif