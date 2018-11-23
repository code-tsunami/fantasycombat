/*********************************************************************
** Program name: BlueMen.cpp
** Author: Sonam D. Kindy
** Date: 11/11/17
** Description: This file contains the BlueMen class implementation
** wherein each BlueMen object inherits all of the data members,
** public methods, as well as access to the protected data member of 
** attackDie and defenseDie in order to initialize them and free memory
** allocated to them within the class given that Character is an abstract
** base class. The defense member function of the base class Character
** is defined and there exists a helper function to determine the number 
** of defense die that the BlueMen should have based on their strength.
*********************************************************************/

#include "BlueMen.hpp"

/*********************************************************************
** Description: This constructor initializes a BlueMen object calling
** the base class constructor with its type (string), armor (int), and
** strength points (int) and within the definition initializes pointers
** to dynamically created Die objects for the attack and defense die.
*********************************************************************/
BlueMen::BlueMen(std::string nameStr) : Character(nameStr, "Blue Men", 3, 12) // armor: 3, strength: 12
{
    attackDie = new Die(2, 10); // 2d10
    defenseDie = new Die(3, 6); // 3d6
}

/*********************************************************************
** Description: This member function overrides the base class, Character's
** definition of the defense method. For every 4 points of damage taken,
** one defense die is lost (which is handled in the call to the detNumDefenseDie
** member function). For every enemy attack made, the damage for the round 
** is calculated by taking the enemy attack and subtracting the roll(s) the
** Blue Men objects' defense die and armor.
*********************************************************************/
void BlueMen::defense(int enemyAttack)
{
    detNumDefenseDie();
    setDefenseRoll(defenseDie->rollDice());
    setDamage(enemyAttack - getDefenseRoll() - getArmor());
    updateStrength();
}

/*********************************************************************
** Description: This member function determines how many defense die
** the BlueMen object should have based on the current value of strength.
** If the BlueMen won the previous battle and recovered strength to 9 or 
** more, then they should recover all defense die. Otherwise, for every 4
** points of damage taken, one defense die is lost. If round starts with 
** strength at 3, then the number of defense die should be 1.
*********************************************************************/
void BlueMen::detNumDefenseDie()
{
    if (getStrength() > 8 && defenseDie->getNumDies() != 3) {
        delete defenseDie;
        Die * tempDie = new Die(3,6);
        defenseDie = tempDie;
    }

    if (getStrength() <= 4 && defenseDie->getNumDies() > 1) {
        delete defenseDie;
        Die * tempDie = new Die(1, 6);
        defenseDie = tempDie;
        printHeader("Only 1 member of the BlueMen mob remains. Defense lowered.\n");
    } else if (getStrength() <= 8 && defenseDie->getNumDies() > 1) {
        delete defenseDie;
        Die * tempDie = new Die(2, 6);
        defenseDie = tempDie;
        printHeader("Only 2 members of the BlueMen mob remains. Defense lowered.\n");
    }
}

/*********************************************************************
** Description: This destructor frees the memory allocated to dynamically
** create a pointer to a Die object for the attackDie and defenseDie data
** members.
*********************************************************************/
BlueMen::~BlueMen()
{
    delete attackDie;
    delete defenseDie;
}
