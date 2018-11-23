/*********************************************************************
** Program name: main.cpp
** Author: Sonam D. Kindy
** Date: 11/11/17
** Description: This program initiliazes a main menu with the items play
** and exit. If the option play is selected, then the function startGame
** defined in getUserInfo.cpp is called to gather user input to start
** the tournament/game.
*********************************************************************/

#include "game/Menu.hpp"

int main()
{
    Menu * menu = new Menu;
    menu->addItem("Play");
    menu->addItem("Exit");
    
    menu->prompt();

    delete menu;

    return 0;
}
