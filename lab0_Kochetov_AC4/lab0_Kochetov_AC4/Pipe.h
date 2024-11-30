#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Pipe
{
private:
	static int maxId;
	int Id;
	string kilometricMark = "Nothing";
	double Length = 0.0;
	int Diameter = 0;
	bool isUnderRepair = false;

public:	
	int GetDiameter() const;
	int GetId();
	string Getname() const;
	bool GetRepairStatus();
	void SetRepairStatus(bool status);
	void PrintRepairStatus();
	void EditPipe();

	friend ostream& operator << (ostream& out, const Pipe& newPipe);
	friend istream& operator >> (istream& in, Pipe& newPipe);
	friend ofstream& operator << (ofstream& fout, const Pipe& newPipe);
	friend ifstream& operator >> (ifstream& flin, Pipe& newPipe);
};
