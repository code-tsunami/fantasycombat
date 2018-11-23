/*********************************************************************
** Program name: HarryPotter.cpp
** Author: Sonam D. Kindy
** Date: 10/28/17
** Description: This file contains the HarryPotter class implementation
** wherein each HarryPotter object inherits all of the data members,
** public methods, as well as access to the protected data member of
** attackDie and defenseDie in order to initialize them and free memory
** allocated to them within the class given that Character is an abstract
** base class. The defense member function of the base class Character
** is defined and there exists an additional data member unique to the 
** derived class to track if hogwarts was used.
*********************************************************************/

#include "HarryPotter.hpp"

/*********************************************************************
** Description: This constructor initializes a HarryPotter object calling
** the base class constructor with its type (string), armor (int), and
** strength points (int) and within the definition initializes pointers
** to dynamically created Die objects for the attack and defense die.
*********************************************************************/
HarryPotter::HarryPotter(std::string nameStr) : Character(nameStr, "Harry Potter", 0, 10) // armor: 0, strength: 10
{
    attackDie = new Die(2, 6);  // 2 dice 6-sided
    defenseDie = new Die(2, 6); // 2 dice 6-sided
    hogwartsUsed = false;       // Hogwarts can only be used to resurrect once
}

/*********************************************************************
** Description: This member function overrides the base class, Character's
** definition of the defense method. That is, if Harry Potter's strength
** reaches 0 or below, he immediately recovers and his total strength
** becomes 20. If he were to die again, then he actually dies.
*********************************************************************/
void HarryPotter::defense(int enemyAttack)
{
    setDefenseRoll(defenseDie->rollDice());
    setDamage(enemyAttack - getDefenseRoll() - getArmor());
    updateStrength();

    if (!(getStrength()) && !hogwartsUsed) {
        printHeader("Harry Potter used Hogwarts. He is resurrected!\n");
        updateStrength(20); // after using Hogwarts, HP strength is 20
        hogwartsUsed = true;
    }
}

/*********************************************************************
** Description: This destructor frees the memory allocated to dynamically
** create a pointer to a Die object for the attackDie and defenseDie data
** members.
*********************************************************************/
HarryPotter::~HarryPotter()
{
    delete attackDie;
    delete defenseDie;
}
