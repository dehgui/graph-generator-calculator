#ifndef INTERNAL_COMMANDS_HPP
#define INTERNAL_COMMANDS_HPP

#include <fstream>
#include <sstream>
#include <vector>
#include "ask_and_print.hpp"

using namespace std;

void write_in_file(const char*, string);
string making_user(string,string,string);
bool check_data(const char*, string, int);
string get_user_in_data(string);
vector<string> split(string, char);
string pick_string_from_data(const char*,string,int);
void deleting(string,string); 
void removing_graph(int, vector<graph>&);

#endif
