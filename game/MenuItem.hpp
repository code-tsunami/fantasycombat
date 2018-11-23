/*********************************************************************
** Program name: MenuItem.hpp
** Author: Sonam D. Kindy
** Date: 10/3/17
** Description: This file is the MenuItem class specification/interface.
*********************************************************************/

#ifndef MENU_ITEM_HPP
#define MENU_ITEM_HPP

#include <string>
#include "../utilities/utilities.hpp"
#include "../constants/constants.hpp"

class MenuItem
{
    private:
        // declare member variables
        std::string descrip;
        void (*fPtr)();
    public:
        // declare constructors
        MenuItem(const std::string, void (*pFunc)() = nullptr);
        // declare member functions, set/get
        void call();
        std::string getDescription();
};

#endif
