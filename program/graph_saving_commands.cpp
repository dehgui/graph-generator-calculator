#include "graph_saving_commands.hpp"

bool validate_name(string word)
{
	if(word.size() == 0)
		return false;

	for(int i = 0; i < word.size(); i++)
		if(!isalnum(word.at(i)) && word.find_first_of("#$&*") != string::npos)
		{
			print_string("\nInvalid name!\n");
			return false;
		}
	return true;
}

bool graph_already_exists(vector<graph> GRAPHS, string name)
{
	for(int i = 0; i < GRAPHS.size(); i++)
		if(name == GRAPHS.at(i).getName())
		{
			print_string("\nGraph already registered!\n");
			return true;
		}

	return false;
}

bool name_already_exists(string name,vector<string> names)
{
	for(int i = 0; i < names.size(); i++)
		if(names.at(i) == name)
		{
			print_string("Names must be unique.\n");
			return true;
		}

	return false;
}

vector<string> nodes_names(vector<node> nodes)
{
	vector<string> names;
	for(int i = 0; i < nodes.size(); i++)
		names.push_back(nodes.at(i).getName());

	return names;
}

bool check_option(int option)
{
	if(option != 0 && option != 1)
	{
		print_string("Enter 0 or 1 only.\n");
		return false;
	}
	else
		return true;
}
