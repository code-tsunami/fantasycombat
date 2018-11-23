/********************************************************************* 
** Program name: Stack.hpp
** Author: Sonam D. Kindy 
** Date: 11/11/17
** Description: This file is the Stack class specification/interface. 
*********************************************************************/ 

#ifndef STACK_HPP
#define STACK_HPP

#include "Node.hpp"
#include "../constants/constants.hpp"

class Stack
{
    private:
        // declare member variables
        Node* top;
        Node* bottom;
    public:
        // declare constructors
        Stack() : top(nullptr), bottom(nullptr) {}
        // declare member functions, set/get
        void push(Character*);
        void traverseList() const;
        ~Stack();
};

#endif
