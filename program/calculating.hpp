#ifndef CALCULATING_HPP
#define CALCULATING_HPP

#include "make_graph.hpp"

void calculating(graph);
bool check_if_node_exists(string,vector<node>);
void calculate_the_path(string,string,graph);
void check_if_its_over(vector<path>&, string);
bool all_paths_founded(vector<path>);
bool find_node(string, int, vector<arests>);
void find_paths(path, vector<path>&, vector<arests>, int, string, string);
void varredura(vector<path>&);
void setting_total_price(vector<path>, vector<arests>);
float lowest_price(vector<path>);
void printing_the_paths(vector<path>, float);
void show_all_possibilities(vector<path>);

#endif
