#include "calculating.hpp"

void calculating(graph mygraph)
{
	cin.ignore();
	string begin, end;
	do{
		 begin = ask_string("From: ");
	}while(!check_if_node_exists(begin, mygraph.getAll_nodes()));

	do{
		end = ask_string("To: ");
	}while(!check_if_node_exists(end, mygraph.getAll_nodes()) || end == begin);

        if(find_node(begin,0,mygraph.getGrafo()) && find_node(end, 1, mygraph.getGrafo()))
		calculate_the_path(begin, end, mygraph);
}

bool check_if_node_exists(string name,vector<node> nodes)
{
	for(int i = 0; i < nodes.size(); i++)
		if(nodes.at(i).getName() == name)
			return true;

	print_string("\nNode not found.\n");
	return false;
}

void calculate_the_path(string begin, string end, graph mygraph)
{
	vector<path> paths;
	path initial_path;
	paths.push_back(initial_path);
	find_paths(initial_path, paths, mygraph.getGrafo(), 0, begin, end);
	
	while(!all_paths_founded(paths) && paths.size() != 0)
	{
		bool stop = false;
		varredura(paths);
		for(int i = 0; i < paths.size() && !stop; i++)
			if(!paths.at(i).iscompleted())
			{
				find_paths(paths.at(i), paths, mygraph.getGrafo(), i, paths.at(i).getDirection().at(paths.at(i).getDirection().size() - 1).getEnd().getName() , end);
				stop = true;
			}
	}

	if(paths.size() == 0)
	{
		print_string("No paths found.\nPress Enter to continue.\n");
		cin.ignore();
	}
	else
		setting_total_price(paths, mygraph.getGrafo());
}

void check_if_its_over(vector<path>& paths, string end)
{
	for(int i = 0; i < paths.size(); i++)
		if(paths.at(i).getDirection().at(paths.at(i).getDirection().size() - 1).getEnd().getName() == end)
			paths.at(i).setCondition(true);
}

bool all_paths_founded(vector<path> paths)
{
	for(int i = 0; i < paths.size(); i++)
		if( !(paths.at(i).iscompleted()) )
			return false;

	return true;
}

bool find_node(string name, int position, vector<arests> all_arests)
{
	for(int i = 0; i < all_arests.size(); i++)
		if( (position == 0 && all_arests.at(i).getBegin().getName() == name) || (position == 1 && all_arests.at(i).getEnd().getName() == name) )
			return true;

	if(position == 1)
	{
		print_string("There are no paths to " + name + "\nPress Enter to continue.\n");
		cin.ignore();
	}
	else	if(position == 0)
		{
			print_string("There are no paths leaving " + name + "\nPress Enter to continue\n");
			cin.ignore();
		}

	cout << endl;
	return false;
}



void find_paths(path mypath, vector<path>& paths, vector<arests> all_arests,int position, string arest_begin, string end)
{
	paths.erase(paths.begin() + position);
	int degree = 0;
	
	for(int i = 0; i < all_arests.size(); i++)
		if(all_arests.at(i).getBegin().getName() == arest_begin)
		{
			path new_path;
			new_path.setCondition(false);
			for(int j = 0; j < mypath.getDirection().size(); j++)	
				new_path.setDirection(mypath.getDirection().at(j));
			new_path.setDirection(all_arests.at(i));		

			vector<path>::iterator it;
			it = paths.begin() + degree;
			paths.insert(it , new_path);
			degree+=1;
		}

	check_if_its_over(paths, end);		
}

void varredura(vector<path> & paths)
{
	vector<path>::iterator it;

	for(it = paths.begin(); it != paths.end(); ++it)
	{
		path local = *it;
		for(int j = local.getDirection().size() - 1; j >= 0; j--)
			if(local.getDirection().at(local.getDirection().size() - 1).getEnd().getName() == local.getDirection().at(j).getBegin().getName())
			{
				paths.erase(it);
				--it;
			}
	}
}

void setting_total_price(vector<path> paths, vector<arests> all_arests)
{
	for(int i = 0; i < paths.size(); i++)
	{
		float total_price = 0;
		for(int j = 0; j < paths.at(i).getDirection().size(); j++)
			total_price+=paths.at(i).getDirection().at(j).getPrice();

		paths.at(i).setTotal_price(total_price);
	}

	lowest_price(paths);
}

float lowest_price(vector<path> paths)
{
	float lowest = paths.at(0).getTotal_price();
	for(int i = 0; i < paths.size(); i++)
		if(paths.at(i).getTotal_price() <= lowest)
			lowest = paths.at(i).getTotal_price();
	
	printing_the_paths(paths, lowest);
}

void printing_the_paths(vector<path> paths, float lowest_price)
{
	int option;
	do{

		system("clear");
		print_string("Begin: " + paths.at(0).getDirection().at(0).getBegin().getName() + "\nEnd: " + paths.at(0).getDirection().at(0).getEnd().getName() + "\n\n");
		print_string("Lowest cost: ");
		cout << lowest_price << endl << endl;
		print_string("Lowest-cost path(s): \n\n");
		for(int i = 0; i < paths.size(); i++)
			if(paths.at(i).getTotal_price() == lowest_price)
			{
				vector<arests> in_analysis = paths.at(i).getDirection();
				print_string(in_analysis.at(0).getBegin().getName());
				for(int j = 0; j < paths.at(i).getDirection().size(); j++)
					print_string(" ---> " + in_analysis.at(j).getEnd().getName());
				cout << endl << endl;
			}

		cout << "(1) Show all possibilities.\n(0) Return to graph menu." << endl;
		option = ask_int("");
		if(option == 1)
			show_all_possibilities(paths);
		else	if(option != 0)
				cout << "Invalid option." << endl;
	}while(option != 0);
}

void show_all_possibilities(vector<path> paths)
{
	int option;
	print_string("\nAll paths: \n");
        for(int i = 0; i < paths.size(); i++)
        {
                vector<arests> in_analysis = paths.at(i).getDirection();
                print_string(in_analysis.at(0).getBegin().getName());
                for(int j = 0; j < paths.at(i).getDirection().size(); j++)
                	print_string(" ---> " + in_analysis.at(j).getEnd().getName());
                                        
        	cout <<" // Cost: " << paths.at(i).getTotal_price() << endl;
        }

        do{
             	option = ask_int("(0) Close.\nOption: ");
                if(option != 0)
                      	print_string("Invalid option!");
       	}while(option != 0);

}
