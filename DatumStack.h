/*
 * DatumStack.h
 * Description: Class that Implementation of DatumStack. The date structure
 *              is a vector. This vector will act like a stack in which
 *              the user could add element top of the stack and delete the
 *              element on the top.
 */

#include <vector>

#include "Datum.h"

#ifndef _DATUMSTACK_H_
#define _DATUMSTACK_H_

using namespace std;

class DatumStack
{
public:
        DatumStack();
        DatumStack(Datum input_datum[], int size);

        bool isEmpty();
        void clear();
        int size();
        Datum top();
        void pop();
        void push(Datum element);

        void print();

private:
        vector <Datum> datums;
        //void print();//for testing
};

#endif
