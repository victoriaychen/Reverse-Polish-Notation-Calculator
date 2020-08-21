/*
* DatumStack.cpp
* Description: Implementation of the public and private function for
*               DatumStack. The user can add and remove element from the
*               stack. They can also check the top element and size of the
*               stack.
*/
#include <iostream>
#include "DatumStack.h"
#include "Datum.h"

// Default Constructor
// Parameters: none
// Returns: none
// Does: Initializes an empty vector
DatumStack::DatumStack()
{

}

// 2nd Constructor
// Parameters: passing in a array of datum
// Returns: none
// Does: Add element from the input datum into the stack
DatumStack::DatumStack(Datum input_datum[], int size)
{
        for (int i = 0; i < size; i++){
                datums.push_back(input_datum[i]);
        }
}

// Function isEmpty
// Parameters: none
// Returns: true if stack is empty, false otherwise
// Does: Check if the stack is empty
bool DatumStack::isEmpty()
{
        if (datums.size() == 0){
                return true;
        }
        return false;
}

// Function clear
// Parameters: none
// Returns: none
// Does: Set arr capacity and num_chars to 0
void DatumStack::clear()
{
        datums.clear();
        vector <Datum>().swap(datums);


}

// Function size
// Parameters: none
// Returns: integer
// Does: Get number of datum in the stack
int DatumStack::size()
{
        return datums.size();
}

// Function top
// Parameters: none
// Returns: Datum
// Does: Get the top element in the stack
Datum DatumStack::top()
{
        if (isEmpty()){
                throw range_error ("empty_stack");
        }

        Datum first_element = datums.back();

        return first_element;
}

// Function pop
// Parameters: none
// Returns: none
// Does: Remove the top element (last element) in the stack
void DatumStack::pop()
{
        datums.pop_back();
}

// // Function push
// // Parameters: Datum
// // Returns: none
// // Does: Put the input datum and put it on the top
void DatumStack::push(Datum element)
{
        //datums.insert(datums.begin(),element);
        datums.push_back(element);
}

//For testing
void DatumStack::print()
{
        for (int i = 0; i < size(); i++){
                cout << datums[i].toString()<< endl;
        }
}
