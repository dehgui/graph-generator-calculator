#include "internal_commands.hpp"

void write_in_file(const char* file,string text)
{
	ofstream arquivo;
	arquivo.open(file, fstream::app);
	arquivo << text << endl;
	arquivo.close();
}

string making_user(string pass,string email,string name)
{
        string user_info = name + "#" + email + "#" + pass;
        return user_info;
}

bool check_data(const char* file,string thing, int position)
{
	string line;
	fstream arquivo;
	arquivo.open(file);

	while(getline(arquivo,line))
	{
		vector<string> user_informations = split(line,'#');
		if(user_informations.at(position) == thing)
		{
			arquivo.close();
			return true;
		}
	}
	
	arquivo.close();
	return false;
}

string get_user_in_data(string email)
{
	string line;
	fstream arquivo;
	arquivo.open("data/users.txt");

	while( getline(arquivo,line) )
	{
		vector<string> user_informations = split(line,'#');
		if(user_informations.at(1) == email)
		{
			arquivo.close();
			return user_informations.at(0);
		}
	}
	arquivo.close();
	return "Unknown";
}

vector<string> split(string str, char delimiter)
{
        vector<string> internal;
        stringstream ss(str);
        string tok;

        while(getline(ss, tok, delimiter)){
                internal.push_back(tok);
        }

        return internal;
}

string pick_string_from_data(const char* file, string thing, int position)
{
	string line;
	fstream arquivo;
	arquivo.open(file);

	while(getline(arquivo,line))
	{
		vector<string> all = split(line,'#');
		for(int i = 0; i < all.size(); i++)
			if(all.at(i) == thing)
				return all.at(position);
	}

	return "what?";
}

/*bool string_in_vector(string name, vector<string> names)
{
	for(int i = 0; i < names.size(); i++)
		if(names.at(i) == name)
			return true;

	return false;
}

void deleting(string ID, string name)
{
	string line;
	vector<string> entire;
	fstream arquivo;
	system("rm data/graphs.txt");
	arquivo.open("data/graphs.txt");
	
	while( getline(arquivo, line) )
	{
		if( !(split(line,'#').at(1) == name && split(line,'#').at(0) == ID) )
		{
			cout << "Done" << endl;
			entire.push_back(line);
		}
	}

	cout << entire.size() << endl;
	for(int i = 0; i < entire.size(); i++)
		arquivo << entire.at(i) << endl;

	arquivo.close();
}*/

void removing_graph(int local, vector<graph> &graphs)
{
	vector<graph>::iterator it;
	it = graphs.begin() + local;

	graphs.erase(it);
}
