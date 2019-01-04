/**************************************************************************************************************
** Program name: Project 4
** Author: Derrick Li
** Date: Mar. 5, 2017
** Description:
** This class implementation file contains the member function definitions for the Creature base class and its
** 5 derived classes--Vampire class, Barbarian class, BlueMen class, Medusa class, and HarryPotter class.
***************************************************************************************************************/

#include "Creature.hpp"

#include <iostream>

using std::endl;
using std::cout;
using std::cin;

/***************************************************************************************************************
** Description: The Creature base class constructor initializes its pointer members to nullptr, its int 
** members to zero, its type to ' ', and its name to an empty string.
***************************************************************************************************************/
Creature::Creature()
{
	attackDie = nullptr;
	defenseDie = nullptr;
	numOfAttackDie = 0;
	numOfDefenseDie = 0;
	armor = 0;
	strength = 0;
	creatureType = ' ';
	creatureName = "";
}

/***************************************************************************************************************
** Description: The Creature base class destructor frees the Die objects held by attackDie and defenseDie
** upon exiting of the program.
***************************************************************************************************************/
Creature::~Creature()
{
	delete attackDie;
	attackDie = nullptr;

	delete defenseDie;
	defenseDie = nullptr;
}

/***************************************************************************************************************
** Description: getStrength() function returns the strength data member as a int. It does not take in any argument.
***************************************************************************************************************/
int Creature::getStrength()
{
	return strength;
}

/***************************************************************************************************************
** Description: setStrength() function takes in an int and assigns it to the strength data member. It does not
** have a return type.
***************************************************************************************************************/
void Creature::setStrength(int inputStrength)
{
	strength = inputStrength;
}

/***************************************************************************************************************
** Description: getArmor() function returns the armor data member as a int. It does not take in any argument.
***************************************************************************************************************/
int Creature::getArmor()
{
	return armor;
}

/***************************************************************************************************************
** Description: getCreatureType() function returns the creature type as a char. It does not take any argument.
***************************************************************************************************************/
char Creature::getCreatureType()
{
	return creatureType;
}

/***************************************************************************************************************
** Description: getCreatureName() function returns the creature name as a string. It does not take any argument.
***************************************************************************************************************/
string Creature::getCreatureName()
{
	return creatureName;
}

/***************************************************************************************************************
** Description: setCreatureName() function takes a single string argument and sets the creatureName data
** member. The function does not have a return type.
***************************************************************************************************************/
void Creature::setCreatureName(string inputName)
{
	creatureName = inputName;
}

/***************************************************************************************************************
** Description: getNumOfSidesOnAttackDie() function returns the number of sides on the attack die as a int.
** It does not take in any argument.
***************************************************************************************************************/
int Creature::getNumOfSidesOnAttackDie()
{
	return attackDie->getSides();
}

/***************************************************************************************************************
** Description: getNumOfAttackDie() function returns the numOfAttackDie data member as a int. It does not take in any argument.
***************************************************************************************************************/
int Creature::getNumOfAttackDie()
{
	return numOfAttackDie;
}

/***************************************************************************************************************
** Description: getNumOfSidesOnDefenseDie() function returns the number of sides on the defense die as a int.
** It does not take in any argument.
***************************************************************************************************************/
int Creature::getNumOfSidesOnDefenseDie()
{
	return defenseDie->getSides();
}

/***************************************************************************************************************
** Description: getNumOfDefenseDie() function returns the numOfDefenseDie data member as a int. It does not take in any argument.
***************************************************************************************************************/
int Creature::getNumOfDefenseDie()
{
	return numOfDefenseDie;
}

/***************************************************************************************************************
** Description: attack() function rolls the attackDie by the number of times indicated by numOfAttackDie.
** The values of the rolls are summed up and returned from the function as an integer. It does not take in any argument.
***************************************************************************************************************/
int Creature::attack()
{
	int attackDamage = 0;

	for (int i = 0; i < numOfAttackDie; i++)
	{
		int tempAttack = attackDie->rollDie();
		//cout << "   Die " << i + 1 << ": " << tempAttack << " damage points rolled."<< endl;
		attackDamage += tempAttack;
	}

	return attackDamage;
}

/***************************************************************************************************************
** Description: defend() function rolls the defenseDie by the number of times indicated by numOfDefenseDie.
** The values of the rolls are summed up along with the armor value. This total represents creature's defense points. 
** The function takes an integer argument representing the damage the creature is being dealt. It takes the damage
** value and substract from it the defense points. If the results are positive, then that is the amount to subtract
** from the creature's strength. If the results are negative, then the defense points are higher than the damage
** being dealt, thus strength is unaffected. The function does not have a return type.
***************************************************************************************************************/
void Creature::defend(int damage)
{
	int defensePoints = armor;

	for (int i = 0; i < numOfDefenseDie; i++)
	{
		int tempDef = defenseDie->rollDie();
		defensePoints += tempDef;
		//cout << "   Die " << i + 1 << ": " << tempDef << " defense points rolled." << endl;
	}

	//cout << "   With armor, the defending player has " << defensePoints << " total defense points." << endl;

	if (defensePoints < damage)
	{
		strength -= (damage - defensePoints);
	}
}

/***************************************************************************************************************
** Description: recoverStrength() function regenerates a certain percentage of the damage inflicted on the creature.
** The creature will be regenerated a certain percent in consideration to its max strength. The default is 60%.
** This recovery value can be changed in the function. The function does not take an argument and
** does not have a return type. The function works for Vampire, Barbarian, BlueMen, and Medusa derived classes.
** HarryPotter has its own recoverStrength() function that overrides this.
***************************************************************************************************************/
void Creature::recoverStrength()
{
	const double RECOVERY_PERCENT = 0.6; //Default: 60% strength recovery from total damage inflicted
	
	const int VAMPIRE_MAX_STRENGTH = 18;
	const int BARBARIAN_MAX_STRENGTH = 12;
	const int BLUEMEN_MAX_STRENGTH = 12;
	const int MEDUSA_MAX_STRENGTH = 8;
	
	int creatureStrength = 0;

	switch (creatureType)
	{
	case 'v': creatureStrength = VAMPIRE_MAX_STRENGTH;
		break;
	case 'b': creatureStrength = BARBARIAN_MAX_STRENGTH;
		break;
	case 'x': creatureStrength = BLUEMEN_MAX_STRENGTH;
		break;
	case 'm': creatureStrength = MEDUSA_MAX_STRENGTH;
		break;
	}

	setStrength(getStrength() + (RECOVERY_PERCENT)*(creatureStrength - getStrength()));
}

/***************************************************************************************************************
** Description: The Vampire derived class constructor.
** Specifications:
**    Attack: 1 Die - 12 sides
**    Defense: 1 Die - 6 sides
**    Armor: 1
**    Strength: 18
**    Special ability: Charm
**	     When attacked, there is a 50% chance that the Vampire object doesn't receive any damage.
***************************************************************************************************************/
Vampire::Vampire(string inputName)
{
	attackDie = new Die(12);
	defenseDie = new Die(6);
	numOfAttackDie = 1;
	numOfDefenseDie = 1;
	armor = 1;
	strength = 18;

	creatureType = 'v';
	creatureName = inputName;
}

/***************************************************************************************************************
** Description: defend() function in Vampire derived class overrides the defend() function in the Base class.
** This version takes into account the Vampire's special ability, Charm.
***************************************************************************************************************/
void Vampire::defend(int damage)
{
	bool charm = rand() % 2;	//50% chance for charm

	if (charm)
	{
		//cout << "   Vampire successfully used Charm. No damage received!" << endl;
	}
	else
	{
		int defensePoints = armor;

		for (int i = 0; i < numOfDefenseDie; i++)
		{
			int tempDef = defenseDie->rollDie();
			defensePoints += tempDef;
			//cout << "   Die " << i + 1 << ": " << tempDef << " defense points rolled." << endl;
		}

		//cout << "   With armor, the defending player has " << defensePoints << " total defense points." << endl;

		if (defensePoints < damage)
		{
			strength -= (damage - defensePoints);
		}
	}
}

/***************************************************************************************************************
** Description: The Barbarian derived class constructor.
** Specifications:
**    Attack: 2 Die - 6 sides
**    Defense: 2 Die - 6 sides
**    Armor: 0
**    Strength: 12
**    Special ability: none.
***************************************************************************************************************/
Barbarian::Barbarian(string inputName)
{
	attackDie = new Die(6);
	defenseDie = new Die(6);
	numOfAttackDie = 2;
	numOfDefenseDie = 2;
	armor = 0;
	strength = 12;

	creatureType = 'b';
	creatureName = inputName;
}

/***************************************************************************************************************
** Description: The BlueMen derived class constructor.
** Specifications:
**    Attack: 2 Die - 10 sides
**    Defense: 3 Die - 6 sides
**    Armor: 3
**    Strength: 12
**    Special ability: Mob
**	     The defense starts off with 3 Dies. When strength drops to 8, the defense will only have 2 Dies.
**		 And when strength drops to 4, the defense will only have 1 Die.
***************************************************************************************************************/
BlueMen::BlueMen(string inputName)
{
	attackDie = new Die(10);
	defenseDie = new Die(6);
	numOfAttackDie = 2;
	numOfDefenseDie = 3;
	armor = 3;
	strength = 12;

	creatureType = 'x';
	creatureName = inputName;
}

/***************************************************************************************************************
** Description: defend() function in BlueMen derived class overrides the defend() function in the Base class.
** This version takes into account the BlueMen's special ability, Mob.
***************************************************************************************************************/
void BlueMen::defend(int damage)
{	
	//Code for Mob ability --- Moved from end of block to front to account for any recovered strength from recover function
	if (strength > 8)
	{
		numOfDefenseDie = 3;
		//cout << "   Blue Men's Mob Defense level is High (Lvl 3)." << endl;
	}
	else if (strength > 4)
	{
		numOfDefenseDie = 2;
		//cout << "   Blue Men's Mob Defense level is Mid (Lvl 2)." << endl;
	}
	else if (strength > 0)
	{
		numOfDefenseDie = 1;
		//cout << "   Blue Men's Mob Defense level is Low (Lvl 1)." << endl;
	}

	int defensePoints = armor;

	for (int i = 0; i < numOfDefenseDie; i++)
	{
		int tempDef = defenseDie->rollDie();
		defensePoints += tempDef;
		//cout << "   Die " << i + 1 << ": " << tempDef << " defense points rolled." << endl;
	}

	//cout << "   With armor, the defending player has " << defensePoints << " total defense points." << endl;

	if (defensePoints < damage)
	{
		strength -= (damage - defensePoints);
	}
}

/***************************************************************************************************************
** Description: The Medusa derived class constructor.
** Specifications:
**    Attack: 2 Die - 6 sides
**    Defense: 1 Die - 6 sides
**    Armor: 3
**    Strength: 8
**    Special ability: Glare
**	     When attaking, if it rolls an attack value of 12. Then the opponent immediately turns to stone and lose
**		 a life.
***************************************************************************************************************/
Medusa::Medusa(string inputName)
{
	attackDie = new Die(6);
	defenseDie = new Die(6);
	numOfAttackDie = 2;
	numOfDefenseDie = 1;
	armor = 3;
	strength = 8;

	creatureType = 'm';
	creatureName = inputName;
}

/***************************************************************************************************************
** Description: attack() function in Medusa derived class overrides the attack() function in the Base class.
** This version takes into account Medusa's special ability, Glare.
***************************************************************************************************************/
int Medusa::attack()
{
	int attackDamage = 0;

	for (int i = 0; i < numOfAttackDie; i++)
	{
		int tempAttack = attackDie->rollDie();
		//cout << "   Die " << i + 1 << ": " << tempAttack << " damage points rolled." << endl;
		attackDamage += tempAttack;
	}

	if (attackDamage == 12)
	{
		attackDamage = 9999;
		//cout << "   Medusa successfully used Glare. Opponent is turned to stone!" << endl;
	}

	return attackDamage;
}

/***************************************************************************************************************
** Description: The HarryPotter derived class constructor.
** Specifications:
**    Attack: 2 Die - 6 sides
**    Defense: 2 Die - 6 sides
**    Armor: 0
**    Strength: 10
**    Special ability: Hogwarts
**	      Has an extra life. Once strength decreases to zero or below, the character is automatically revived and strength is
**		 set to 20. This special ability is only able to be used one time.
***************************************************************************************************************/
HarryPotter::HarryPotter(string inputName)
{
	attackDie = new Die(6);
	defenseDie = new Die(6);
	numOfAttackDie = 2;
	numOfDefenseDie = 2;
	armor = 0;
	strength = 10;

	creatureType = 'h';
	creatureName = inputName;

	numOfExtraLives = 1;
}

/***************************************************************************************************************
** Description: defend() function in HarryPotter derived class overrides the defend() function in the Base class.
** This version takes into account Harry Potter's special ability, Hogwarts.
***************************************************************************************************************/
void HarryPotter::defend(int damage)
{
	int defensePoints = armor;

	for (int i = 0; i < numOfDefenseDie; i++)
	{
		int tempDef = defenseDie->rollDie();
		defensePoints += tempDef;
		//cout << "   Die " << i + 1 << ": " << tempDef << " defense points rolled." << endl;
	}

	//cout << "   With armor, the defending player has " << defensePoints << " total defense points." << endl;

	if (defensePoints < damage)
	{
		strength -= (damage - defensePoints);
	}

	//Code for Hogwarts ability
	if (strength <= 0 && numOfExtraLives > 0)
	{
		//cout << "   Harry Potter was knocked down. But he used Hogwarts and is revived with 20 strength points!." << endl;
		numOfExtraLives--;
		strength = 20;
	}
}

/***************************************************************************************************************
** Description: recoverStrength() function in HarryPotter derived class overrides the defend() function in the Base class.
** This version takes into account Harry Potter's special ability, Hogwarts. Depending on whether it has used its
** special ability, its max strength is either 10 or 20 points. A certain percentage of the total damage inflicted on
** the creature will be regenerated in consideration to its max strength. The default is 60%.
** This recovery value can be changed in the function. The function does not take an argument and
** does not have a return type.
***************************************************************************************************************/
void HarryPotter::recoverStrength()
{
	const double RECOVERY_PERCENT = 0.6; //Default: 60 % strength recovery from total damage inflicted

	const int HARRYPOTTER_MAX_STRENGTH_BEFORE_LIFE = 10;
	const int HARRYPOTTER_MAX_STRENGTH_AFTER_LIFE = 20;

	int creatureStrength = 0;

	switch (numOfExtraLives)
	{
	case 1: creatureStrength = HARRYPOTTER_MAX_STRENGTH_BEFORE_LIFE;
		break;
	case 0: creatureStrength = HARRYPOTTER_MAX_STRENGTH_AFTER_LIFE;
		break;
	}

	setStrength(getStrength() + (RECOVERY_PERCENT)*(creatureStrength - getStrength()));
}
