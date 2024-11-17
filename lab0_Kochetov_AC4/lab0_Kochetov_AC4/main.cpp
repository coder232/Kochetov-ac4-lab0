#include <iostream>
#include <string>
#include "windows.h"
#include <fstream> 
#include "Pipe.h"
#include "CStations.h"
#include <vector>

using namespace std;

void saveToFile(const vector<Pipe>& pipes, const vector<CompressorStation>& cs) {
    ofstream fout("saved_Pipe_CS.txt");
    if (fout) {
        if (pipes.size() == 0)
            cout << "��� ���� ��� ��������" << endl;
        else {
            fout << pipes.size() << endl;
            for (const auto& p : pipes) {
                p.save(fout);
            }
        }
        if (cs.size() == 0)
            cout << "��� �� ��� ��������" << endl;
        else {
            fout << cs.size() << endl;
            for (const auto& CS : cs) {
                CS.save(fout);
            }
        }
    
        cout << "���� ���������: " << pipes.size() << endl
            << "�� ��������� = " << cs.size() << endl;
    }
    else {
        cout << "������ �������� �����" << endl;
    }
}

void loadFromFile(Pipe& p, CompressorStation& cs) {
    std::ifstream fin("saved_Pipe_CS.txt");
    if (fin) {
        int npipe, nCS;
        fin >> npipe;
        if (npipe > 0) p.load(fin);
        else p = Pipe();

        fin >> nCS;
        if (nCS > 0) cs.load(fin);
        else cs = CompressorStation();

        cout << "Pipe loaded = " << npipe << endl
            << "CS loaded = " << nCS << endl;
    }
    else {
        cout << "������ ��������" << endl;
    }
}
void pipeCScheck(const vector<CompressorStation>& station, const vector<Pipe>&  pipes) {
    if (pipes.size() == 0) {
        cout << "����������� �����" << endl;
    }
    else {
        for (size_t i = 0; i < pipes.size(); ++i) {
            cout << i + 1 << ". ����� " << i + 1 << endl;
        }
    }
    if (station.size() == 0) {
        cout << "����������� ��" << endl;
    }
    else {
        for (const auto& Station : station) {
            Station.CS_info();
            cout << endl;
        }
    }
}

int main() {
    vector<CompressorStation> station;
    vector<Pipe>  pipes;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    LOG::Logger logger("logfile.txt"); // �������� ���������� �������
    logger.log(LOG::INFO, "Program started."); // ������ �����������
    while (1) {
        cout << "����:" << endl;
        cout << "1. �������� �����" << endl;
        cout << "2. ������������� �����" << endl;
        cout << "3. ����������� ���������� � ������ � ��" << endl;
        cout << "4. �������� ������������� �������" << endl;
        cout << "5. ������������� ������������� �������" << endl;
        cout << "6. ��������� ���������� � ������ � �� � ����" << endl;
        cout << "7. ��������� ���������� � ������ � �� �� �����" << endl;
        cout << "8. ����� �� ��������� \n" << endl;

        int choice;//!!!
        while (true) {
            cout << "������� ����� ������ ����: ";
            choice = check_int(0, 0);
            break;
        }


        switch (choice) {
        case 1:
        {
            Pipe newPipes = Pipe::addPipe();
            pipes.push_back(newPipes);
            break;
        }
        case 2:
        {
            // ����� ����� ��� ��������������
            int index;
            cout << "������� ����� ����� ��� ��������������: ";
            cin >> index;
            if (index > 0 && index <= pipes.size()) {
                pipes[index - 1].editPipe(); // ����������� ��������� �����
            }
            else {
                cout << "�������� ����� �����." << endl;
            }
            break;
        }
        case 3:
        {
            pipeCScheck(pipes, station);
            break;
        }
        case 4:
        {
            CompressorStation newst = CompressorStation::Add_station();
            station.push_back(newst);
            break;
        }
        case 5:
        {
            for (size_t i = 0; i < station.size(); ++i) {
                cout << i + 1 << ". �� " << i + 1 << endl;
            }
            int index;
            cout << "������� ����� �� ��� ��������������: ";
            cin >> index;
            if (index > 0 && index <= station.size()) {
                station[index - 1].editCS(); // ����������� ��������� �����
            }
            else {
                cout << "�������� ����� KC." << endl;
            }
            break;
        }
        case 6:
        {
        
        saveToFile(pipes, station);
        break;
        }
        case 7:
        {
        //loadFromFile(pipes, station);
        break;
        }
        case 8:
        {
            return 0;
            break;
        }
        default: {
            cout << "�������� �����. ���������� ��� ���. \n" << endl;
            break;
        }
        }

    }
    return 0;
}