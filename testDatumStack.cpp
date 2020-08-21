/*
* testDatumStack.cpp
* Description: This file contains unit testing function that test the functions
*              in DatumStack.cpp
*/

#include <iostream>
#include "DatumStack.h"

using namespace std;

void isEmptyTesting();
void clearTesting();
void sizeTesting();
void pushTesting();
void topTesting();
void popTesting();
void constructor2Testing(Datum input_datum[], int size);

int main()
{
        isEmptyTesting();
        clearTesting();
        sizeTesting ();
        pushTesting();
        topTesting();
        popTesting();

        Datum input_datum[3] = {1,3,5};
        constructor2Testing (input_datum, 3);

}

//testing clear()
void isEmptyTesting()
{
        DatumStack stack;
        if (stack.isEmpty()){
                cout << "Stack is empty!"<< endl;
        }
}

//testing clear()
void clearTesting()
{
        DatumStack stack;
        Datum a = 1;
        Datum b = 2;
        Datum c = 3;

        stack.push(a);
        stack.push(b);
        stack.push(c);

        stack.clear();

        if (stack.isEmpty()){
                cout << "stack is empty!"<< endl;
        }else{
                //stack.print();
        }
}

//testing push()
void pushTesting()
{
        DatumStack stack;
        Datum a = 1;
        Datum b = 2;
        Datum c = 3;

        stack.push(a);
        stack.push(b);
        stack.push(c);

        //stack.print();
}

//testing size()
void sizeTesting()
{
        DatumStack stack;
        Datum a = 1;
        Datum b = 2;
        Datum c = 3;

        stack.push(a);
        stack.push(b);
        stack.push(c);

        cout << stack.size() << endl;
}

//testing top()
void topTesting()
{
        DatumStack stack;
        Datum a = 1;
        Datum b = 2;
        Datum c = 3;

        stack.push(a);
        stack.push(b);
        stack.push(c);

        cout << stack.top().toString() << endl;
}

//testing pop()
void popTesting()
{
        DatumStack stack;
        Datum a = 1;
        Datum b = 2;
        Datum c = 3;

        stack.push(a);
        stack.push(b);
        stack.push(c);

        stack.pop();
        stack.pop();

        //stack.print();
}

void constructor2Testing(Datum input_datum[], int size )
{
        DatumStack stack(input_datum, size);

        //stack.print();
}
