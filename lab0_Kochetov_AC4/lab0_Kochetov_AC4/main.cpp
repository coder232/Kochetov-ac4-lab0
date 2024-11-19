#include <iostream>
#include <fstream>
#include <cstdlib>  
#include <string>
#include <unordered_map>
#include <chrono>
#include <format>
#include <queue>
#include "Pipe.h"
#include "CStations.h"
#include "Operations.h"
#include "Utilities.h"
using namespace std;
using namespace chrono;

int main()
{
	//setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	redirect_output_wrapper cerr_out(cerr);
	string time = format("{:%d_%m_%Y %H_%M_%OS}", system_clock::now() + hours(3));
	ofstream logfile("log_" + time);
	if (logfile)
		cerr_out.redirect(logfile);

	Pipe pipe0;
	CStations station0;
	unordered_map<int, Pipe> Pipes = {};
	unordered_map<int, CStations> Stations = {};
	Operations operations;

	int num = 0;
	while (true) {
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
		switch (GetCorrectData(0, 10))
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
			if (Pipes.size() == 0)
				cout << "\n0 ���� ���� ���������!" << endl;
			for (const auto& elem : Pipes)
				cout << elem.second;

			if (Stations.size() == 0)
				cout << "\n0 ������� ���� ���������!" << endl;
			for (const auto& elem : Stations)
				cout << elem.second;
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
				int indPipes = Pipes.size();
				Pipe& pipe0 = SelectElement(Pipes, GetCorrectData(1, indPipes));
				operations.EditPipe(pipe0);
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
				int indStations = Stations.size();
				CStations& station0 = SelectElement(Stations, GetCorrectData(1, indStations));
				operations.EditCStation(station0);
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
				cin >> key0;
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
				cin >> key0;
				removeKeyIfExists(Stations, key0);
			}
			break;
		}
		case 8:
		{
			cout << "\n[8] ���������� � ����" << endl;
			ofstream fout;
			string fileName;
			cout << "����������, ������� ��� �����: ";
			cin.ignore();
			getline(cin, fileName);
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
			break;
		}
		case 9:
		{
			cout << "\n[9] �������� �� �����" << endl;
			ifstream fin;
			string fileName;
			cout << "����������, ������� ��� �����: ";
			cin.ignore();
			getline(cin, fileName);
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
			break;
		}
		case 10:
		{
			bool flag = true;
			while (flag) {
				cout << "\n[10] �����" << endl;
				cout << "��� �� ������ �����?" << endl;
				cout << "1. �����" << endl;
				cout << "2. ��" << endl;
				cout << "3. ���������" << endl;
				cout << "������� �������: ";
				switch (GetCorrectData(1, 3))
				{
				case 1:
					cout << "\n����� ����..." << endl;
					operations.searchPipe(Pipes);
					break;
				case 2:
					cout << "\n����� ��..." << endl;
					operations.searchCStations(Stations);
					break;
				case 3:
					flag = false;
					break;
				default:
					cout << "����������, ������� ������ �������!" << endl;
					break;
				}
			}
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

