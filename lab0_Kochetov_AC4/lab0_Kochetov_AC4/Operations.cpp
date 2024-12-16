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

