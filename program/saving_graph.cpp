#include "saving_graph.hpp"

void save_graph(string ID, graph GRAFO)
{
	write_in_file("data/graphs.txt",making_user(separating_graph(GRAFO),GRAFO.getName(),ID));
}

string separating_graph(graph GRAFO)
{
	string line = "";
	for(int i = 0; i < GRAFO.getGrafo().size(); i++)
	{
		if(i != 0)
			line+= '$';

		line += GRAFO.getGrafo().at(i).getBegin().getName() + "*" + GRAFO.getGrafo().at(i).getEnd().getName() + "&" + float_to_string(GRAFO.getGrafo().at(i).getPrice());
	}
	
	line += "#";
	for(int i = 0; i < GRAFO.getAll_nodes().size(); i++)
	{
		string node = GRAFO.getAll_nodes().at(i).getName() + "&";
		line += node;
	}

	if(GRAFO.getGrafo().size() == 0)
		line = "NONE";

	return line;
}

string float_to_string(float number)
{
	stringstream ss (stringstream::in | stringstream::out);
	ss << number;
	string strnumber = ss.str();
	return strnumber;
}
