#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "path.hpp"

class graph
{
	private:
		string name;
		int nodes;
		vector<arests> grafo;
		vector<node> all_nodes;

	public:
		void setName(string);
		string getName();

		int getNodes();
		void setNodes(int);

		void setGrafo(vector<arests>);
		vector<arests> getGrafo();

		void setAll_nodes(vector<node>);
		vector<node> getAll_nodes();
		
};

#endif
