/********************************************************************* 
** Program name: Queue.hpp
** Author: Sonam D. Kindy 
** Date: 11/11/17
** Description: This file is the Queue class specification/interface. 
*********************************************************************/ 

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../characters/Character.hpp"
#include "../constants/constants.hpp"
#include <iostream>


class Queue
{
    private:
        // declare member variables
        struct QueueNode {
            Character* member;
            QueueNode* prev;
            QueueNode* next;
            QueueNode(Character* m) : member(m), prev(nullptr), next(nullptr) {}
        };
        QueueNode* head;
    public:
        // declare constructors
        Queue() : head(nullptr) {}
        // declare member functions, set/get
        bool isEmpty() const;
        Character* getFront();
        void addBack(Character*);
        void removeFront();
        ~Queue();
};

#endif
