/*****************************************************************************
  PURPOSE: Takes input and runs an interpreter to process data. 
  IMPLEMENTED BY: Jeremy Villegas
  DATE: 09/03/2007 
  USER INFORMATION: 
      See program guidelines attached in readme.txt
  IMPLEMENTATION METHOD: No algorithm's used.
  OVERVIEW OF SUBPARTS: 
      imgr.h    - Short driver program used to store the data list input by
                  the user.
      interp.sh - Shell script uses hw1.in as the input buffer to execute
                  the program.
      hw1.in    - Data buffer and instruction set.  See readme.txt.
 ****************************************************************************/


#include <iostream>
#include "imgr.h"

using namespace std;
const int MAX_BUFFER = 1000; // Maximum size of the instruction buffer


main()
{
  // Initalize vars for input and processing 
  int nInput=0, nInterp=0, nVal=0, accumulator=0, insIndex=0, insList[MAX_BUFFER];
  bool bDone = false;
  imgr dataList;

  cout << "Reading data from input stream..."; 
  // First get the data from the input stream
  while (1) {
    // Get Input
    cin >> nInput;
    // Load into mem if checks are passed
    if (nInput > 0 && nInput < 9999) dataList.StoreNumber(nInput); 
    if (nInput == 9999) break;
  }

  // Initalize the command buffer
  for (int x=0;x<MAX_BUFFER;x++) insList[x]=0;

  cout << endl << "Loading instruction set...";
  // Now do the same for the instruction set
  while (1) { 
    // Get Input
    cin >> nInput;
    nInterp = nInput / 1000;
    nVal = nInput % 1000;

    // Load into mem of checks are passed
    if (nInterp > 0 && nInterp < 7) insList[insIndex==MAX_BUFFER?insIndex:insIndex++] = nInput;

    // Break when done 
    if (nInput == 9999) break; 
  }
  
  cout << endl;
  /* Now you have the data and instructions stored in separate lists
     Go through each instruction and execute the appropriate command */
  insIndex = 0;  // start counter over again
  while (!bDone) {
    cout << "Accumulator: " << accumulator << " "; 

    // Get next instruction
    nInput = insList[insIndex==MAX_BUFFER?insIndex:insIndex++];
    nInterp = nInput / 1000;
    nVal = nInput % 1000;
    // Run through different possible instructions
    switch (nInterp) {
      case 1:  // Load accumulator with contents of XXX
        accumulator = dataList.GetNumber(nVal);
        cout << "Loaded " << nVal;
        break;
      case 2:  // Store accumulator into location XXX
        dataList.StoreNumberToLocation(accumulator,nVal);
        cout << "Stored accumulator into " << nVal;
        break; 
      case 3:  // Add contents of XXX to accumulator
        accumulator += dataList.GetNumber(nVal);
        cout << "Added " << nVal;
        break; 
      case 4:  // Sub contents of XXX from accumulator
        accumulator -= dataList.GetNumber(nVal);
        cout << "Subtract " << nVal;
        break; 
      case 5:  // Branch to instruction XXX if accumulator is negative
        if (accumulator<0) { 
          insIndex = nVal;
          cout << "Jumping to instruction " << nVal;
        } else cout << "Cannot jump to instruction " << nVal;
        break;
      case 6:  // End program
        bDone=true;
    }
    cout << endl;
  }  
  
  // Wrap it up
  cout << endl << "Final Value of Accumulator: " << accumulator << "." << endl;
}
