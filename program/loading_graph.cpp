#include "loading_graph.hpp"

vector<graph> loading(string ID)
{
	vector<graph> User_graphs;
	vector<string> graphs;
	string line;
	fstream arquivo;
	arquivo.open("data/graphs.txt");
	
	while( getline(arquivo,line) ){
		if(split(line,'#').at(0) == ID)
			graphs.push_back(line);
	}
	
	for(int i = 0; i < graphs.size(); i++)
		User_graphs.push_back(getting_graph(graphs.at(i)));

	return User_graphs;
}

graph getting_graph(string line)
{
	graph mygraph;

	mygraph.setName(split(line,'#').at(1));
	vector<arests> arestas = getting_all_arests(split(line,'#').at(2));
	mygraph.setAll_nodes(the_nodes(split(line,'#').at(3)));
	mygraph.setGrafo(arestas);
	mygraph.setNodes(the_nodes(split(line,'#').at(2)).size());

	return mygraph;
}

vector<node> the_nodes(string nodes)
{
	vector<node> the_nodes;
	vector<string> all_nodes = split(nodes, '&');
	for(int i = 0; i < all_nodes.size(); i++)
	{
		node local;
		local.setName(all_nodes.at(i));
		the_nodes.push_back(local);
	}

	return the_nodes;
}

/*vector<node> the_nodes(string aresta)
{
	vector<node> nodes;

	if(aresta != "NONE")
	{
		vector<string> arest_by_arest = split(aresta,'$'), jafoi;
		for(int i = 0; i < arest_by_arest.size(); i++)		
		{
			string withoutPrice = split(arest_by_arest.at(i),'&').at(0);
			vector<string> the_nodes = split(withoutPrice,'*');
			
			check_the_vec(nodes,the_nodes.at(0),jafoi);
			check_the_vec(nodes,the_nodes.at(1),jafoi);
		}
	}
	return nodes;
}

void check_the_vec(vector<node> &nodes, string the_node, vector<string> &jafoi)
{
	bool check = true;
        for(int j = 0; j < jafoi.size() && check == true; j++)
		if(jafoi.at(j) == the_node)
                	check = false;

	if(check)
	{
		jafoi.push_back(the_node);
                node local;
                local.setName(the_node);
		nodes.push_back(local);
	}
}*/

vector<arests> getting_all_arests(string line)
{
	vector<arests> ARESTAS;
	if(line != "NONE")
	{
		vector<string> string_arests = split(line,'$');
		for(int i = 0; i < string_arests.size(); i++)
		{
			node begin, end;
			arests ARESTA;
			vector<string> arest = split(string_arests.at(i),'&');
	
			ARESTA.setPrice(string_to_price(arest.at(1)));
			begin.setName(split(arest.at(0),'*').at(0));
			end.setName(split(arest.at(0),'*').at(1));
	
			ARESTA.setBegin(begin);
			ARESTA.setEnd(end);
	
			ARESTAS.push_back(ARESTA);
		}
	}
	
	return ARESTAS;
}

float string_to_price(string price_word)
{
	if(price_word.at(0) == '0')
		return 0;
	else	if(price_word.find(".",1,1) != string::npos)
		{
			vector<string> number = split(price_word,'.');
			float int_part = string_to_float(number.at(0)), fract_part = string_to_float(number.at(1));
			while(fract_part >= 1)
				fract_part/=10;
	
			return int_part + fract_part;
		}
		else
			return string_to_float(price_word);	
}

float string_to_float(string word)
{
	float number = 0.00;
	string numbers = "0123456789";
	
	for(int i = 0; i < word.size(); i++)
		for(int j = 0; j < numbers.size(); j++)
			if(word.at(i) == numbers.at(j))
			{
				number*=10;
				number+=j;
			}
	return number;
}
