#include "using_graph.hpp"

void print_graph(graph Grafo)
{
	int option;
	system("clear");
	cin.ignore();
	do{
		print_string("___" + Grafo.getName() + "___\n\n");
		print_order(Grafo.getAll_nodes());
		print_with_matricial(Grafo.getGrafo(), Grafo.getAll_nodes());

		option = ask_int("\n(1) Calculate the least expensive route.\n(0) Exit\nOption: ");
		analiser_for_graph(option,Grafo);
		system("clear");
	}while(option != 0);
}

void print_order(vector<node> nodes)
{
	print_string("Order: || ");
	for(int i = 0; i < nodes.size(); i++)
		print_string(nodes.at(i).getName() + " || ");

	cout << endl << endl;
}

void analiser_for_graph(int option,graph user_graph)
{
	switch(option)
	{
		case 0:	break;
		case 1:	calculating(user_graph);
			break;
		default: print_string("Invalid option!");
	}
}

void print_with_matricial(vector<arests> arestas, vector<node> nodes)
{
	for(int i = 0; i < nodes.size(); i++)
	{
		print_string(nodes.at(i).getName() + " || ");
		for(int j = 0; j < nodes.size(); j++)
		{
			bool check = true;
			for(int k = 0; k < arestas.size(); k++)
				if(arestas.at(k).getBegin().getName() == nodes.at(i).getName() && arestas.at(k).getEnd().getName() == nodes.at(j).getName() && check)
				{
					check = false;
					cout << arestas.at(k).getPrice() << " || ";
				}
			if(check == true)
				cout << "- || ";
		}
		cout << endl;
	}
}

/*void printing_graph(vector<arests> all_paths,vector<node> nodes)
{
        cout << "  ||";
        for(int i=0;i<nodes.size();i++)
        {
                cout << nodes.at(i).getName() << " || ";
        }
        cout << endl << endl;
        for(int i=0;i<nodes.size();i++)
        {
                cout << nodes.at(i).getName() << " || ";
                for(int j=0;j<nodes.size();j++)
                        if(nodes.at(i).getName() == all_paths.at(i).getBegin().getName() && all_paths.at(i).getEnd().getName() == nodes.at(j).getName() && i != j)
                                cout << all_paths.at(j).getPrice() << " || ";
                        else
                                cout << "-" << " || ";

                cout << endl;
        }
}*/

