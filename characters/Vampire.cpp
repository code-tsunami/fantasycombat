/*********************************************************************
** Program name: Vampire.cpp
** Author: Sonam D. Kindy
** Date: 10/28/17
** Description: This file contains the Vampire class implementation
** wherein each Vampire object inherits all of the data members,
** public methods, as well as access to the protected data member of 
** attackDie and defenseDie in order to initialize them and free memory
** allocated to them within the class given that Character is an abstract
** base class. The pure virutal defense member function inherited from the
** super class Character is defined in this class definition.
*********************************************************************/

#include "Vampire.hpp"

/*********************************************************************
** Description: This constructor initializes a Vampire object calling
** the base class constructor with its type (string), armor (int), and
** strength points (int) and within the definition initializes pointers
** to dynamically created Die objects for the attack, defense and charm.
*********************************************************************/
Vampire::Vampire(std::string nameStr) : Character(nameStr, "Vampire", 1, 18) // armor: 1, strength: 18
{
    attackDie = new Die(1, 12); // 1d12
    defenseDie = new Die(1, 6); // 2d6
    charmDie = new Die(1,2);    // 1d2
}

/*********************************************************************
** Description: This member function overrides the base class Character's
** definition of the defense function to account for the vampire's 'charm',
** the 50% chance that opponent does not actually attack the vampire, so
** randomly generate number between 0 and 1, if number is 1, calculate
** damage inflicted by attack after accounting for defense and armor;
** else do not (leave vampire strength as is, i.e as if not attacked).
*********************************************************************/
void Vampire::defense(int enemyAttack)
{
    setDefenseRoll(defenseDie->rollDice());

    if (charmDie->rollDice() - 1) { // if roll - 1 == 1
        printHeader("Vampire charm activated. Attacker did not attack!\n");
        setDamage(0);
    } else { // else roll - 1 == 0
        setDamage(enemyAttack - getDefenseRoll() - getArmor());
        updateStrength();
    }
}

/*********************************************************************
** Description: This destructor frees the memory allocated to dynamically
** create a pointer to a Die object for the attackDie, defenseDie and 
** charmDie data members.
*********************************************************************/
Vampire::~Vampire()
{
    delete attackDie;
    delete defenseDie;
    delete charmDie;
}
