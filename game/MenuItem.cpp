/*********************************************************************
** Program name: MenuItem.cpp
** Author: Sonam D. Kindy
** Date: 10/3/17
** Description: This program is the MenuItem class implementation file
** wherein each Menu object contains a constructor that takes three
** parameters for its description, a pointer to another class's member
** function, and a pointer to an instantiation of that class. It also
** contains its own member functions to call the given class's member
** function via the pointer to it and the pointer to one of its objects.
*********************************************************************/

#include "MenuItem.hpp"

/*********************************************************************
** Description: This constructor initializes a MenuItem object's data
** members of string description, object pointer and function pointer
** to the given parameters.
*********************************************************************/
MenuItem::MenuItem(const std::string d, void (*pFunc)())
{
    descrip = d;
    fPtr = pFunc;
}

/*********************************************************************
** Description: This member function dereferences the function pointer
** and invokes the function pointed to, i.e. calls the function pointed
** to.
*********************************************************************/
void MenuItem::call()
{
    (*fPtr)();
}

/*********************************************************************
** Description: This member function returns the string data member
** called description.
*********************************************************************/
std::string MenuItem::getDescription()
{
    return descrip;
}
