/****************************************************************************
   PURPOSE: Implements a data structure, simple dynamic list 
   USING: No dependencies 
   USED IN: interp.c, see readme.txt 
   IMPLEMENTATION: Uses array data structure. No algorithms
 ***************************************************************************/
const int MAX_SIZE = 1000; 

// class declaration
class imgr {
  private:
    int numberList[MAX_SIZE];
    int listSize;
    void InitList();
  public:
     // Constructor/Deconstructor
     imgr(){InitList();};
     ~imgr(){};
 
     // Main functions
     void StoreNumber(int num); // Store number to next in list 
     void StoreNumberToLocation(int num, int pos); // Specific pos 
     int GetNumber(int location); // Get number from location 
};

/***
 * Purpose : Initalize the list
 * Inputs  : None
 * Outputs : None
 ***/
void imgr::InitList() {
  listSize = 0;
  for (int x=0;x<MAX_SIZE+1;x++) numberList[x] = 0;
}

/*** 
 * Purpose : Store a number to the next available spot
 * Inputs  : Number to store
 * Outputs : None
 ***/
void imgr::StoreNumber(int num) {
  if (MAX_SIZE != listSize) {
    numberList[++listSize] = num;
  }
}

/***
 * Purpose : Store number to a specific position in the list
 * Inputs  : Number to store, and position to store it in
 * Outputs : None
 ***/
void imgr::StoreNumberToLocation(int num, int pos) {
  if (pos>MAX_SIZE) return; // Check bounds
  if (pos>listSize) listSize=pos; // Is the new spot beyond the current size? 
  numberList[listSize++] = num; // Increment listSize and store new number
}

/***
 * Purpose : Get a number from a particular location in the list
 * Inputs  : Location, the memory location of item to return
 * Outputs : Returns the number read from the location in memory
 ***/
int imgr::GetNumber(int location) { 
  if (location<1 || location>MAX_SIZE) return 0; // Check bounds
  return listSize>=location?numberList[location]:0; // 0 if location invalid
} 

