#include "Utilities.h"
#include <iostream>
#include <string>

string inputString(istream& in) 
{
	string str;
	std::getline(in >> std::ws, str);
	cerr << str << endl; 
	return str;
}
