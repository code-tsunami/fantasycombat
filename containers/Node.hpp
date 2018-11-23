/********************************************************************* 
** Program name: Node.hpp
** Author: Sonam D. Kindy 
** Date: 11/11/17
** Description: This file is the Node class specification/interface. 
*********************************************************************/ 

#ifndef NODE_HPP
#define NODE_HPP

#include "../characters/Character.hpp"

class Node
{
    private:
        // declare member variables
        Character* player;
        Node* prev;
        Node* next;
    public:
        // declare constructors
        Node(Character* p) : player(p), prev(nullptr), next(nullptr) {}
        // declare member functions, set/get
        void setNext(Node*);
        void setPrev(Node*);
        Character* getMember();
        Node* getNext() const;
        Node* getPrev() const;
};

#endif
