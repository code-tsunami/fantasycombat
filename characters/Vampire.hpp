/*********************************************************************
** Program name: Vampire.hpp
** Author: Sonam D. Kindy
** Date: 10/28/17
** Description: This file is the Vampire class specification/interface.
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character
{
    private:
        Die * charmDie;
    public:
        // declare constructors
        Vampire(std::string);
        // declare member functions, set/get
        virtual void defense(int);
        ~Vampire();
};

#endif
