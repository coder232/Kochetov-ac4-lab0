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
	cout << "Статус \"В ремонте\" будет изменен, вы уверены?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
	cout << "Введите ваш выбор: ";
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "Введите статус \"в ремонте\": ";
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
		cout << "Пожалуйста,введите корректную команду!\n" << endl;
		break;
	}
	}
}

void Operations::EditPipes(vector<Pipe*>& pipes)
{
	cout << "\nВы хотите изменить статус \"в ремонте\" у выбранных труб?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
	cout << "Введите ваш выбор: ";
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "Введите статус \"в ремонте\" для выбранных труб: ";
		bool repSt = GetCorrectData(false, true);

		for (auto& pipe : pipes)
		{
			pipe->isUnderRepair = repSt;
		}
		cout << "\nСтатус был изменен для всех труб!" << endl;
		break;
	}
	case 2:
		return;
	default:
		cout << "Пожалуйста, введите корректные данные!" << endl;
		break;
	}
}

void Operations::searchPipe(unordered_map<int, Pipe>& Pipes)
{
	while (true)
	{
		cout << "\nВыберите по какому параметру вы хотите искать трубы: " << endl;
		cout << "1. Имя" << endl;
		cout << "2. Статус \"в ремонте\"" << endl;
		cout << "3. Вернуться" << endl;
		cout << "Введите ваш выбор: ";
		switch (GetCorrectData(1, 3))
		{
		case 1:
		{
			string pipeName;
			cout << "\nВведите километровую марку (имя) трубы: ";
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
				cout << "Нет трубы с таким именем!" << endl;
			else
				EditPipes(editPipes);
		}
		break;
		case 2:
		{
			cout << "Введите статуc \"в ремонте\" для трубы: ";
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
				cout << "Нет трубы с таким статусом!" << endl;
			else
				EditPipes(editPipes);
		}
		break;
		case 3:
			return;
		default:
		{
			cout << "Пожалуйста, введите точные данные!" << endl;
			break;
		}
		}
	}
}

void Operations::EditCStation(CStations& station)
{
	cout << "Номер активных цехов будет изменен, вы уверены?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
	cout << "Введите ваш выбор: ";
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "Введите номер активных цехов: ";
		station.ActWorkshops = GetCorrectData(1, station.GetWorkshops());
		cout << "ID: " << station.Id << ": ";
		station.PrintWorkshops();
	}
	case 2:
		return;
	default:
	{
		cout << "Введите корректную команду!\n" << endl;
		break;
	}
	}
}

void Operations::EditCStations(vector<CStations*> stations)
{
	cout << "\nВы точно хотите число активных цехов?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
	cout << "Введите ваш выбор: ";
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "введите процент неактивных цехов: ";
		float percent = GetCorrectData(0.0, 100.0);
		for (auto& station : stations)
		{
			station->ActWorkshops = round(station->totalWorkshops * (100 - percent) / 100);
		}
		cout << "\nНомер активных цехов был изменен для всех КС!" << endl;
		break;
	}
	case 2:
		return;
	default:
		cout << "Введите корректные данные!";
		break;
	}
}

void Operations::searchCStations(unordered_map<int, CStations>& Stations)
{
	while (true)
	{
		cout << "\nВыберите по какому признаку искать КС: " << endl;
		cout << "1. Имя" << endl;
		cout << "2. Процент неактивных цехов" << endl;
		cout << "3. Вернуться" << endl;
		cout << "Введите ваш выбор: ";
		switch (GetCorrectData(1, 3))
		{
		case 1:
		{
			string stationName;
			cout << "Введите имя КС : ";
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
				cout << "Нет КС с таким именем!" << endl;
			else
				EditCStations(editStations);
		}
		break;
		case 2:
		{
			cout << "\nВведите процент неактивных цехов: ";
			int percent = GetCorrectData(0, 100);
			cout << "Какие пределы поиска будут заданы?" << endl;
			cout << "1. Меньше (<%)" << endl;
			cout << "2. Равно (=%)" << endl;
			cout << "3. Больше (>%)" << endl;
			cout << "Пожалуйста, введите ваш выбор: ";
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
				cout << "Нет КС с таким процентом!" << endl;
			else
				EditCStations(editStations);
		}
		break;
		case 3:
			return;
		default:
		{
			cout << "Введите корректные данные!" << endl;
			break;
		}
		}
	}
}

