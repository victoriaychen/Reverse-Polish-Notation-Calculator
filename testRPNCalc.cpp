/*
testRPNCalc.cpp
Description: This file contain unit testing function for the public and private
              function for RPNCalc. At first, I have tested the simple command
              by passing in a datum. Now, I changed some of the simple command
              function like add_number(), add_true(), add_false(), and
              processing_not() to take in instream instead. Therefore, some of
              testing function is commented out because it takes in a different
              Parameters and the functions are now in the private function
              of RPNCalc.
*/

#include <iostream>

#include "RPNCalc.h"

using namespace std;

void testing_add_number(istream &input);
void testing_add_true(istream &input);
void testing_processing_not(istream &input);
void testing_processing_print(Datum number);
void testing_processing_clear(Datum number);
void testing_processing_drop(Datum number1, Datum number2);
void testing_processing_dup(Datum command);
void testing_processing_quit();
void testing_processing_swap(Datum number1, Datum number2);
void testing_calculation(Datum number1, Datum number2, Datum command);
void testing_comparsion(Datum number1, Datum number2, Datum command);
void testing_parseRstring();
void testing_processing_exec(Datum number1,Datum number2,Datum command);
void testing_processing_exec2();
void testing_simple_command(RPNCalc my_calc);
void testing_harder_command(RPNCalc my_calc);
void testing_run();
void testing_file(RPNCalc my_calc);

int main(int argc, char *argv[]){
        (void) argc;
        (void) argv;
        Datum a(1);
        Datum c(2);
        Datum b(true);
        Datum command ("<=");
        //Datum input_string (cin);
        //testing_add_number(cin);
        //testing_processing_true(cin);
        //testing_processing_not(cin);
        //testing_processing_print(a);
        //testing_processing_clear(a);
        //testing_processing_drop(a,c);
        //testing_processing_dup(c);
        //testing_processing_quit();
        //testing_processing_swap(a,c);
        //testing_calculation (a,c,command);
        //testing_comparsion (a,c,command);
        //testing_parseRstring();
        //testing_processing_exec(a,c,command);
        //testing_processing_file();
        //testing_processing_exec2();

        RPNCalc my_calc;
        // testing_simple_command(my_calc);
        //testing_harder_command(my_calc);
        //testing_file(my_calc);
        testing_run();
}

void testing_run(){
        RPNCalc calc;
        calc.run();
}

// void testing_add_number(istream &input){
//         RPNCalc calc;
//         string i;
//         input >> i;
//         calc.add_number(i);
//         calc.processing_print();
// }
//
// void testing_add_true(istream &input){
//         RPNCalc calc;
//         string i;
//         input >> i;
//         if (i == "#t"){
//                 calc.add_true();
//         }
//         calc.print();
// }
//
// void testing_processing_not(istream &input){
//         RPNCalc calc;
//         string i;
//         input >> i;
//         if (i == "#t"){
//                 calc.add_true();
//         }
//         calc.processing_not();
//         calc.print();
// }

// void testing_processing_print(Datum number){
//         RPNCalc calc;
//         calc.add_number(number);
//         calc.processing_print();
// }
//
// void testing_processing_clear(Datum number){
//         RPNCalc calc;
//         calc.add_number(number);
//         calc.processing_clear();
//         calc.processing_print();
// }
//
// void testing_processing_drop(Datum number1, Datum number2){
//         RPNCalc calc;
//         calc.add_number(number1);
//         calc.add_number(number2);
//         calc.processing_drop();
//         calc.processing_print();
// }
//
// void testing_processing_dup(Datum command){
//         RPNCalc calc;
//         calc.add_number(command);
//         calc.processing_dup();
//         calc.print();
// }

// void testing_processing_quit(){
//         RPNCalc calc;
//         calc.processing_quit();
// }
//
// void testing_processing_swap(Datum number1, Datum number2){
//         RPNCalc calc;
//         calc.add_number(number1);
//         calc.add_number(number2);
//         calc.print();
//
//         calc.processing_swap();
//         calc.print();
// }
//
// void testing_calculation(Datum number1, Datum number2, Datum command){
//         RPNCalc calc;
//         calc.add_number(number1);
//         calc.add_number(number2);
//         calc.calculation(command);
//         calc.processing_print();
// }
//
// void testing_comparsion(Datum number1, Datum number2, Datum command){
//         RPNCalc calc;
//         calc.add_number(number1);
//         calc.add_number(number2);
//         calc.comparsion(command);
//         calc.processing_print();
// }
//
// void testing_parseRstring(){
//         RPNCalc calc;
//         string input;
//         cin >> input;
//         cout << calc.parseRstring(cin) << endl;
// }

// void testing_processing_exec(Datum number1,Datum number2,Datum command){
//         RPNCalc calc;
//         calc.add_number(number1);
//         calc.add_number(number2);
//         // calc.print();
//         // cout << endl;
//         calc.processing_exec(command);
//         calc.processing_print();
// }

// void testing_processing_exec2(){
//         RPNCalc calc;
//         Datum s ("{ 1 2 + }");
//         calc.add_number(s);
//         calc.processing_exec();
//         calc.processing_print();
// }
// void testing_simple_command(RPNCalc my_calc){
//         my_calc.simple_command(cin);
// }
// void testing_process_command(RPNCalc my_calc){
//         my_calc.process_command(cin);
// }
