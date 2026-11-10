#include "ask_and_print.hpp"

string ask_string(string info)
{
        string words;
        cout << info;
        getline(cin,words);
        return words;
}

int ask_int(string info)
{
	int number;
	cout << info;
	cin >> number;
	return number;
}

float ask_float(string info)
{
	float thing;

	do{
		cout << info;
		cin >> thing;
		if(thing > 999999)
			cout << "Do not enter numbers greater than 999999.\n";
	}while(thing < 0 || thing > 999999);

	return thing;
}

string ask_string_secret(string info)
{
	cout << info;
	termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        string thing;
        getline(cin, thing);
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return thing;
}

void print_string(string info)
{
	cout << info;
}

vector<string> ask_all_names(int nodes,string info)
{
        vector<string> names;
        for(int  i=0;i<nodes;i++)
        {
                string name;
                cout << info;
                getline(cin,name);
                names.push_back(name);
        }
        return names;
}
