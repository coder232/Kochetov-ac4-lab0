#include <iostream>
#include <string>
#include "windows.h"
#include <vector>
#include <fstream> 
#include <csignal>

struct Pipe {
    std::string kilometricMark = "Nothing"; // ������������ ������� 
    double length = 0.0; // �����, ��
    int diameter = 0; // �������, ��
    bool isUnderRepair = false; // ������� "� �������"
};
struct CompressorStation {
    std::string name = "Nothing"; //�������� ������������� �������
    int totalShops = 0; // ����� ���������� �����
    int activatedShops = 0; // ���������� ����� � ������
    double efficiency = 0.0; // ������������� (���������� ����������)
};
Pipe addPipe() {
    Pipe newPipe;
    std::cout << "������� ������������ �������: ";
    std::cin.ignore(); // ������� ������ �����
    std::getline(std::cin, newPipe.kilometricMark);

    std::cout << "������� ����� ����� (��): ";
    std::cin >> newPipe.length;

    std::cout << "������� ������� ����� (��): ";
    std::cin >> newPipe.diameter;

    std::cout << "������� �� ������� (0 - ���, 1 - ��): ";
    int repairStatus;
    std::cin >> repairStatus;
    newPipe.isUnderRepair = (repairStatus == 1);

    
    std::cout << "����� ������� ���������." << std::endl;
    return newPipe;
}
CompressorStation Add_station() { //2. �������� �� 
    CompressorStation new_station;
    std::cout << "�������� ���� ��: " << std::endl;
    std::cin >> new_station.name;
    std::cout << "������� ���������� �����: " << std::endl;
    std::cin >> new_station.totalShops;
    std::cout << "������� ���������� ������� �����: " << std::endl;
    std::cin >> new_station.activatedShops;
    std::cout << "������� ������������� ��(� ���������): " << std::endl;
    std::cin >> new_station.efficiency;
    return new_station;
}

void pipe_info(Pipe new_pipe) { //���������� � ������
    std::cout << "���������� � ����� �����:" << std::endl;
    if (new_pipe.kilometricMark == "Nothing") {
        std::cout << "�����������..." << std::endl;
    }
    else {
        std::cout << "���: " << new_pipe.kilometricMark << std::endl;
        std::cout << "�����: " << new_pipe.length << " ������." << std::endl;
        std::cout << "�������: " << new_pipe.diameter << " �����������." << std::endl;
        if (new_pipe.isUnderRepair == 0) {
            std::cout << "������: �����" << std::endl;
        }
        else {
            std::cout << "������: � �������" << std::endl;
        }
    }
}
void CS_info(CompressorStation newcs) { //���������� � ��
    std::cout << "���������� � ����� ������������� �������:" << std::endl;
    if (newcs.name == "Nothing") {
        std::cout << "�����������..." << std::endl;
    }
    else {
        std::cout << "��� ������������� �������: " << newcs.name << std::endl;
        std::cout << "���-�� �����: " << newcs.totalShops << std::endl;
        std::cout << "������� ����: " << newcs.activatedShops << " ��." << std::endl;
        std::cout << "�������������: " << newcs.efficiency << " %" << std::endl;
    }
}
void edit_pipe(Pipe new_pipe) { //4. ������������� ����� 
    int num_pipe = 0, new_lenght, new_diameter;
    std::string new_kilometricMark_pipe;
    if (new_pipe.kilometricMark == "Nothing") {
        std::cout << "����������� ����� ��� �������������� \n";
        
    }
    else {
        bool new_repair;
        std::cout << "��� ������ ��������?" << std::endl;
        std::cout << "1. ������������ �����;" << std::endl;
        std::cout << "2. �����" << std::endl;
        std::cout << "3. ������� " << std::endl;
        std::cout << "4. �����" << std::endl;
        std::cin >> num_pipe;
        switch (num_pipe)
        {
        case 1:
        {
            std::cout << "������� ����� ������������ �����: " << std::endl;
            std::cin >> new_kilometricMark_pipe;
            new_pipe.kilometricMark = new_kilometricMark_pipe;
            break;
        }
        case 2:
        {
            std::cout << "������� ����� �����: " << std::endl;
            std::cin >> new_lenght;
            new_pipe.length = new_lenght;
            break;
        }
        case 3:
        {
            std::cout << "������� ������� �����: " << std::endl;
            std::cin >> new_diameter;
            new_pipe.diameter = new_diameter;
            break;
        }
        case 4:
        {
            std::cout << "������� ����� �����:" << std::endl;
            std::cout << "0. �����;" << std::endl;
            std::cout << "1. � �������" << std::endl;
            std::cin >> new_repair;
            new_pipe.isUnderRepair = new_repair;
            break;
        }
        default:
        {
            std::cout << "��������� ������. ��������� �����..." << std::endl;
            edit_pipe(new_pipe);
        }
        }
        pipe_info(new_pipe);
    }
    
}
void edit_CS(CompressorStation newst) { //4. ������������� �� 
    int newTotal_shops, newActivated_shops, newEfficiency;
    std::string newName;
    if (newst.name == "Nothing") {
        std::cout << "����������� �� ��� �������������� \n";
    }
    else {
        int numCS = 0;
        std::cout << "��� ������ ��������?" << std::endl;
        std::cout << "1. ���:" << std::endl;
        std::cout << "2. ���������� �����: " << std::endl;
        std::cout << "3. ���-�� ����� � ������: " << std::endl;
        std::cout << "4. �������������" << std::endl;
        std::cin >> numCS;
        switch (numCS)
        {
        case 1:
        {
            std::cout << "������� �������� ��: " << std::endl;
            std::cin >> newName;
            newst.name = newName;
            break;
        }
        case 2:
        {
            std::cout << "������� ���������� ���� �����: " << std::endl;
            std::cin >> newTotal_shops;
            newst.totalShops = newTotal_shops;
            break;
        }
        case 3:
        {
            std::cout << "������� ���-�� ����� � ������: " << std::endl;
            std::cin >> newActivated_shops;
            newst.activatedShops = newActivated_shops;
            break;
        }
        case 4:
        {
            std::cout << "������� ������������� ��:" << std::endl;
            std::cin >> newEfficiency;
            newst.efficiency = newEfficiency;
            break;
        }
        default:
        {
            std::cout << "��������� ������. ��������� �����..." << std::endl;
            edit_CS(newst);
        }
        }
        CS_info(newst);
    }
    
}
void save__Pipe(const Pipe& p, std::ofstream& fout)
{
    fout << p.kilometricMark << std::endl
        << p.length << std::endl
        << p.diameter << std::endl
        << p.isUnderRepair << std::endl;
}

void save__CS(const CompressorStation& cs, std::ofstream& fout)
{
    fout << cs.name << std::endl
        << cs.totalShops << std::endl
        << cs.activatedShops << std::endl
        << cs.efficiency << std::endl;
}

void save__File(const Pipe& p, const CompressorStation& cs) 
{
    int npipe = 0;
    int nCS = 0;

    std::ofstream fout;
    fout.open("saved_Pipe_CS.txt", std::ios::out);
    if (fout)
    {
        if (p.kilometricMark == "Nothing") // for pipe
            fout << npipe << std::endl;
        else
        {
            npipe = 1;
            fout << npipe << std::endl;
            save__Pipe(p, fout);
        }
        if (cs.name == "Nothing") // for cs
            fout << nCS << std::endl;
        else
        {
            nCS = 1;
            fout << nCS << std::endl;
            save__CS(cs, fout);
        }
        std::cout << "����� ��������� = " << npipe << std::endl
            << "�� ��������� = " << nCS << std::endl;
    }
    else
        std::cout << "������ ������� � ����" << std::endl;
    fout.close(); 
}
/*void SAVE_pipe(Pipe pipes) {
    std::ofstream outp("saved_Pipe_CS.txt");
    if (outp.is_open()) {
        outp << pipes.kilometricMark << std::endl;
        outp  << pipes.length << std::endl;
        outp  << pipes.diameter << std::endl;
        outp  << pipes.isUnderRepair << std::endl;
        outp.close(); // �������� �����


        std::cout << "������ �������� � ���� saved_Pipe_CS.txt" << std::endl;
    }
    else {
        std::cout << "�� ���������� ������� ����." << std::endl;
    }
}
void SAVE_CS(CompressorStation station) {
    std::ofstream outp("saved_Pipe_CS.txt");
    if (outp.is_open()) {
        outp <<  station.name << std::endl;
        outp << station.totalShops << std::endl;
        outp << station.activatedShops << std::endl;
        outp << station.efficiency << std::endl;
        std::cout << "������ �������� � ���� saved_Pipe_CS.txt" << std::endl;
        outp.close(); // �������� �����
    }
    else {
        std::cout << "�� ���������� ������� ����." << std::endl;
    }
}*/
void load_Pipe(Pipe& p, std::ifstream& flin)
{
    flin >> p.kilometricMark;
    flin >> p.length;
    flin >> p.diameter;
    flin >> p.isUnderRepair;
}

void load_CS(CompressorStation& cs, std::ifstream& flin)
{
    flin >> cs.name;
    flin >> cs.totalShops;
    flin >> cs.activatedShops;
    flin >> cs.efficiency;
}
void loadFile(Pipe& p, CompressorStation& cs){
    int npipe;
    int nCS;
    std::ifstream flin;
    flin.open("saved_Pipe_CS.txt", std::ios::in);
    if (flin)
    {
        flin >> npipe;
        if (npipe > 0) // �������� ���-�� ����
            load_Pipe(p, flin);
        else
        {
            Pipe empty_p;
            p = empty_p;
        }


        flin >> nCS;
        if (nCS > 0)
            load_CS(cs, flin); //�������� ���-�� ��
        else
        {
            CompressorStation empty_cs;
            cs = empty_cs;
        }

        std::cout << "Pipe loaded = " << npipe << std::endl
            << "CS loaded = " << nCS << std::endl;
    }
    else
        std::cout << "������ ��������" << std::endl;
    flin.close(); 
}


int main() {
    CompressorStation station;
    Pipe pipes;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    while (1) {
        std::cout << "����:" << std::endl;
        std::cout << "1. �������� �����" << std::endl;
        std::cout << "2. ������������� �����" << std::endl;
        std::cout << "3. ����������� ���������� � ������ � ��" << std::endl;
        std::cout << "4. �������� ������������� �������" << std::endl;
        std::cout << "5. ������������� ������������� �������" << std::endl;
        std::cout << "6. ��������� ���������� � ������ � �� � ����" << std::endl;
        std::cout << "7. ��������� ���������� � ������ � �� �� �����" << std::endl;
        std::cout << "8. ����� �� ��������� \n" << std::endl;

        int choice;
        while (true) {
            std::cout << "������� ����� ������ ����: ";
            if (std::cin >> choice) {
                // ��������, ��� ������� ����� �����
                break;
            }
            else {
                // ������� ������ � ������ �����
                std::cin.clear();
                // �������� ���� �������� �� ������ ����� �� ����� ������
                std::cin.ignore(100, '\n');
                std::cout << "�������� ����. ������� ����� �����.\n";
            }
        }


        switch (choice) {
        case 1:
        {
            pipes = addPipe();
            break;
        }
        case 2:
        {
            edit_pipe(pipes);
            break;
        }
        case 3:
        {
            pipe_info(pipes);
            std::cout << "\n" << std::endl;
            CS_info(station);
            break;
        }
        case 4:
        {
            station = Add_station();
            break;
        }
        case 5:
        {
            edit_CS(station);
            break;
        }
        case 6:
        {
        save__File(pipes, station);
        break;
        }
        case 7:
        {
        loadFile(pipes, station);
        break;
        }
        case 8:
        {
            return 0;
            break;
        }
        default: {
            std::cout << "�������� �����. ���������� ��� ���. \n" << std::endl;
            break;
        }
        }

    }
    return 0;
}