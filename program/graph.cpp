#include "graph.hpp"

void graph::setName(string name)
{
	this->name=name;
}

void graph::setGrafo(vector<arests> grafo)
{
	this->grafo=grafo;
}

void graph::setNodes(int nodes)
{
	this->nodes=nodes;
}

void graph::setAll_nodes(vector<node> graph_nodes)
{
	this->all_nodes=graph_nodes;
}

string graph::getName()
{
	return this->name;
}

vector<arests> graph::getGrafo()
{
	return this->grafo;
}

vector<node> graph::getAll_nodes()
{
	return this->all_nodes;
}
