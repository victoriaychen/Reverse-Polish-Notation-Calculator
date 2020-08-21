/*
* parser.cpp
* Description: This file contains one function that return a string of vaild
*               of the input command. This function is called when there is
+               a "{" in the command
*/
#include <iostream>
#include <istream>
#include <string>

using namespace std;

string parseRstring(istream &input)
{
        string vaild = "{";
        char temp;

        int counter = 1;

        while(counter != 0){
                input.get(temp);

                if (temp == '{'){
                        counter++;
                }else if (temp == '}'){
                        counter--;
                }
                vaild = vaild + temp;
        }
                return vaild;
}

//Testing parseRstring()
int main()
{
        string command;
        cin >> command;
        cout << parseRstring(cin) << endl;
}
