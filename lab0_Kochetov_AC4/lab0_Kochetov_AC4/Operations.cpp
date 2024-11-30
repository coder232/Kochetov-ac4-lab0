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

void Operations::EditPipes(unordered_map<int, Pipe>& pipes)
{
	cout << "\nВы хотите изменить статус \"в ремонте\" у выбранных труб?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
	cout << "3. Изменить часть найденных" << endl;
	cout << "Введите ваш выбор: ";
	switch (GetCorrectData(1, 3))
	{
	case 1:
	{
		cout << "Введите статус \"в ремонте\" для выбранных труб: ";
		bool repSt = GetCorrectData(false, true);

		for (auto& [id, p] : pipes)
		{
			p.SetRepairStatus(repSt);
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
				cout << "Нет трубы с таким именем!" << endl;
			else
				EditPipes(searchPipes);
		}
		break;
		case 2:
		{
			cout << "Введите статуc \"в ремонте\" для трубы: ";
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
				cout << "Нет трубы с таким статусом!" << endl;
			else
				EditPipes(searchPipes);
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

void Operations::EditCStations(unordered_map<int, CStations>& stations) {
	cout << "\nВы точно хотите изменить число активных цехов?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
	cout << "Введите ваш выбор: ";
	switch (GetCorrectData(1, 2)) {
	case 1: {
		cout << "Введите процент неактивных цехов: ";
		float percent = GetCorrectData(0.0, 100.0);
		for (auto& [id, st] : stations) {
			st.SetActWorkshops(round(st.GetWorkshops() * (100 - percent) / 100));
		}
		cout << "\nЧисло активных цехов было изменено для всех КС!" << endl;
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
				cout << "Нет КС с таким именем!" << endl;
			else
				EditCStations(searchStations);
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
				cout << "Нет КС с таким процентом!" << endl;
			else
				EditCStations(searchStations);
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

