#pragma once
#include <string>
#include <fstream>
using namespace std;

class CStations
{
private:
	static int maxId;
	int Id;
	string Name = "Nothing";
	int totalWorkshops = 0;
	int ActWorkshops = 0;
	double Efficiency = 0.0;
	int id_in = 0;
	int id_out = 0;
	int shortest_path;

public:
	int GetId();
	string Getname() const;
	int GetWorkshops() const;
	int GetActWorkshops() const;
	int GetPercentOfNonActiveWorkshops() const;
	int Get_Id_in() const;
	int Get_Id_out() const;
	void Set_Id_in(int in);
	void Set_Id_out(int out);
	void SetActWorkshops(int cnt);
	void PrintWorkshops() const;
	void EditCStation();

	friend ostream& operator << (ostream& out, const CStations& newStation);
	friend istream& operator >> (istream& in, CStations& newStation);
	friend ofstream& operator << (ofstream& fout, const CStations& newStation);
	friend ifstream& operator >> (ifstream& flin, CStations& newStation);
};

