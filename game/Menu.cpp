/*********************************************************************
** Program name: Menu.cpp
** Author: Sonam D. Kindy
** Date: 10/3/17
** Description: This is the Menu class definition file wherein each
** Menu object contains the data members of a vector containing
** MenuItem objects and an int that represents the number of times the
** user has been prompted with the menu and selected to start the
** given program.
*********************************************************************/

#include "Menu.hpp"
#include "MenuItem.hpp"
#include <iostream>
#include <iomanip>

/*********************************************************************
** Description: This member function initializes a MenuItem object using
** the given parameters of a string description of the item, a pointer to
** the specific object's data member function to be called if that item
** is selected by the user, and a pointer to the actual object.
** The MenuItem is then appended to the vector data member called menuList.
*********************************************************************/
void Menu::addItem(const std::string d, void (*pFunc)())
{
    MenuItem *item = new MenuItem(d, pFunc);
    menuList.emplace_back(item);
}

/*********************************************************************
** Description: This member function takes as a parameter the number
** that the user has input as their selection from the menu items and
** calls the member function.
*********************************************************************/
void Menu::callMenuItem(int option)
{
    menuList.at(option - 1)->call();
}

/*********************************************************************
** Description: This member function prompts the user for their selection
** from the main menu items until the option selected is to quit. It also
** outputs a goodbye message if the option selected is to quit and an error
** message if the option input is invalid.
*********************************************************************/
void Menu::prompt()
{
    int input,
        input2;
    do {
        // starting with the first iteration and thereafter every even interation,
        // display the menu options of play (again)/exit
        if ( iteration % 2 == 0 ) {
            display();
        }
        // if the iteration is even, then given the generic prompt to enter
        // selection [0,1]
        if (iteration % 2 == 0) {
            std::cout << GENERIC_PROMPT;
            input = getInt(menuList.size(), 1);
            if (input == optionToQuit())
                printHeader(GOODBYE, WAVE);
        } else { 
            // else the prompts should ask for the number of players on each team,
            // i.e., it is given that the player selected to play the previous 
            // iteration
            std::cout << "\nPlease enter the number of players on Team A (1 to 100): ";
            input = getInt(100,1); 
            std::cout << "\nPlease enter the number of players on Team B (1 to 100): ";
            input2 = getInt(100,1); 
            startGame(input, input2);
            input = input2 = 0; // reset to zero so loop continues
        } 
        iteration++;
    } while(input != optionToQuit());
}

/*********************************************************************
** Description: This member function prompts the user for their selection
** from the submenu items. 
*********************************************************************/
Character* Menu::prompt(int playerNum)
{
    display();      // display the character options
    std::cout << "\nEnter your selection for player " << playerNum << ": ";
    int input = getInt(menuList.size(), 1);
    return createPlayer(input); // return the character pointer to the calling 
                                // function
}

/*********************************************************************
** Description: This member function displays the items for the user
** to select from. If the user has already gone through one iteration
** of the program, the description output for that is to play again
** (instead of simply play).
*********************************************************************/
void Menu::display()
{
    if (!iteration && menuList.size() <= 2) {
        printBorder(WAVE);
        printHeader(INTRO);
    }
    printBorder(WAVE);
    printHeader(MENU);

    std::string description,
                tabs;
    for(size_t i = 0; i < menuList.size(); i++) {
        description = menuList.at(i)->getDescription();
        if (iteration && description == "Play")
            description = "Play again";
        tabs.assign(5, '\t');
        std::cout << tabs << "[" << (i + 1) << "] ";
        std::cout << description << std::endl << std::endl;
    }

    printBorder(WAVE);
}

/*********************************************************************
** Description: This member function returns the index of the option
** to quit out of/exit the menu prompt.
*********************************************************************/
int Menu::optionToQuit()
{
    for(size_t i = 0; i < menuList.size(); i++)
    {
        if (menuList.at(i)->getDescription() == "Quit" ||
            menuList.at(i)->getDescription() == "Exit") {
            return (i + 1);
        }
    }
    return -1;
}

/*********************************************************************
** Description: This destructor frees all memory allocated to the pointers
** to MenuItem objects in the menuList data member of the type vector.
*********************************************************************/
Menu::~Menu()
{
    for(size_t i = 0; i < menuList.size(); i++)
        delete menuList[i];
    menuList.clear();
}
