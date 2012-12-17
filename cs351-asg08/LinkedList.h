/*******************************************************
 * by Jeremy Villegas
 * CS 351 Fall 07
 * Assignment #8
 * 
 * Purpose: Header file for LinkedQueue.h. This inherits
            LinkedQueue, therefore LinkedQueue.h is
            required.
 *
 ******************************************************/

#include "LinkedQueue.h"

class LinkedList : public LinkedQueue {
  public:
    void addFront(el_t);
    void deleteRear(el_t &OldNum);
    int search(el_t &Key);
    void deleteIth(int I, el_t &OldNum);
    void deleteAll();
};


