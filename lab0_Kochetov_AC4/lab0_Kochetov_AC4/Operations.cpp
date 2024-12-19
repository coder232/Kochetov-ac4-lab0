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
    cout << "\nВы хотите изменить статус \"в ремонте\" у выбранных труб или удалить их?" << endl;
    cout << "1. Изменить статус \"в ремонте\"" << endl;
    cout << "2. Удалить трубы" << endl;
    cout << "3. Ничего не делать" << endl;
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
    case 2: {
        for (int id : selectedPipes) {
            auto it = pipes.find(id);
            if (it != pipes.end()) {
                // Iterate through the vector of connections
                for (auto& connVec : Conns) {
                    auto& connList = connVec.second;  // Get the vector of connections
                    for (auto connIt = connList.begin(); connIt != connList.end(); ) {
                        if (connIt->id_pipe == id) {
                            cout << "Обнаружена сеть, где содержится эта труба. Происходит удаление сети..." << endl;
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
                cout << "Труба с ID " << id << " была удалена из системы." << endl;
            }
            else {
                cout << "Труба с ID " << id << " не найдена." << endl;
            }
        }
        cout << "\nВыбранные трубы были удалены!" << endl;
        break;
    }
    case 3:
        return;

    default:
        cout << "Пожалуйста, введите корректные данные!" << endl;
        break;
    }
}



void Operations::EditCStations(unordered_map<int, CStations>& stations, unordered_set<int>& selected_stations, unordered_map<int, Pipe>& Pipes, unordered_map<int, vector<connections>>& Conns) {
    cout << "\nВы хотите изменить число активных цехов или удалить выбранные КС?" << endl;
    cout << "1. Изменить число активных цехов" << endl;
    cout << "2. Удалить выбранные КС" << endl;
    cout << "3. Ничего не делать" << endl;
    cout << "Введите ваш выбор: ";

    switch (GetCorrectData(1, 3)) {
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
        cout << "\nЧисло активных цехов было изменено для всех выбранных КС!" << endl;
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
                cout << "КС с ID " << id << " была удалена из системы." << endl;
            }
            else {
                cout << "КС с ID " << id << " не найдена." << endl;
            }
        }
        cout << "\nВыбранные КС были удалены!" << endl;
        break;
    }
    case 3:
        return;

    default:
        cout << "Введите корректные данные!" << endl;
        break;
    }
}



