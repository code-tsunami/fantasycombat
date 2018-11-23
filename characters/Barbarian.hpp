/*********************************************************************
** Program name: Barbarian.hpp
** Author: Sonam D. Kindy
** Date: 11/11/17
** Description: This file is the Barbarian subclass specification/interface.
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character
{
    public:
        // declare constructors
        Barbarian(std::string);
        // declare member functions, set/get
        void defense(int);
        ~Barbarian();
};

#endif
