/*********************************************************************
** Program name: Medusa.hpp
** Author: Sonam D. Kindy
** Date: 11/11/17
** Description: This file is the Medusa subclass specification/interface.
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character
{
    public:
        // declare constructors
        Medusa(std::string);
        // declare member functions, set/get
        void defense(int);
        virtual int attack();
        ~Medusa();
};

#endif
