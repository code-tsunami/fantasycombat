/********************************************************************* 
** Program name: Stack.cpp
** Author: Sonam D. Kindy 
** Date: 11/11/17
** Description: This file contains the Stack class implementation 
** wherein each Stack object has data members of the top and bottom
** that are pointers to the first and last Node object in the doubly linked
** list. The member functions included allow adding to a new Node object to
** top, traversing the stack from top to bottom. There is also a destructor 
** that frees all memory dynamically allocated to Node objects created.
*********************************************************************/ 

#include "Stack.hpp"
#include <iostream>

/*********************************************************************
** Description: This member function sets the data member top. That is,
** a pointer to a dynamically created Node object is assigned to the
** top. If there is an existing top, then the new top Node next pointer 
** is set to the prev top and the prev pointer is set to null, signifying 
** that the new Node is the new top. The previous top's prev pointer is 
** set to the new top Node. If there is no existing top, then the bottom
** pointer is set to new bottom Node and the new top Node.
*********************************************************************/ 
void Stack::push(Character* player)
{
    Node* newTop = new Node(player);
    if (top) { // top already points to a Node object
        newTop->setNext(top);
        newTop->setPrev(nullptr);
        top->setPrev(newTop);
    } else { // top points to null; does not point to a Node object yet
        bottom = newTop; 
    }
    top = newTop;
}

/*********************************************************************
** Description: This member function traverses the linked list and prints
** the nodes from the front of the linked list to the back (top to bottom)
** as long as there is a top, i.e. head points to a Node object/list is 
** not empty. 
*********************************************************************/ 
void Stack::traverseList() const
{
    if (!top) {
        std::cout << EMPTY_LIST;
    }
    Node* ptr = top;
    while(ptr) {
        printHeader(ptr->getMember()->getType() + SPACE + 
                    ptr->getMember()->getName());
        ptr = ptr->getNext();
    }
    std::cout << std::endl;
}

/*********************************************************************
** Description: This deconstructor frees the memory allocated to create
** the pointers to the dynamically created Node objects starting with the
** second Node object to the bottom, ending with the top. That is, if the
** top points to a Node object, a temp Node object is initialized that
** contains the next Node pointer. While there is a next Node pointed to,
** top's next pointer is updated to the next-next Node object pointed to 
** upon each iteration and the temp pointer containing the next Node object
** is deleted (the memory allocated to it is freed). Finally, the memory 
** allocated to the top is freed.
*********************************************************************/ 
Stack::~Stack()
{
    if (top) {
        Node* ptr = top->getNext();
        while (ptr) {
            top->setNext(ptr->getNext());
            delete ptr->getMember();
            delete ptr;
            ptr = top->getNext();
        }
        delete top->getMember();
        delete top;
    }
}
