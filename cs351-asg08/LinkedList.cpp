/*******************************************************
 * by Jeremy Villegas
 * CS 351 Fall 07
 * Assignment #8
 * 
 * Purpose: Function definitions for LinkedList.h
 *
 ******************************************************/

#include <iostream>
#include "LinkedList.h"

void LinkedList::addFront(el_t NewNum) {
  if(Count==MAX_SIZE) return;
  Node *p=new Node();                     // Allocate new node
  p->node_data=NewNum;                    // Set the data for new node
  if(!isEmpty()) {                        // We empty?
    Front->next=p;                        // No, so set last element to point to this one
    p->prev=Front;                        // Make this element point to the old rear
    Rear=p;                               // Make this the new rear
  } else {  
    Front=p;                              // We're empty, so make this the front
    Rear=p;                               // ...and make this the rear
  }
  Count++;                                // Increment the count
}

void LinkedList::deleteRear(el_t &OldNum) {
  Node *p=Rear;
  if (p==NULL) QueueError("Nothing to delete");     // If queue is empty, bail out
  else {                                            // Cheap error checking
    OldNum=Rear->node_data;                         // Get data from deleted item before deleting
    if (p->prev!=NULL) Rear=p->prev;                // Is there going to be a new Rear? Then Set it.
    else {
      Front=NULL;                                   // Reset the front and rear
      Rear=NULL;
    }
    delete(p);                                      // Now just delete p
    Count--;                                        // Adjust counter
  }
}

int LinkedList::search(el_t &Key) {
  Node *p=Front;
  if (p==NULL) QueueError("Nothing to delete");     // If queue is empty, bail out
  else 
    for(int x=1;p!=NULL;x++) {                      // Cycle through list, x is the index
      if (p->node_data==Key) return x;              // Found! Return LL index
      p=p->next;                                    // Not found, go to next item
    }  
    QueueError("Item not found. ");
    return 0;                                       // Not in this list
}

// Delete the Ith element from the list (I being from 1 - count)
void LinkedList::deleteIth(int I, el_t &OldNum) {
  Node *p=Front;  
  if (p==NULL) QueueError("Nothing to delete");     // If queue is empty, bail out
  else if (I>Count||I<1) QueueError("Invalid LL Index."); // Are we outside the bounds of the LL?
  else {
    for(int x=1;x<I;x++) p=p->next;                 // Cycle through list finding the Ith node

    /* At this point all the previous/next links need to be fixed before a purge happens */
    if(p->next==NULL&&p->prev==NULL)  {             // Is this the only elem in the list?
      Front=NULL;                                   // Then the list will be empty
      Rear=NULL;
    }
    else if(p->next==NULL) {                        // If this is the end, this must be Rear
      Rear = p->prev;                               // New Rear
      p->prev->next=NULL;                           // Set Previous to this new rear
    }
    else if (p->prev==NULL) {                       // This is the first element
      Front=p->next;                                // New Front
    }
    else {                                          // This element is somewhere in the middle
      p->prev->next=p->next;
      p->next->prev=p->prev;
    }
    OldNum=p->node_data;                            // Get node data before deleting
    delete(p);                                      // Delete it
    Count--;
  }
}

void LinkedList::deleteAll() {
  el_t e;
  while(Front!=NULL)                                // Dump the list, public function
    deleteFront(e);
}

