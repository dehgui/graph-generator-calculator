#include "users.hpp"

bool vectorisalnum(vector<string> things)
{
	for(int i = 0; i < things.size(); i++)
		for(int j = 0; j < things.at(i).size(); j++)
			if(!isalnum(things.at(i).at(j)))
				return false;

	return true;
}

bool validate_password(string password)
{
	if(password.size() < 8 || string::npos == password.find_first_of("0123456789") || string::npos != password.find("#"))
        {
                print_string("Invalid password!\n");
                return false;
        }
	else
		return true;
}

/*bool stringisalnum(string thing)
{
	for(int i = 0; i < thing.size(); i++)
		if( !isalnum(thing.at(i)))
		{
			print_string("Type only letters and numbers!\n");
			return false;
		}
	return true;
}*/

bool validate_email(string email)
{
	size_t a_local = email.find("@",1,1);
	size_t p_local = email.find(".",a_local+2,1);
	
	if(check_data("data/users.txt",email,1))
	{
        	print_string("Email already registered!\n");
		return false;
	}
	else
	{
		if(a_local != string::npos && p_local != string::npos && email.find_first_of("#$&*") == string::npos && p_local != (email.size() - 1) && email.at(email.size() - 1) != '.')
			if(vectorisalnum(split(cut(email,a_local,email.size()),'.')))
				return true;

			print_string("Invalid email!\n");
			return false;
	}
}

bool validate_username(string username)
{
	if(username.size() == 0)
		return false;

	if(username.find_first_of("#&$*") != string::npos)
	{
		print_string("Invalid name! \n");
		return false;
	}

	return true;
}

bool confirm_password(string password, string email)
{
	if(pick_string_from_data("data/users.txt",email,2) == password)
		return true;
	else
		return false;
}

string cut(string message,size_t begin,size_t limit)
{
	string thing = "";
	for(int i = limit-1; i > begin; i--)
		thing+=message.at(i);

	return thing;
}
