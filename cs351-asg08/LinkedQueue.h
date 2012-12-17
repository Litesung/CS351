/*******************************************************
 * by Jeremy Villegas
 * CS 351 Fall 07
 * Assignment #8
 * 
 * Purpose: Header file for LinkedQueue class
 *
 ******************************************************/

// Shortcut definiton for int
typedef char el_t;
const int MAX_SIZE = 10;

// Node structure
struct Node {
  el_t node_data;             // Actual node data
  Node *next;                 // Pointer for next element
  Node *prev;                 // Pointer for next element
};

class LinkedQueue {
  protected:
    Node *Front;              // Pointer to first element in line
    Node *Rear;               // Pointer to last element in line
    int Count;                // How many elements are in the list
    void QueueError(char*);   // Bail out  
  public:
    LinkedQueue();            // Constructor
    ~LinkedQueue();           // DeConstructor
    void addRear(el_t);       // Add an element to the back
    void deleteFront(el_t&);  // The wait is over, pop from queue
    int getSize();            // Returns size of queue
    void displayAll();        // Display the whole queue, no popping
    bool isEmpty();           // Is the queue empty
};

