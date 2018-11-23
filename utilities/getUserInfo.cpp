/*********************************************************************
** Program name: getUserInfo.cpp
** Author: Sonam D. Kindy
** Date: 10/28/17
** Description: This function takes as parameters two ints representing the
** number of characters/teams to be on each team, and using a while loop and
** switch statement, gathers the selection for each character on the team, asks
** for the name to use to refer to each character, and forms the queues for both
** teams. It then dynamically creates a game object, passing the parameters of
** the created teams and initiates the gameplay. 
*********************************************************************/

#include "getUserInfo.hpp"

/*********************************************************************
** Description: This function takes as parameters two ints representing the
** number of characters/teams to be on each team, and using two separate for
** statements given the parameter values, calls the submenu Menu class prompt
** member function to display the menu options, gather input and return the result
** of the function call to createPlayer, i.e. a Character pointer to a dynamically
** allocated derived class object. Each of the character pointers are added to the
** back of the dynamically allocated Queue object, forming the queues for both
** teams.It then dynamically creates a game object, passing the parameters of
** the team queues and initiates the gameplay by calling the play member function
** of the Game class. 
*********************************************************************/
void startGame(int teamASize, int teamBSize)
{
    Menu * submenu = new Menu;
    submenu->addItem("Barbarian");
    submenu->addItem("Blue Men");
    submenu->addItem("Vampire");
    submenu->addItem("Medusa");
    submenu->addItem("Harry Potter");

    Queue* teamA = new Queue;
    Queue* teamB = new Queue;
    
    printBorder(WAVE);
    printHeader("SELECT EVERY PLAYER FOR TEAM A");
    for(int i = 0; i < teamASize; i++) {
        teamA->addBack(submenu->prompt(i + 1));
    }

    printBorder(WAVE);
    printHeader("SELECT EVERY PLAYER FOR TEAM B");
    for (int i = 0; i < teamBSize; i++) {
        teamB->addBack(submenu->prompt(i + 1));
    }

    Game * game = new Game(teamA, teamB);
    game->play();

    delete teamA;
    delete teamB;
    delete game;
    delete submenu;
}

/*********************************************************************
** Description: This function takes as a parameter the input option selected,
** and using the switch statement returns the corresponding dynamically allocated
** derived class object. The return type is the base class Character pointer,
** which is returned to the calling function startGame above, which is used
** to add a node containing the Character pointer to the back of the respective
** team queue.
*********************************************************************/
Character* createPlayer(int playerSelected) {
    std::cout << "\nEnter name for player: ";
    std::string name = getStr();
    std::cout << std::endl;

    switch(playerSelected) {
        case 1:
            return new Barbarian(name);
            break;
        case 2:
            return new BlueMen(name);
            break;
        case 3:
            return new Vampire(name);
            break;
        case 4:
            return new Medusa(name);
            break;
        default: // case 5
            return new HarryPotter(name);
            break;
    }
}
