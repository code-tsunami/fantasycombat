/*********************************************************************
** Program name: Barbarian.cpp
** Author: Sonam D. Kindy
** Date: 10/28/17
** Description: This file contains the Barbarian class implementation
** wherein each Barbarian object inherits all of the data members,
** public methods, as well as access to the protected data member of 
** attackDie and defenseDie in order to initialize them and free memory
** allocated to them within the class given that Character is an abstract
** base class. The pure virtual defense method inherited from the super 
** class Character is defined in this derived class definition.  
*********************************************************************/

#include "Barbarian.hpp"

/*********************************************************************
** Description: This constructor initializes a Barbarian object calling
** the base class constructor with its type (string), armor (int), and
** strength points (int) and within the definition initializes pointers
** to dynamically created Die objects for the attack and defense die.
*********************************************************************/
Barbarian::Barbarian(std::string nameStr) : Character(nameStr, "Barbarian", 0, 12) // armor: 0, strength: 12
{
    attackDie = new Die(2, 6);  // 2d6
    defenseDie = new Die(2, 6); // 2d6
}

/*********************************************************************
** Description: This member function takes as a parameter enemyAttack (int)
** sets the defense roll data member by calling the setDefenseRoll method,
** sets damage based on the difference of enemyAttack and defense roll and
** armor. Then the updateStrength method is called to update the data member
** strength based on the actual damage inflicted.
*********************************************************************/
void Barbarian::defense(int enemyAttack)
{
    setDefenseRoll(defenseDie->rollDice());
    setDamage(enemyAttack - getDefenseRoll() - getArmor());
    updateStrength();
}

/*********************************************************************
** Description: This destructor frees the memory allocated to dynamically
** create a pointer to a Die object for the attackDie and defenseDie data
** members.
*********************************************************************/
Barbarian::~Barbarian()
{
    delete attackDie;
    delete defenseDie;
}
