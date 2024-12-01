#include "Operations.h"
#include "Pipe.h"
#include "CStations.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void Operations::EditPipes(unordered_map<int, Pipe>& pipes, const unordered_set<int>& selectedPipes) {
	cout << "\n�� ������ �������� ������ \"� �������\" � ��������� ����?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;
	cout << "������� ��� �����: ";

	switch (GetCorrectData(1, 3)) {
	case 1: {
		cout << "������� ������ \"� �������\" ��� ��������� ����: ";
		bool repSt = GetCorrectData(false, true);

		for (int id : selectedPipes) {
			auto it = pipes.find(id);
			if (it != pipes.end()) {
				it->second.SetRepairStatus(repSt);
			}
		}
		cout << "\n������ ��� ������� ��� ��������� ����!" << endl;
		break;
	}
	case 2:
		return;

	default:
		cout << "����������, ������� ���������� ������!" << endl;
		break;
	}
}

void Operations::searchPipe(unordered_map<int, Pipe>& Pipes)
{
	while (true)
	{
		cout << "\n�������� �� ������ ��������� �� ������ ������ �����: " << endl;
		cout << "1. ���" << endl;
		cout << "2. ������ \"� �������\"" << endl;
		cout << "3. ���������" << endl;
		cout << "������� ��� �����: ";
		switch (GetCorrectData(1, 3))
		{
		case 1:
		{
			string pipeName;
			cout << "\n������� ������������ ����� (���) �����: ";
			cin.ignore();
			getline(cin, pipeName);//!!!!!!!!!!!!!!!!!!!!!!
			unordered_map<int, Pipe> searchPipes;
			for (auto& elem : Pipes)
			{
				if (elem.second.Getname().find(pipeName) != string::npos)
				{
					cout << elem.second;
					searchPipes[elem.first] = elem.second;
				}
			}	
			if (searchPipes.empty())
				cout << "��� ����� � ����� ������!" << endl;
			//else
				//EditPipes(searchPipes);
		}
		break;
		case 2:
		{
			cout << "������� �����c \"� �������\" ��� �����: ";
			bool repairStatus = GetCorrectData(false, true);
			unordered_map<int, Pipe> searchPipes;
			for (auto& elem : Pipes)
			{
				if (elem.second.GetRepairStatus() == repairStatus)
				{
					cout << elem.second;
					searchPipes[elem.first] = elem.second;
				}
			}
			if (searchPipes.empty())
				cout << "��� ����� � ����� ��������!" << endl;
			//else
				//EditPipes(searchPipes);
		}
		break;
		case 3:
			return;
		default:
		{
			cout << "����������, ������� ������ ������!" << endl;
			break;
		}
		}
	}
}

void Operations::EditCStations(unordered_map<int, CStations>& stations, unordered_set<int>& selected_stations) {
	cout << "\n�� ����� ������ �������� ����� �������� �����?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;
	cout << "������� ��� �����: ";
	switch (GetCorrectData(1, 2)) {
	case 1: {
		cout << "������� ������� ���������� �����: ";
		float percent = GetCorrectData(0.0f, 100.0f);
		for (int id : selected_stations) {
			auto it = stations.find(id);
			if (it != stations.end()) {
				int totalWorkshops = it->second.GetWorkshops();
				int activeWorkshops = round(totalWorkshops * (100 - percent) / 100.0f);
				it->second.SetActWorkshops(activeWorkshops);
			}
		}
		cout << "\n����� �������� ����� ���� �������� ��� ���� ��!" << endl;
		break;
	}
	case 2:
		return;
	default:
		cout << "������� ���������� ������!" << endl;
		break;
	}
}

void Operations::searchCStations(unordered_map<int, CStations>& Stations)
{
	while (true)
	{
		cout << "\n�������� �� ������ �������� ������ ��: " << endl;
		cout << "1. ���" << endl;
		cout << "2. ������� ���������� �����" << endl;
		cout << "3. ���������" << endl;
		cout << "������� ��� �����: ";
		switch (GetCorrectData(1, 3))
		{
		case 1:
		{
			string stationName;
			cout << "������� ��� �� : ";
			cin.ignore();
			getline(cin, stationName);
			unordered_map<int, CStations> searchStations;
			for (auto& elem : Stations)
			{
				if (elem.second.Getname().find(stationName) != string::npos)
				{
					cout << elem.second;
					searchStations[elem.first] = elem.second;
				}
			}
			if (searchStations.empty())
				cout << "��� �� � ����� ������!" << endl;
			//else
				//EditCStations(searchStations);
		}
		break;
		case 2:
		{
			cout << "\n������� ������� ���������� �����: ";
			int percent = GetCorrectData(0, 100);
			cout << "����� ������� ������ ����� ������?" << endl;
			cout << "1. ������ (<%)" << endl;
			cout << "2. ����� (=%)" << endl;
			cout << "3. ������ (>%)" << endl;
			cout << "����������, ������� ��� �����: ";
			unordered_map<int, CStations> searchStations;
			switch (GetCorrectData(1, 3))
			{
			case 1:
			{
				for (auto& elem : Stations)
				{
					if (elem.second.GetPercentOfNonActiveWorkshops() < percent)
					{
						cout << elem.second;
						searchStations[elem.first] = elem.second;
					}
				}
			}
			break;
			case 2:
			{
				for (auto& elem : Stations)
				{
					if (elem.second.GetPercentOfNonActiveWorkshops() == percent)
					{
						cout << elem.second;
						searchStations[elem.first] = elem.second;
					}
				}
			}
			break;
			case 3:
			{
				for (auto& elem : Stations)
				{
					if (elem.second.GetPercentOfNonActiveWorkshops() > percent)
					{
						cout << elem.second;
						searchStations[elem.first] = elem.second;
					}
				}
			}
			break;
			}
			if (searchStations.empty())
				cout << "��� �� � ����� ���������!" << endl;
			//else
				//EditCStations(searchStations);
		}
		break;
		case 3:
			return;
		default:
		{
			cout << "������� ���������� ������!" << endl;
			break;
		}
		}
	}
}

