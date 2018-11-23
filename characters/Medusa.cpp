/*********************************************************************
** Program name: Medusa.cpp
** Author: Sonam D. Kindy
** Date: 10/28/17
** Description: This file contains the Medusa class implementation
** wherein each Medusa object inherits all of the data members,
** public methods, as well as access to the protected data member of 
** attackDie and defenseDie in order to initialize them and free memory
** allocated to them within the class given that Character is an abstract
** base class. The attack member function of the base class Character
** is overriden/redefined. The pure virtual defense method inherited from
** the super class Character is defined in this derived class definition.  
*********************************************************************/

#include "Medusa.hpp"

/*********************************************************************
** Description: This constructor initializes a Medusa object calling
** the base class constructor with its type (string), armor (int), and
** strength points (int) and within the definition initializes pointers
** to dynamically created Die objects for the attack and defense die.
*********************************************************************/
Medusa::Medusa(std::string nameStr) : Character(nameStr, "Medusa", 3, 8) // armor: 3, strength: 8
{
    attackDie = new Die(2, 6);  // 2d6
    defenseDie = new Die(1, 6); // 1d6
}

/*********************************************************************
** Description: This member function overrides the base class Character
** attack function to account for Medusa's 'glare', i.e. if a Medusa
** rolls 12 when attacking, then the target instantly gets turned into
** stone, and Medusa wins! That is, Medusa will win by returning the
** the integer maximum, guaranteed to trump any defensive roll and armor. 
** Otherwise, if Medusa does not roll a 12, then Medusa will return the
** value of the roll.
** Note that if Medusa uses Glare on Harry Potter on his first life,
** then Harry Potter will come back to life (not remain stone/dead).
*********************************************************************/
int Medusa::attack()
{
    setAttackRoll(attackDie->rollDice()); // roll and set attack roll

    if (getAttackRoll() == GLARE_ACTIVATED) { // if roll == 12
        printHeader("Medusa glare activated. Target is turned to stone!\n");
        setAttackRoll(KILL); // glare produces fatal blow (set to INT_MAX)
        return KILL;         // return INT_MAX
    }
    return getAttackRoll();  // else glare not activated; return roll
}

/*********************************************************************
** Description: This member function takes as a parameter enemyAttack (int)
** sets the defense roll data member by calling the setDefenseRoll method,
** sets damage based on the difference of enemyAttack and defense roll and
** armor. Then the updateStrength method is called to update the data member
** strength based on the actual damage inflicted.
*********************************************************************/
void Medusa::defense(int enemyAttack)
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
Medusa::~Medusa()
{
    delete attackDie;
    delete defenseDie;
}
