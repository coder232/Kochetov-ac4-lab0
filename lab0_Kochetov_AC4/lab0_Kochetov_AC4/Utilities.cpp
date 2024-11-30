#include "Utilities.h"
#include <iostream>
#include <string>

string inputString(istream& in) // string input for whole line
//string inputString(istream& in, const string& exeption)
{
	string str;
	std::getline(in >> std::ws, str);
	/*if (exeption != "")
		while (str == exeption)
		{
			cout << "ERROR wrong name " << exeption << " --> try again: ";
			cerr << str << endl;
			getline(in >> ws, str);
		}*/
	cerr << str << endl; // LOGGING!!!!!!!
	return str;
}
