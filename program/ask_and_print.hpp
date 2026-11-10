#ifndef ASK_AND_PRINT_HPP
#define ASK_AND_PRINT_HPP

#include <iostream>
#include <iomanip>
#include <termios.h>
#include <unistd.h>
#include "graph.hpp"


int ask_int(string);
float ask_float(string);
string ask_string_secret(string);
string ask_string(string);
void print_string(string);
vector<string> ask_all_names(int,string);

#endif
