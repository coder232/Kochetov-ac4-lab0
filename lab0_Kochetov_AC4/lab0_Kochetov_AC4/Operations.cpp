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

void Operations::EditPipe(Pipe& pipe)
{
	cout << "������ \"� �������\" ����� �������, �� �������?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;
	cout << "������� ��� �����: ";
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "������� ������ \"� �������\": ";
		bool pipeRepair = GetCorrectData(false, true);;
		pipe.isUnderRepair = pipeRepair;
		cout << "ID: " << pipe.Id << ": ";
		pipe.PrintRepairStatus();
		break;
	}
	case 2:
	{
		return;
	}
	default:
	{
		cout << "����������,������� ���������� �������!\n" << endl;
		break;
	}
	}
}

void Operations::EditPipes(vector<Pipe*>& pipes)
{
	cout << "\n�� ������ �������� ������ \"� �������\" � ��������� ����?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;
	cout << "������� ��� �����: ";
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "������� ������ \"� �������\" ��� ��������� ����: ";
		bool repSt = GetCorrectData(false, true);

		for (auto& pipe : pipes)
		{
			pipe->isUnderRepair = repSt;
		}
		cout << "\n������ ��� ������� ��� ���� ����!" << endl;
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
			getline(cin, pipeName);
			vector<Pipe*> editPipes;
			for (auto& elem : Pipes)
			{
				if (elem.second.GetKM().find(pipeName) != string::npos)
				{
					cout << elem.second;
					editPipes.push_back(&(elem.second));
				}
			}
			if (editPipes.empty())
				cout << "��� ����� � ����� ������!" << endl;
			else
				EditPipes(editPipes);
		}
		break;
		case 2:
		{
			cout << "������� �����c \"� �������\" ��� �����: ";
			bool repairStatus = GetCorrectData(false, true);
			vector<Pipe*> editPipes;
			for (auto& elem : Pipes)
			{
				if (elem.second.GetRepairStatus() == repairStatus)
				{
					cout << elem.second;
					editPipes.push_back(&(elem.second));
				}
			}
			if (editPipes.empty())
				cout << "��� ����� � ����� ��������!" << endl;
			else
				EditPipes(editPipes);
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

void Operations::EditCStation(CStations& station)
{
	cout << "����� �������� ����� ����� �������, �� �������?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;
	cout << "������� ��� �����: ";
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "������� ����� �������� �����: ";
		station.ActWorkshops = GetCorrectData(1, station.GetWorkshops());
		cout << "ID: " << station.Id << ": ";
		station.PrintWorkshops();
	}
	case 2:
		return;
	default:
	{
		cout << "������� ���������� �������!\n" << endl;
		break;
	}
	}
}

void Operations::EditCStations(vector<CStations*> stations)
{
	cout << "\n�� ����� ������ ����� �������� �����?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;
	cout << "������� ��� �����: ";
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "������� ������� ���������� �����: ";
		float percent = GetCorrectData(0.0, 100.0);
		for (auto& station : stations)
		{
			station->ActWorkshops = round(station->totalWorkshops * (100 - percent) / 100);
		}
		cout << "\n����� �������� ����� ��� ������� ��� ���� ��!" << endl;
		break;
	}
	case 2:
		return;
	default:
		cout << "������� ���������� ������!";
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
			vector<CStations*> editStations;
			for (auto& elem : Stations)
			{
				if (elem.second.GetName().find(stationName) != string::npos)
				{
					cout << elem.second;
					editStations.push_back(&(elem.second));
				}
			}
			if (editStations.empty())
				cout << "��� �� � ����� ������!" << endl;
			else
				EditCStations(editStations);
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
			vector<CStations*> editStations;
			switch (GetCorrectData(1, 3))
			{
			case 1:
			{
				for (auto& elem : Stations)
				{
					if (elem.second.GetPercentOfNonActiveWorkshops() < percent)
					{
						cout << elem.second;
						editStations.push_back(&(elem.second));
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
						editStations.push_back(&(elem.second));
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
						editStations.push_back(&(elem.second));
					}
				}
			}
			break;
			}
			if (editStations.empty())
				cout << "��� �� � ����� ���������!" << endl;
			else
				EditCStations(editStations);
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

