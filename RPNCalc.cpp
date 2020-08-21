/*
RPNCalc.cpp
Description: Implementation of the public and private function for
              RPNCalc. The user can enter any command, but only
              vaild command will be execute. The user could enter integer,
              booleans, or Rstring. Different function will be called to
              execute different function. Error statement will print if
              an exception is caught.
*/

#include <fstream>
#include <string>
#include <sstream>
#include "RPNCalc.h"
#include "DatumStack.h"
#include "Datum.h"

// Default Constructor
// Parameters: none
// Returns: none
// Does: Initializes the private variables
RPNCalc::RPNCalc(){

}

// Destructor
// Parameters: none
// Returns: none
// Does Deletes the heap-allocated data
RPNCalc::~RPNCalc(){

}

// run()
// Parameters: none
// Returns: none
// Does: launch the command loop
void RPNCalc::run(){
        process_command(cin);
        exit(EXIT_SUCCESS);
}

// process_command()
// Parameters: istream input
// Returns: none
// Does: Take command from istream and call different function based on the
//       input command
void RPNCalc::process_command(istream &input){
        int int_p;
        string array1[] = {"+" , "-" ,"*" , "/", "mod"};
        string array2[] = {"<","<=",">", ">=", "=="};

        while(input >> command){
                if (error_command (command) == true){
                        if (got_int(command, &int_p) == true){
                                add_number(command);
                        }else if(command == "#t"){
                                add_true();
                        }else if (command == "#f"){
                                add_false();
                        }else if (command == "not"){
                                processing_not();
                        }else if (command == "print"){
                                processing_print();
                        }else if (command == "clear"){
                                processing_clear();
                        }else if (command == "quit"){
                                processing_quit();
                        }else if (command == "drop"){
                                processing_drop();
                        }else if (command == "dup"){
                                processing_dup();
                        }else if (command == "swap"){
                                processing_swap();
                        }else if (command == "{"){
                                addRstring(parseRstring(input));
                        }else if (command == "exec"){
                                processing_exec();
                        }else if (command == "file"){
                                processing_file();
                        }else if (command == "if"){
                                processing_if();
                        }else{
                                for (int i = 0; i < 5; i++){
                                        if (command == array1[i]){
                                                calculation(command);
                                        }else if (command == array2[i]){
                                                comparsion(command);
                                        }
                                }
                        }
                }else{
                        cerr << command << ": unimplemented\n";
                }
        }
}

// add_number()
// Parameters: string input
// Returns: none
// Does: push a number to the stack by turing a string into a integer
void RPNCalc::add_number(string input){
        stringstream stringInput (input);
        int temp = 0;
        stringInput >> temp;
        Datum number(temp);
        stack.push(number);
}

// add_true()
// Parameters: string input
// Returns: none
// Does: push a number to the stack by turing a string into a boolean
void RPNCalc::add_true(){
        bool temp = true;
        Datum boolean(temp);
        stack.push(boolean);
}

// add_false()
// Parameters: string input
// Returns: none
// Does: push a number to the stack by turing a string into a boolean
void RPNCalc::add_false(){
        bool temp = false;
        Datum boolean(temp);
        stack.push(boolean);
}

// processing_not()
// Parameters: none
// Returns: none
// Does: pop the top element or change the boolean to its inverse
void RPNCalc::processing_not(){
        if(stack.isEmpty()){
                cerr << "Error: empty_stack\n";
        }else if (stack.top().isBool() == true){
                bool temp = stack.top().getBool();
                temp = !temp;
                stack.pop();
                Datum new_bool(temp);
                stack.push(new_bool);
        }else if (stack.top().isInt() == true){
                stack.pop();
        }else if (stack.top().isRString() == true){
                cerr << "Error: datum_not_bool\n";
                stack.pop();
        }
}

// processing_print()
// Parameters: none
// Returns: none
// Does: print the top element
void RPNCalc::processing_print(){
        try{
                cout << stack.top().toString() << endl;
        }catch (runtime_error e){
                cerr << "empty_stack" << endl;
        }

}

// processing_clear()
// Parameters: none
// Returns: none
// Does: clear the stack
void RPNCalc::processing_clear(){
        stack.clear();
}

// processing_drop()
// Parameters: none
// Returns: none
// Does: pop the top element
void RPNCalc::processing_drop(){
        if (stack.isEmpty() == true){
                cerr << "Error: empty_stack" << endl;
        }else{
                stack.pop();
        }
}

// processing_dup()
// Parameters: none
// Returns: none
// Does: Duplicate the datum from the top of the stack and push it onto stack
void RPNCalc::processing_dup(){
        if (stack.isEmpty() == true){
                cerr << "Error: empty_stack" << endl;
        }else{
                Datum duplicate (stack.top());
                stack.push(duplicate);
        }
}

// processing_swap()
// Parameters: none
// Returns: none
// Does: pop top to element off the stack and swap
void RPNCalc::processing_swap(){
        try{
                if (stack.isEmpty() == true){
                        cerr << "Error: empty_stack" << endl;
                }else{
                        Datum top (stack.top());
                        stack.pop();
                        Datum second (stack.top());
                        stack.pop();

                        stack.push(top);
                        stack.push(second);
                }
        }catch (range_error e){
                cerr << "Error: empty_stack" << endl;
        }
}

// processing_quit()
// Parameters: none
// Returns: none
// Does: terminate the program
void RPNCalc::processing_quit(){
        cout << "Thank you for using CalcYouLater."<< endl;
        stack.clear();
        exit(EXIT_SUCCESS);
}

// error_command()
// Parameters: none
// Returns: bool
// Does: check if the command are vaild
bool RPNCalc::error_command(string user_command){
        int int_p;
        string array1[] = {"+" , "-" ,"*" , "/", "mod"};
        string array2[] = {"<","<=",">", ">=", "=="};

        if (got_int(user_command, &int_p) == true){
                return true;
        }else if(user_command == "#t"){
                return true;
        }else if (user_command == "#f"){
                return true;
        }else if (user_command == "not"){
                return true;
        }else if (user_command == "print"){
                return true;
        }else if (user_command == "clear"){
                return true;
        }else if (user_command == "quit"){
                return true;
        }else if (user_command == "drop"){
                return true;
        }else if (user_command == "dup"){
                return true;
        }else if (user_command == "swap"){
                return true;
        }else if (user_command == "{"){
                return true;
        }else if (user_command == "exec"){
                return true;
        }else if (user_command == "file"){
                return true;
        }else if (user_command== "if"){
                return true;
        }else{
                for (int i = 0; i < 5; i++){
                        if (user_command == array1[i]){
                                return true;
                        }else if (user_command == array2[i]){
                                return true;
                        }
                }
        }
        return false;
}

// calculation()
// Parameters: string
// Returns: none
// Does: do operation on the first two element in the stack and push the
//             result back into the top of the stack
void RPNCalc::calculation(string input_command){
        Datum element1(stack.top());
        stack.pop();
        Datum element2(stack.top());
        stack.pop();

        if(input_command == "+"){
                Datum result = element1.getInt() + element2.getInt();
                stack.push(result);
        }else if (input_command == "-"){
                Datum result = element2.getInt() - element1.getInt();
                stack.push(result);
        }else if (input_command == "*"){
                Datum result = element1.getInt() * element2.getInt();
                stack.push(result);
        }else if (input_command == "/") {
                if (element1.getInt() == 0){
                        cerr << "Error: division by 0." << endl;
                }else{
                        Datum result = element2.getInt() / element1.getInt();
                        stack.push(result);
                }
        }else if (input_command == "mod"){
                Datum result = element2.getInt() % element1.getInt();
                stack.push(result);
        }
}

// calculation()
// Parameters: string
// Returns: none
// Does: do comparsion on the first two element in the stack and push
//            a boolean back into the top of the stack
void RPNCalc::comparsion(string input_command){
        Datum element1(stack.top());
        stack.pop();
        Datum element2(stack.top());
        stack.pop();

        Datum t(true);
        Datum f(false);

        if (input_command == "<"){
                if (element1.getInt() < element2.getInt()){
                        stack.push(t);
                }else{
                        stack.push(f);
                }
        }else if (input_command == ">"){
                if (element1.getInt() > element2.getInt()){
                        stack.push(t);
                }else{
                        stack.push(f);
                }
        }else if (input_command == "<="){
                if (element1.getInt() <= element2.getInt()){
                        stack.push(t);
                }else{
                        stack.push(f);
                }
        }else if (input_command == ">=") {
                if (element1.getInt() >= element2.getInt()){
                        stack.push(t);
                }else{
                        stack.push(f);
                }
        }else if (input_command == "=="){
                if (element1.isBool() || element2.isBool()){
                        stack.push(f);
                }else if (element1.getInt() == element2.getInt()){
                        stack.push(t);
                }else{
                        stack.push(f);
                }
        }
}

// parseRstring()
// Parameters: istream
// Returns: string
// Does: return a vaild RString
string RPNCalc::parseRstring(istream &input_Rstring){
        string vaild = "{";
        char temp;
        int counter = 1;

        while(counter != 0){
                input_Rstring.get(temp);

                if (temp == '{'){
                        counter++;
                }else if (temp == '}'){
                        counter--;
                }
                vaild = vaild + temp;
        }
        return vaild;
}

// addRstring()
// Parameters: string
// Returns: none
// Does: add rstring to the top of the stack
void RPNCalc::addRstring(string vaild_string){
        Datum s (vaild_string);
        stack.push(s);
}

// processing_exec()
// Parameters: none
// Returns: none
// Does: exec the commands from a rstring
void RPNCalc::processing_exec(){
        try{
                string input_string = stack.top().getRString();
                stack.pop();

                stringstream input1 (input_string);
                string rstring_command;
                int int_p;
                string array1[] = {"+" , "-" ,"*" , "/", "mod"};
                string array2[] = {"<","<=",">", ">=", "=="};

                input1 >> rstring_command;//take in open bracket

                while(input1 >> rstring_command){
                        if (got_int(rstring_command, &int_p) == true){
                                add_number(rstring_command);
                        }else if(rstring_command == "#t"){
                                add_true();
                        }else if (rstring_command == "#f"){
                                add_false();
                        }else if (rstring_command == "not"){
                                processing_not();
                        }else if (rstring_command == "print"){
                                processing_print();
                        }else if (rstring_command == "clear"){
                                processing_clear();
                        }else if (rstring_command == "quit"){
                                processing_quit();
                        }else if (rstring_command == "drop"){
                                processing_drop();
                        }else if (rstring_command == "dup"){
                                processing_dup();
                        }else if (rstring_command == "swap"){
                                processing_swap();
                        }else if (rstring_command == "{"){
                                addRstring(parseRstring(input1));
                        }else if (rstring_command == "exec"){
                                processing_exec();
                        }else if (rstring_command == "file"){
                                processing_file();
                        }else if (rstring_command == "if"){
                                processing_if();
                        }else{
                                for (int i = 0; i < 5; i++){
                                        if (rstring_command == array1[i]){
                                                calculation(rstring_command);
                                        }else if (rstring_command == array2[i]){
                                                comparsion(rstring_command);
                                        }
                                }
                        }
                }
        }catch (runtime_error e){
                cerr << "Error: cannot execute non rstring\n";
        }
}

// processing_file()
// Parameters: none
// Returns: none
// Does: read in the Rstring with the filename
void RPNCalc::processing_file(){
        try{
                string input_string = stack.top().getRString();
                stack.pop();
                stringstream input (input_string);
                string readIn;

                input >> readIn;//read in the {
                input >> readIn;//over write and reading the filename
                read_file(readIn);

        }catch (runtime_error e) {
                cerr << "Error: file operand not rstring\n";
        }
}

// read_file()
// Parameters: none
// Returns: none
// Does: open the file
void RPNCalc::read_file(string filename){
        ifstream infile(filename.c_str());
        if(!infile.is_open()){
                cerr << "Error: could not open file "<< filename << endl;
                return;
        }
        process_command(infile);
        infile.close();
}

// processing_if()
// Parameters: none
// Returns: none
// Does: execute a rstring base on the boolean
void RPNCalc::processing_if(){
        try{
                string false_case  = stack.top().getRString();
                        stack.pop();
                string true_case = stack.top().getRString();
                        stack.pop();
                bool condition = stack.top().getBool();
                        stack.pop();

                        if (condition == true){
                                exec_cases(true_case);
                        }else{
                                exec_cases(false_case);
                        }
        }catch (runtime_error e){
                if (strcmp(e.what(), "datum_not_rstring") == 0){
                        cerr << "Error: expected rstring in if branch\n";
                } else if (strcmp(e.what(), "datum_not_bool") == 0){
                        cerr << "Error: expected boolean in if test\n";
                }
        }
}

// exec_cases()
// Parameters: string
// Returns: none
// Does: read in the command from the rstring pass in from the if function
void RPNCalc::exec_cases(string string_case){
        stringstream input1 (string_case);
        string rstring_command;
        int int_p;
        string array1[] = {"+" , "-" ,"*" , "/", "mod"};
        string array2[] = {"<","<=",">", ">=", "=="};

        input1 >> rstring_command;//take in the bracket

        while(input1 >> rstring_command){
                if (got_int(rstring_command, &int_p) == true){
                        add_number(rstring_command);
                }else if(rstring_command == "#t"){
                                add_true();
                }else if (rstring_command == "#f"){
                                add_false();
                }else if (rstring_command == "not"){
                                processing_not();
                }else if (rstring_command == "print"){
                                processing_print();
                }else if (rstring_command == "clear"){
                                processing_clear();
                }else if (rstring_command == "drop"){
                                processing_drop();
                }else if (rstring_command == "dup"){
                                processing_dup();
                }else if (rstring_command == "swap"){
                                processing_swap();
                }else if (rstring_command == "{"){
                                addRstring(parseRstring(input1));
                }else if (rstring_command == "exec"){
                                processing_exec();
                }else if (rstring_command == "file"){
                                processing_file();
                }else if (rstring_command == "if"){
                                processing_if();
                }else{
                        for (int i = 0; i < 5; i++){
                                if (rstring_command == array1[i]){
                                        calculation(rstring_command);
                                }else if (rstring_command == array2[i]){
                                        comparsion(rstring_command);
                                }
                        }
                }
        }
}

// simple_command()
// Parameters: istream
// Returns: none
// Does: Testing function to take the simple command
void RPNCalc::simple_command(istream &input){
        int int_p;
        input >> command;
        while(command != "quit"){
                if (got_int(command, &int_p) == true){
                        add_number(command);
                }else if(command == "#t"){
                        add_true();
                }else if (command == "#f"){
                        add_false();
                }else if (command == "not"){
                        processing_not();
                }else if (command == "print"){
                        processing_print();
                }else if (command == "clear"){
                        processing_clear();
                }else if (command == "drop"){
                        processing_drop();
                }else if (command == "dup"){
                        processing_dup();
                }else if (command == "swap"){
                        processing_swap();
                }else{
                        cout << "none command" << endl;
                }
                input >> command;
        }
        processing_quit();
}

// got_int()
// Parameters: string, int
// Returns: bool
// Does: Check if the given string is a int or not
bool RPNCalc::got_int(string s, int *resultp){
        return sscanf(s.c_str(), "%d", resultp) == 1;
}

// print()
// Parameters: none
// Returns: none
// Does: loop through the stack and print all element in the stack
void RPNCalc::print(){
        stack.print();
}
