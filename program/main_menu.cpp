#include "main_menu.hpp"

void show_menu()
{
	system("clear");
	int option;
	do{
		print_string("____GRAPH____\nA CPE PROJECT\n\n");
		print_string("(1) Sign up\n(2) Log in\n(0) Exit.\n");
		option = ask_int("");
		cin.ignore();
		system("clear");
		execute(option);

	}while(option != 0);
}

void execute(int option)
{
	switch(option)
	{
		case 0: break;
		case 1: Sign_Up();
			break;
		case 2: Log_in();
			break;
		default: print_string("Invalid option!\n");
	}
}

void Sign_Up()
{
	string full_user;
	print_string("Enter your details.\nYour password must contain at least 8 characters, including at least one digit.\n\n");
	string user, email, password;
	do{
		user = ask_string("Display name: ");
	}while(!validate_username(user)); 
	
	do{
		email = ask_string("Email: ");
	}while(!validate_email(email));

	do{
		password = ask_string_secret("Password: ");
	}while(!validate_password(password));

	full_user = making_user(password, email, user);
	print_string("\n");

	system("clear");

	write_in_file("data/users.txt",full_user);
}

void Log_in()
{
	string email, password;
	do{
		email = ask_string("Email: ");
		if(!check_data("data/users.txt",email,1))
				print_string("Invalid email!\n");
	}while(!check_data("data/users.txt",email,1));
	
	do{
		password = ask_string_secret("Password: ");
		if(!confirm_password(password,email))
			print_string("Invalid password!\n");
	}while(!confirm_password(password,email));

	system("clear");
	menu(get_user_in_data(email),email);
}
