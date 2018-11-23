/*********************************************************************
** Program name: Die.cpp
** Author: Sonam D. Kindy
** Date: 10/12/17
** Description: This program is the Die class function implementation
** file wherein each Die object has an int data member that represents
** the number of sides of the dice as well as member functions to roll
** the dice and to get the value for the number of sides.
*********************************************************************/

#include "Die.hpp"

/*********************************************************************
** Description: This member function returns the number of sides.
*********************************************************************/
int Die::getNumSides() const
{
    return numSides;
}

/*********************************************************************
** Description: This member function returns the number of dies.
*********************************************************************/
int Die::getNumDies() const
{
    return numDies;
}

/*********************************************************************
** Description: This member function generates a random number between
** 1 and the value for the number of sides plus 1, i.e. 1 through the
** the number of sides.
*********************************************************************/
int Die::rollDice()
{
    const int rangeFrom = 1,
              rangeTo = getNumSides();
    std::mt19937 generator(randDev());
    std::uniform_int_distribution<int> distribution(rangeFrom, rangeTo);

    int sumOfRolls = 0;

    for (int i = 0; i < getNumDies(); i++) {
        sumOfRolls += distribution(generator); 
    }

    return sumOfRolls;
}
