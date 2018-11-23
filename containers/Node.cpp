/********************************************************************* 
** Program name: Node.cpp
** Author: Sonam D. Kindy 
** Date: 11/11/17
** Description: This file contains the Node class implementation wherein 
** each Node object has data members of the pointer to a Character object
** contained in the node, a pointer to the next Node object in the data 
** structure and a pointer to the previous Node object "" as well as 
** member funcs to get the data members' values and set the values of 
** prev and next.
*********************************************************************/ 

#include "Node.hpp"

/*********************************************************************
** Description: This member function sets the data member prev, the 
** pointer to the previous node in the doubly linked list to the given
** parameter of a pointer to a Node object.
*********************************************************************/ 
void Node::setPrev(Node* p)
{
    prev = p;
}

/*********************************************************************
** Description: This member function sets the data member next, the 
** pointer to the next node in the doubly linked list to the given
** parameter of a pointer to a Node object.
*********************************************************************/ 
void Node::setNext(Node* n)
{
    next = n;
}

/*********************************************************************
** Description: This member function returns the value of member (Character*).
*********************************************************************/ 
Character* Node::getMember()
{
    return player;
}

/*********************************************************************
** Description: This member function returns the value of prev (Node*).
*********************************************************************/ 
Node* Node::getPrev() const
{
    return prev;
}

/*********************************************************************
** Description: This member function returns the value of next (Node*).
*********************************************************************/ 
Node* Node::getNext() const
{
    return next;
}
