/********************************************************************* 
** Program name: Queue.cpp
** Author: Sonam D. Kindy 
** Date: 11/11/17
** Description: This file contains the Queue class implementation wherein 
** each Queue object has a single data members of the head that is a pointer
** to the first QueueNode object in the circular linked list data structure, 
** specifically a queue. The member functions included allow adding a new 
** QueueNode object to back of the queue, deleting the first QueueNode object, 
** getting the Character pointer contained in the front node of the queue, 
** and checking if the queue is empty. There is also a destructor that frees 
** all memory dynamically allocated to QueueNode objects created.
*********************************************************************/ 

#include "Queue.hpp"

/*********************************************************************
** Description: This member function takes a user-inputted integer (passed
** as a parameter), creates a QueueNode with user-inputted integer, and 
** appends it to the back of the queue.
*********************************************************************/ 
void Queue::addBack(Character* mem)
{
    QueueNode* newBack = new QueueNode(mem);
    if (isEmpty()) { 
        head = newBack; 
        head->prev = newBack;
        head->next = newBack;
    } else { // head already points to a QueueNode object
        newBack->prev = head->prev;
        newBack->next = head;
        head->prev->next = newBack;
        head->prev = newBack;
    }
}

/*********************************************************************
** Description: This member function removes the front QueueNode of the 
** queue and frees the memory. 
*********************************************************************/ 
void Queue::removeFront()
{
    if (isEmpty()) {
        std::cout << "\nQueue is empty. No front to remove!\n";
    } else { // head already points to a QueueNode object
        QueueNode* nextNode = head->next;
        if (nextNode != head) {
            nextNode->prev = head->prev;
            head->prev->next = nextNode;
            if (nextNode->next == head) {
                nextNode->next = nextNode;
            }
            delete head;
            head = nextNode;
        } else {
            delete head;
            head = nullptr;
        }
    }
}

/*********************************************************************
** Description: This member function checks if the queue is empty first, 
** and if it is, it displays a message stating so and returns nullptr, 
** signifying no nodes exist and therefore the Character pointer returned
** should be nullptr. Otherwise, it returns pointer to the Character object
** contained the node at the front of the queue.
*********************************************************************/ 
Character* Queue::getFront()
{
    if (isEmpty()) {
        return nullptr;
    } else {
        return head->member;
    }
}

/*********************************************************************
** Description: This member function checks if the head is pointing
** to null, i.e. no node exists in the queue. If so, it returns true; 
** otherwise, it returns false. 
*********************************************************************/ 
bool Queue::isEmpty() const
{
    return (!head);
}

/*********************************************************************
** Description: This deconstructor frees the memory allocated to create
** the pointers to the dynamically created QueueNode objects starting with the
** second QueueNode object to the tail, ending with the head. That is, if the
** head points to a QueueNode object, a temp Node object is initialized that
** contains the next QueueNode pointer. While there is a next Node pointed to,
** head's next pointer is updated to the next-next QueueNode object pointed to 
** upon each iteration and the temp pointer containing the next QueueNode object
** is deleted (the memory allocated to it is freed). The memory allocated to the
** Character object pointed to that is contained in the node is also freed. 
** Finally, the memory allocated to the head along with the Character object 
** pointed to that is contained in the node is freed.
*********************************************************************/ 
Queue::~Queue()
{
    if (!isEmpty()) { // if list is not empty
        QueueNode* ptr = head->next;
        while (ptr != head) {
            head->next = ptr->next;
            delete ptr->member;
            delete ptr;
            ptr = head->next;
        }
        delete head->member;
        delete head;
    }
}
