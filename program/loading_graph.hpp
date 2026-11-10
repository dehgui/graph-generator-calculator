#ifndef LOADING_GRAPH_HPP
#define LOADING_GRAPH_HPP

#include "saving_graph.hpp"

vector<graph> loading(string);
graph getting_graph(string);
vector<node> the_nodes(string);
void check_the_vec(vector<node>&, string, vector<string>&);
vector<arests> getting_all_arests(string);
float string_to_price(string);
float string_to_float(string);

#endif
