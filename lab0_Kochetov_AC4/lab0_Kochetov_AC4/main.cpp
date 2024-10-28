#include <iostream>
#include <string>
#include "windows.h"
#include <fstream> 
#include "Pipe.h"
#include "CStation.h"
#include "LOG.h"

using namespace std;
using namespace pipe;
using namespace CStation;

void saveToFile(const Pipe& p, const CompressorStation& cs) {
    std::ofstream fout("saved_Pipe_CS.txt");
    if (fout) {
        int npipe = (p.getMark() == "Nothing") ? 0 : 1;
        fout << npipe << endl;
        if (npipe > 0) p.save(fout);

        int nCS = (cs.getName() == "Nothing") ? 0 : 1;
        fout << nCS << endl;
        if (nCS > 0) cs.save(fout);

        cout << "����� ��������� = " << npipe << endl
            << "�� ��������� = " << nCS << endl;
    }
    else {
        cout << "������ �������� � ����" << endl;
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


int main() {
    CompressorStation station;
    Pipe pipes;
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
            pipes = Pipe::addPipe();
            break;
        }
        case 2:
        {
            pipes.editPipe();
            break;
        }
        case 3:
        {

            pipes.pipe_info();
            cout << "\n" << endl;
            station.CS_info();
            break;
        }
        case 4:
        {
            station = CompressorStation::Add_station();
            break;
        }
        case 5:
        {
            station.editCS();
            break;
        }
        case 6:
        {
        saveToFile(pipes, station);
        break;
        }
        case 7:
        {
        loadFromFile(pipes, station);
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