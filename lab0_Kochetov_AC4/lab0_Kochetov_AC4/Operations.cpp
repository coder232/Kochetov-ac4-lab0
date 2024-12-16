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
	cout << "\nВы хотите изменить статус \"в ремонте\" у выбранных труб?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
	cout << "Введите ваш выбор: ";

	switch (GetCorrectData(1, 3)) {
	case 1: {
		cout << "Введите статус \"в ремонте\" для выбранных труб: ";
		bool repSt = GetCorrectData(false, true);

		for (int id : selectedPipes) {
			auto it = pipes.find(id);
			if (it != pipes.end()) {
				it->second.SetRepairStatus(repSt);
			}
		}
		cout << "\nСтатус был изменен для выбранных труб!" << endl;
		break;
	}
	case 2:
		return;

	default:
		cout << "Пожалуйста, введите корректные данные!" << endl;
		break;
	}
}


void Operations::EditCStations(unordered_map<int, CStations>& stations, unordered_set<int>& selected_stations) {
	cout << "\nВы точно хотите изменить число активных цехов?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
	cout << "Введите ваш выбор: ";
	switch (GetCorrectData(1, 2)) {
	case 1: {
		cout << "Введите процент неактивных цехов: ";
		float percent = GetCorrectData(0.0f, 100.0f);
		for (int id : selected_stations) {
			auto it = stations.find(id);
			if (it != stations.end()) {
				int totalWorkshops = it->second.GetWorkshops();
				int activeWorkshops = round(totalWorkshops * (100 - percent) / 100.0f);
				it->second.SetActWorkshops(activeWorkshops);
			}
		}
		cout << "\nЧисло активных цехов было изменено для всех КС!" << endl;
		break;
	}
	case 2:
		return;
	default:
		cout << "Введите корректные данные!" << endl;
		break;
	}
}

