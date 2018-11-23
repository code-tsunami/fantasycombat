/*********************************************************************
** Program name: Menu.hpp
** Author: Sonam D. Kindy
** Date: 8/6/17
** Description: This file is the Menu class specification/interface.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include "MenuItem.hpp"
#include "../characters/Character.hpp"
#include "../utilities/getUserInfo.hpp"

class Menu
{
    private:
        // declare member variables
        std::vector<MenuItem*> menuList;
        int iteration;
    public:
        // declare constructors
        Menu() : iteration(0) {}
        // declare member functions, set/get
        void addItem(const std::string d, void (*pFunc)() = nullptr);
        void callMenuItem(int);
        void display();
        void prompt();
        Character* prompt(int);
        int optionToQuit();
        ~Menu();
};

#endif
