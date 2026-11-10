#ifndef GRAPH_SAVING_COMMANDS
#define GRAPH_SAVING_COMMANDS

#include "users.hpp"

bool validate_name(string);
bool graph_already_exists(vector<graph>,string);
bool name_already_exists(string,vector<string>);
vector<string> nodes_names(vector<node>);
bool check_option(int);

#endif
