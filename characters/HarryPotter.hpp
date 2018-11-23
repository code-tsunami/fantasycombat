/*********************************************************************
** Program name: HarryPotter.hpp
** Author: Sonam D. Kindy
** Date: 10/28/17
** Description: This file is the HarryPotter subclass specification/interface.
*********************************************************************/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character
{
    private:
        // declare member variables
        bool hogwartsUsed;
    public:
        // declare constructors
        HarryPotter(std::string);
        // declare member functions, set/get
        void defense(int);
        ~HarryPotter();
};

#endif
