#include <iostream>

#include "Heap.h"

using namespace std;

  Heap::Heap(){
        numItems = 0;                                                   //CONSTRUCTOR THAT SETS NUM OF ITEMS TO 0
  }



//------------------------ELLA CODE---------------------

   void Heap::enqueue( PrintJob* newJob)
  {
    //Check if there is space in the heap
    if(numItems < MAX_HEAP_SIZE)
    {
    //Checks if this number is valid or not
    if(numItems == false)
    {
    //Adds new job to the end of the array and appends numItems
    arr[numItems ] = newJob;
    ++numItems;
    }
    else
    {
    //Create a varibale to hold num of items
    int tempVal = numItems;

    //Checks if the newJob priority is greater than its parent
    while (tempVal > 0 && newJob->getPriority() > (arr[(tempVal-1)/2]->getPriority()))
    {
    //If newJob is greater than its parent, the positions are switched
    arr[tempVal] = arr[(tempVal-1)/2];
    tempVal = (tempVal-1)/2;
    }  
    arr[tempVal] = newJob;
    ++numItems;
    }
  }
}


//-------------------------------------------------------









  void Heap::dequeue ( ) {

        if (numItems == 0) {
            return;
        }

        swap(arr[0], arr[numItems-1]);                                  //MOVES THE FIRST ITEM TO THE END OF THE ARRAY
        numItems --;                                                    //DELETES THE LAST ITEM IN THE ARRAY (ORIGINALLY THE FIRST)
        trickleDown(0);                                                 //CALL PRIVATE FUNCTION TO MOVE THE SWAPPED ITEM TO RIGHT POSITION
  }

  PrintJob* Heap::highest ( ) {
        
        if (numItems == 0) {
            return nullptr;
        }
        
        return arr[0];                                                  //RETURNS INDEX 0 ITEM WHICH IS SUPPOSED TO HIGHEST PRIORITY
  }

  void Heap::print ( ) {                                                //PRINTS THE INDEX 0 OBJECT AS LONG AS ARRAY ISN'T EMPTY
        if (numItems == 0) {
            cout << "EMPTY ARRAY";
            return;
        }
        
    cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages() << endl;
  }

//-----------------------------------------------------------------PRIVATE FUNCTIONS BELOW----------------------------------------

  void Heap::trickleDown(int x) {
        
        int maxValue, maxIndex, i, toTrickle = x;
        int childIndex = 2 * toTrickle + 1;
        int value = arr[toTrickle]->getPriority();

        while (childIndex < numItems){
            maxValue = value;
            maxIndex = -1;

            for (i=0; i< 2 && i + childIndex < numItems; i++){              //CHECK IF PARENT, CHILD 1 OR CHILD 2 IS LARGEST
                if (arr[i+childIndex]->getPriority() > maxValue) {
                    maxValue = arr[i+childIndex]->getPriority();
                    maxIndex = i + childIndex;
                }
            }

            if (maxValue == value) {                                        //IF PARENT IS LARGEST THEN EVERYTHING IS GOOD
                return;
            }

            else {                                                          //SWAP PARENT WITH BIGGER CHILD
                swap(arr[toTrickle],arr[maxIndex]);
                toTrickle = maxIndex;                                       //SWAPPED NODE BECOMES NEW PARENT FOR NEW LOOP
                childIndex = 2 * toTrickle + 1;                             //GET THE 2 NEW CHILDRE FOR NEW LOOP ITERATION
            }
        } 

  }

  //You can include additional private helper functions here