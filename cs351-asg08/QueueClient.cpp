/*******************************************************
 * by Jeremy Villegas
 * CS 351 Fall 07
 * Assignment #8
 * 
 * Purpose: Queue Client to test drive the linkedlist
            class.
 *
 ******************************************************/

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
  LinkedList l;
  el_t c='z';
  
  cout<<"1. Dequeue first in line\n2. Empty the list\n3. Display the ";
  cout<<"list\n0. Quit this\n?. Display This Menu\nAnything Else. Add to queue\n\n";
  while(c!='0'){    
    //cout<<"[hw08@localhost ~]$ ";
    cin>>c;
    switch(c){
      case '1':
        l.deleteFront(c);
        break;
      case '2':
        l.deleteAll();
        break;
      case '3':
        cout<<"List: ";
        l.displayAll();
        cout<<endl;
        break;
      case '0':
        break;
      case '?':
          cout<<"1. Dequeue first in line\n2. Empty the list\n3. Display the ";
          cout<<"list\n0. Quit this\n?. Display This Menu\nAnything Else. Add to queue\n\n";
      default:
        l.addRear(c);
    }
  }
  return 0;
}
