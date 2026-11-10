#include "make_graph.hpp"

graph making_graph(string email,vector<graph> user_graphs)
{
        graph GRAFO;
        GRAFO.setName(ask_graph_name("Graph name: ",user_graphs));

        int nodes;
	do{
		nodes = ask_int("Number of nodes: ");
		if(nodes < 2)
			print_string("Minimum: 2.\n");
	}while(nodes < 2);

	GRAFO.setNodes(nodes);
	vector<node> all_nodes = set_names_of_nodes(nodes);
	GRAFO.setGrafo(set_all_parameters(all_nodes));
	GRAFO.setAll_nodes(all_nodes);
	
	save_graph(email,GRAFO);
	system("clear");
	print_string("Graph created!\n");
	return GRAFO;
}

string ask_graph_name(string info, vector<graph> user_graphs)
{
	system("clear");
        string graph_name;
        do{
                print_string(info);
                getline(cin,graph_name);

        }while(!validate_name(graph_name) || graph_already_exists(user_graphs, graph_name));

        return graph_name;
}

vector<node> set_names_of_nodes(int how_many)
{
	cin.ignore();
	vector<node> Grafo;
	print_string("Enter the node names.\n\n");
	for(int i = 0; i < how_many; i++)
	{
		node local;
		string name;
		do{
	                cout << "Name of node " << i+1 << ": ";
			name = ask_string("");
		}while(!validate_name(name) || name_already_exists(name, nodes_names(Grafo)));

		local.setName(name);
		Grafo.push_back(local);
	}
	system("clear");
	return Grafo;
}

vector<arests> set_all_parameters(vector<node> nodes)
{
        vector<arests> grafo;
	vector<string> names = nodes_names(nodes);
        for(int i = 0; i < nodes.size(); i++)
        {
                print_string("Enter the connections for node " + names.at(i) + ": \n\n(1) Yes\n(0) No\n");
		for(int j = 0; j < nodes.size(); j++)
			if(names.at(i) != names.at(j))
			{
				int option;
				do{
					option = ask_int("Connect to "  + names.at(j) + ": ");
				}while(!check_option(option));
				if(option == 1)
				{
					arests way;
					way.setBegin(nodes.at(i));
					way.setEnd(nodes.at(j));
					way.setPrice(ask_float("Cost: "));
					
					grafo.push_back(way);
				}	
			}	
        }
	system("clear");
        return grafo;
}
