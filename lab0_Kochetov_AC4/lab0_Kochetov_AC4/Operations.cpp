#include "Operations.h"
#include "Pipe.h"
#include "CStations.h"
#include "Utilities.h"
#include "Connections.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void Operations::EditPipes(unordered_map<int, Pipe>& pipes, const unordered_set<int>& selectedPipes, unordered_map<int, CStations>& Stations, unordered_map<int, vector<connections>>& Conns) {
    cout << "\n�� ������ �������� ������ \"� �������\" � ��������� ���� ��� ������� ��?" << endl;
    cout << "1. �������� ������ \"� �������\"" << endl;
    cout << "2. ������� �����" << endl;
    cout << "3. ������ �� ������" << endl;
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
    case 2: {
        for (int id : selectedPipes) {
            auto it = pipes.find(id);
            if (it != pipes.end()) {
                // Iterate through the vector of connections
                for (auto& connVec : Conns) {
                    auto& connList = connVec.second;  // Get the vector of connections
                    for (auto connIt = connList.begin(); connIt != connList.end(); ) {
                        if (connIt->id_pipe == id) {
                            cout << "���������� ����, ��� ���������� ��� �����. ���������� �������� ����..." << endl;
                            int id_entry = connIt->id_entry;
                            int id_out = connIt->id_out;

                            Stations[id_entry].Set_Id_in(Stations[id_entry].Get_Id_in() - 1);
                            Stations[id_out].Set_Id_out(Stations[id_out].Get_Id_out() - 1);
                            connIt = connList.erase(connIt);  // Erase the connection from the vector
                        }
                        else {
                            ++connIt;
                        }
                    }
                }
                pipes.erase(it);
                cout << "����� � ID " << id << " ���� ������� �� �������." << endl;
            }
            else {
                cout << "����� � ID " << id << " �� �������." << endl;
            }
        }
        cout << "\n��������� ����� ���� �������!" << endl;
        break;
    }
    case 3:
        return;

    default:
        cout << "����������, ������� ���������� ������!" << endl;
        break;
    }
}



void Operations::EditCStations(unordered_map<int, CStations>& stations, unordered_set<int>& selected_stations, unordered_map<int, Pipe>& Pipes, unordered_map<int, vector<connections>>& Conns) {
    cout << "\n�� ������ �������� ����� �������� ����� ��� ������� ��������� ��?" << endl;
    cout << "1. �������� ����� �������� �����" << endl;
    cout << "2. ������� ��������� ��" << endl;
    cout << "3. ������ �� ������" << endl;
    cout << "������� ��� �����: ";

    switch (GetCorrectData(1, 3)) {
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
        cout << "\n����� �������� ����� ���� �������� ��� ���� ��������� ��!" << endl;
        break;
    }
    case 2: {
        for (int id : selected_stations) {
            auto it = stations.find(id);
            if (it != stations.end()) {
                // Iterate through the vector of connections
                for (auto& connVec : Conns) {
                    auto& connList = connVec.second;  // Get the vector of connections
                    for (auto connIt = connList.begin(); connIt != connList.end(); ) {
                        if (connIt->id_entry == id || connIt->id_out == id) {
                            int pipe_id = connIt->id_pipe;
                            Pipes.erase(pipe_id);  // Remove the associated pipe
                            connIt = connList.erase(connIt);  // Erase the connection from the vector
                        }
                        else {
                            ++connIt;
                        }
                    }
                }
                stations.erase(it);
                cout << "�� � ID " << id << " ���� ������� �� �������." << endl;
            }
            else {
                cout << "�� � ID " << id << " �� �������." << endl;
            }
        }
        cout << "\n��������� �� ���� �������!" << endl;
        break;
    }
    case 3:
        return;

    default:
        cout << "������� ���������� ������!" << endl;
        break;
    }
}



