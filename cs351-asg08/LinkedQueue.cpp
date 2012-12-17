/*******************************************************
 * by Jeremy Villegas
 * CS 351 Fall 07
 * Assignment #8
 * 
 * Purpose: Function definitions for linkedqueue.h
 *
 ******************************************************/

#include <iostream>
#include "LinkedQueue.h"

// Constructor
LinkedQueue::LinkedQueue() {
  Front=NULL;                             // Reset all the variables
  Rear=NULL;
  Count=0;
}

// DeConstructor
LinkedQueue::~LinkedQueue() {
  el_t e;   
  while(Front!=NULL)                      // Dump all the variables before deconstructing
    deleteFront(e);
}

// Add an element to the back
void LinkedQueue::addRear(el_t NewNum) {
  if(Count==MAX_SIZE){
    QueueError("List is full");
    return;
  }
  Node *p=new Node();                     // Allocate new node  
  p->node_data=NewNum;                    // Set the data for new node
  if(!isEmpty()) {                        // We empty?
    Rear->next=p;                         // No, so set last element to point to this one
    p->prev=Rear;                         // Make this element point to the old rear
    Rear=p;                               // Make this the new rear
  } else {  
    Front=p;                              // We're empty, so make this the front
    Rear=p;                               // ...and make this the rear
  }
  Count++;                                // Increment the count
}

// The wait is over, pop from queue
void LinkedQueue::deleteFront(el_t &OldNum) {
  Node *p=Front;
  if (Front==NULL) QueueError("Nothing to delete"); // If queue is empty, bail out
  else {                                            // Cheap error checking
    OldNum=Front->node_data;                        // Get data from deleted item before deleting
    p=Front->next;                                  // Move to next element
    delete(Front);                                  // Purge Front
    Front=p;                                        // Make the next element the new front
    Count--;                                        // Adjust counter
  }
}

// Is the queue empty
bool LinkedQueue::isEmpty() {
  return (Front==NULL);                         // Is there someone in line?
}

// Returns size of queue
int LinkedQueue::getSize() {
  return (isEmpty()?true:Count);                // Is it empty? Otherwise return the count
}

// Display the whole queue, no popping
void LinkedQueue::displayAll() {
  Node *p=Front;
  if (isEmpty()) QueueError("Queue is empty");  // Nothing in queue? bail out
  else {                                        // Cheap error checking
    do {
      std::cout<<p->node_data<<" ";             // Output the node_data
      p=p->next;                                // Advance to next element
    } while(p!=NULL);                           // We at the end?
  }
}

// Bail out
void LinkedQueue::QueueError(char *Mesg) {
  std::cout<<"ERROR: "<<Mesg<<"\n";                   // Just display error, don't exit
}

