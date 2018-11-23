/*********************************************************************
** Program name: BlueMen.hpp
** Author: Sonam D. Kindy
** Date: 10/28/17
** Description: This file is the BlueMen subclass specification/interface.
*********************************************************************/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "Character.hpp"

class BlueMen : public Character
{
    public:
        // declare constructors
        BlueMen(std::string);
        // declare member functions, set/get
        void detNumDefenseDie();
        virtual void defense(int);
        ~BlueMen();
};

#endif
