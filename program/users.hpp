#ifndef USERS_HPP
#define USERS_HPP

#include "internal_commands.hpp"

bool vectorisalnum(vector<string>);
bool validate_password(string);
bool check_user_and_email(string,string);
//bool stringisalnum(string);
bool validate_email(string);
bool validate_username(string);
bool confirm_password(string,string);
string cut(string,size_t,size_t);

#endif
