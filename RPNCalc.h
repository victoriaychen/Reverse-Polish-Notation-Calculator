/*
 * RPNCalc.h
 * Description:
 */

#include <vector>
#include <iostream>
#include <fstream>

#include "DatumStack.h"
#include "Datum.h"
#include <cstdio>
#include <string>
#include <cstring>

#ifndef _RPNCALC_H_
#define _RPNCALC_H_

using namespace std;

class RPNCalc
{
public:
        RPNCalc();
        ~RPNCalc();
        void run();
private:
        DatumStack stack;
        string command;

        //contain while loop and take in istream of command
        void process_command(istream &input);

        //simple command
        void add_number(string input);
        void add_true();
        void add_false();
        void processing_not();
        void processing_print();
        void processing_clear();
        void processing_drop();
        void processing_dup();
        void processing_swap();
        void processing_quit();

        //harder command
        string parseRstring(istream &input_Rstring);
        void addRstring(string vaild_string);
        void comparsion(string input_command);
        void calculation(string input_command);
        bool error_command(string user_command);
        void processing_exec();
        void processing_file();
        void read_file(string filename);
        void processing_if();
        void exec_cases(string string_case);//if helper function

        void print();//Help function for debugging
        void simple_command(istream &input);//testing simple command
        bool got_int(string s, int *resultp);
};

#endif
