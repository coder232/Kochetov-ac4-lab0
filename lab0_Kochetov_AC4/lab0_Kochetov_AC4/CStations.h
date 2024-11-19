#pragma once
#include <string>
#include <fstream>
using namespace std;

class CStations
{
public:
	static int maxId;
	int Id;
	string Name = "Nothing";
	int totalWorkshops = 0;
	int ActWorkshops = 0;
	double Efficiency = 0.0;

	int GetId();
	string GetName() const;
	int GetWorkshops() const;
	int GetActWorkshops() const;
	int GetPercentOfNonActiveWorkshops() const;
	void PrintWorkshops() const;

	friend ostream& operator << (ostream& out, const CStations& newStation);
	friend istream& operator >> (istream& in, CStations& newStation);
	friend ofstream& operator << (ofstream& fout, const CStations& newStation);
	friend ifstream& operator >> (ifstream& flin, CStations& newStation);
};

