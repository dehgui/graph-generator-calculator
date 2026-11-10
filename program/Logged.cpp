#include "Logged.hpp"

void menu(string user,string email)
{
	int option;
	vector<graph> User_graphs = loading(email);
	do{
		print_string("Welcome, ");
		print_string(user);
		print_string("!\n\n(1) Create graph\n(2) Load graph\n(0) Return to main menu\n");
		option = ask_int("");
		cin.ignore();
		analiser(option, User_graphs, email);
		system("clear");	
	}while(option != 0);
}

void analiser(int option,vector<graph> &User_graphs,string email)
{
	switch(option)
	{
		case 0: break;
		case 1: User_graphs.push_back(making_graph(email,User_graphs));
			break;
		case 2: load_graph(User_graphs);
			break;
		default: print_string("Invalid option!\n");
	}
}

/*void delete_graph(string ID, vector<graph> &User_graphs)
{
        int option;
        print_string("\n");
        for(int i = 1; i <= User_graphs.size(); i++)
                cout <<"("<<i<<") "<< User_graphs.at(i-1).getName() << endl;
        do{
                option = ask_int("(0) Exit.\nOption: ");
        }while(option > User_graphs.size() && option != 0);

        if(option != 0)
	{
                deleting(ID, User_graphs.at(option-1).getName());
		removing_graph(option-1, User_graphs);
	}
}*/

void load_graph(vector<graph> all_graphs)
{
        int option;
        print_string("\n");
        for(int i = 1; i <= all_graphs.size(); i++)
                cout <<"("<<i<<") "<< all_graphs.at(i-1).getName() << endl;

        print_string("(0) Exit.\n");
        do{
                option = ask_int("Option: ");
        }while(option > all_graphs.size() && option != 0);

        if(option != 0)
                print_graph(all_graphs.at(option - 1));
}

