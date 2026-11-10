#ifndef MAKE_GRAPH_HPP
#define MAKE_GRAPH_HPP

#include <cstdlib>
#include "loading_graph.hpp"

graph making_graph(string,vector<graph>);
vector<node> set_names_of_nodes(int);
vector<arests> set_all_parameters(vector<node>);
string ask_graph_name(string,vector<graph>);

#endif
