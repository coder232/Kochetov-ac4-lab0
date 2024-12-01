#include <iostream>
#include <fstream>
#include <cstdlib>  
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <format>
#include <queue>
#include "Pipe.h"
#include "CStations.h"
#include "Operations.h"
#include "Utilities.h"
#include "filtherr.h"
using namespace std;
using namespace chrono;

int MainMenu()
{
	cout << endl << "����:" << endl;
	cout << "1. �������� �����" << endl;
	cout << "2. �������� ��" << endl;
	cout << "3. �������� ��� �������" << endl;
	cout << "4. ������������� �����" << endl;
	cout << "5. ������������� ��" << endl;
	cout << "6. ������� �����" << endl;
	cout << "7. ������� ��" << endl;
	cout << "8. ���������" << endl;
	cout << "9. ���������" << endl;
	cout << "10. ����� �� �������" << endl;
	cout << "0. �����" << endl;
	cout << endl << "����������, ������� ����� �������: ";
	return GetCorrectData(0, 10);
}

void save_d(unordered_map<int, Pipe>& Pipes, unordered_map<int, CStations>& Stations) {
	cout << "\n[8] ���������� � ����" << endl;
	ofstream fout;
	string fileName;
	cout << "����������, ������� ��� �����: ";
	cin.ignore();
	getline(cin, fileName);///!!!!!!!!!!!!!!!!
	fout.open(fileName);
	if (!fout.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else {
		fout << Pipes.size() << endl;
		for (const auto& elem : Pipes)
			fout << elem.second;
		cout << "������ � ������ ���� ������� ���������!" << endl;

		fout << Stations.size() << endl;
		for (const auto& elem : Stations)
			fout << elem.second;
		cout << "������ � �� ��� ������� ���������!" << endl;
	}
	fout.close();
}
void load_d(unordered_map<int, Pipe>& Pipes, unordered_map<int, CStations>& Stations) {
	cout << "\n[9] �������� �� �����" << endl;
	ifstream fin;
	string fileName;
	cout << "����������, ������� ��� �����: ";
	cin.ignore();
	getline(cin, fileName);//!!!!!!!!!!!!!
	fin.open(fileName);
	if (!fin.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else {
		int pipesSize;
		fin >> pipesSize;
		if (pipesSize == 0)
			cout << "��� ���������� � ������!" << endl;
		else {
			cout << "������ � ������ ���� ������� ���������!" << endl;
		}
		while (pipesSize-- > 0)
		{
			Pipe pipe0;
			fin >> pipe0;
			Pipes.insert({ pipe0.GetId(), pipe0 });
		}

		int csSize;
		fin >> csSize;
		if (csSize == 0)
			cout << "��� ���������� � ��!" << endl;
		else {
			cout << "������ � �� ���� ������� ���������!" << endl;
		}
		while (csSize-- > 0)
		{
			CStations station0;
			fin >> station0;
			Stations.insert({ station0.GetId(), station0 });
		}
		fin.close();
	}
}
void filtering(unordered_map<int, Pipe>& Pipes, unordered_map<int, CStations>& Stations, Operations& operations) {
	bool flag = true;
	while (flag) {
		cout << "\n[10] �����" << endl;
		cout << "��� �� ������ �����?" << endl;
		cout << "1. �����" << endl;
		cout << "2. ��" << endl;
		cout << "3. ���������" << endl;
		cout << "������� �������: ";
		int cm = GetCorrectData(1, 3);
		unordered_set<int> nameResults;
		switch (cm) {
		case 1: {
			nameResults = selectByChosenFilter(Pipes);
			if (nameResults.empty()) {
				cout << "��� ���� � ����� ������!" << endl;
			}
			else {
				cout << "������� �����:" << endl;
				// ����� ��������������� ��������� ����
				for (int id : nameResults) {
					auto it = Pipes.find(id);
					if (it != Pipes.end()) {
						cout << "����� � ID " << id << ": ";
						cout << it->second;
					}
				}
				cout << endl;
				operations.EditPipes(Pipes, nameResults);
			}
			break;
		}
		case 2: {
			cout << "\n����� ��..." << endl;
			nameResults = selectByChosenFilter(Stations);
			if (nameResults.empty()) {
				cout << "��� �� � ����� ������!" << endl;
			}
			else {
				cout << "������� ��:" << endl;
				for (int id : nameResults) {
					auto it = Stations.find(id);
					if (it != Stations.end()) {
						cout << "KC � ID " << id << ": ";
						cout << it->second;
					}
				}
				cout << endl;
				operations.EditCStations(Stations, nameResults);
			}
			break;
		}
		case 3:
			flag = false;
			break;
		default:
			cout << "����������, ������� ������ �������!" << endl;
			break;
		}
	}
}

using std::cin;
using std::cout;

int main()
{
	system("chcp 1251");
	redirect_output_wrapper cerr_out(cerr);
	string time = format("{:%d_%m_%Y %H_%M_%OS}", system_clock::now() + hours(3));
	ofstream logfile("log_" + time);
	if (logfile) {
		cerr_out.redirect(logfile);
		//cout << endl << "CIN:" << endl;
		//cin_out.redirect(logfile);
	}
	unordered_map<int, Pipe> Pipes = {};
	unordered_map<int, CStations> Stations = {};
	Operations operations;
	while (true) {
		switch (MainMenu())
		{
		case 1:
		{
			cout << "\n[1] ���������� ����� �����..." << endl;
			Pipe pipe0;
			cin >> pipe0;
			Pipes.insert({ pipe0.GetId(), pipe0 });
			break;
		}
		case 2:
		{
			cout << "\n[2] ���������� ����� ��..." << endl;
			CStations station0;
			cin >> station0;
			Stations.insert({ station0.GetId(), station0 });
			break;
		}
		case 3:
		{
			cout << "\n[3] �������� ��� �������: " << endl;
			
			Operations::Show(Pipes);
			Operations::Show(Stations);
			break;
		}
		case 4:
		{
			if (Pipes.size() == 0) {
				cout << "\n0 ���� ��������!" << endl;
			}
			else {
				cout << "\n[4] �������������� �����: " << endl;
				cout << "������� ID: ";
				int id;
				while (true) {
					id = GetCorrectData(1, numeric_limits<int>::max());
					if (Pipes.find(id) != Pipes.end())
						break;
					else
						cout << "����� � ����� id �� ����������, ���������� ��� ���!" << endl;
				}
				Pipe& pipe0 = SelectElement(Pipes, id);
				pipe0.EditPipe();
			}
			break;
		}
		case 5:
		{
			if (Stations.size() == 0) {
				cout << "\n0 �� ��������!" << endl;
			}
			else {
				cout << "\n[5] �������������� ��: " << endl;
				cout << "������� ID: ";
				int id;
				while (true) {
					id = GetCorrectData(1, numeric_limits<int>::max());
					if (Stations.find(id) != Stations.end())
						break;
					else
						cout << "�� � ����� id �� ����������, ���������� ��� ���!" << endl;
				}
				CStations& station0 = SelectElement(Stations, id);
				station0.EditCStation();
			}
			
			break;
		}
		case 6:
		{
			if (Pipes.size() == 0) {
				cout << "\n0 ���� ��������!" << endl;
			}
			else {
				cout << "\n[6] �������� �����: " << endl;
				cout << "������� ID: ";
				int key0;
				cin >> key0;///!!!!!!!!!!!!!!!!!
				removeKeyIfExists(Pipes, key0);
			}
			break;
		}
		case 7:
		{
			if (Stations.size() == 0) {
				cout << "\n0 ������� ��������!" << endl;
			}
			else {
				cout << "\n[7] �������� �������: " << endl;
				cout << "������� ID: ";
				int key0;
				cin >> key0;//!!!!!!!!!!!!
				removeKeyIfExists(Stations, key0);
			}
			break;
		}
		case 8:
		{
			save_d(Pipes, Stations);
			break;
		}
		case 9:
		{
			load_d(Pipes, Stations);
			break;
		}
		case 10:
		{
			filtering(Pipes, Stations, operations);
			break;
		}
		case 0:
		{
			return false;
			break;
		}
		default:
		{
			cout << endl << "� ������� ��� ����� �������, ���������� ��� ���" << endl;
			break;
		}
		}
	}
	return 0;
}

