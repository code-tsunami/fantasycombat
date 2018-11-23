/*********************************************************************
** Program name: Die.hpp
** Author: Sonam D. Kindy
** Date: 10/12/17
** Description: This file is the Die class specification/interface.
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <random>

class Die
{
    private:
        // declare member variables
        int numDies;
        int numSides;
        std::random_device randDev;
    public:
        // declare constructors
        Die(int nDies, int nSides) : numDies(nDies), numSides(nSides) {}
        // declare member functions, set/get
        int getNumSides() const;
        int getNumDies() const;
        int rollDice();
        ~Die() {}
};

#endif
