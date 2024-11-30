#include "CStations.h"
#include "Utilities.h"
int CStations::maxId = 0;

int CStations::GetId()
{
    return Id;
}
string CStations::Getname() const
{
    return Name;
}

int CStations::GetWorkshops() const
{
    return totalWorkshops;
}

int CStations::GetActWorkshops() const
{
    return ActWorkshops;
}

int CStations::GetPercentOfNonActiveWorkshops() const
{
    return (totalWorkshops - ActWorkshops) * 100 / totalWorkshops;
}
void CStations::SetActWorkshops(int cnt)
{
    ActWorkshops = cnt;
}

void CStations::PrintWorkshops() const
{
    cout << "� ������ ������ " << ActWorkshops <<
        " �� " << totalWorkshops << " ����� ��������� � ������" << endl;
}
void CStations::EditCStation()
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
        int active = GetCorrectData(1, totalWorkshops);
        SetActWorkshops(active);
        PrintWorkshops();
        
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
istream& operator >> (istream& in, CStations& newCStations)
{
    newCStations.Id = ++newCStations.maxId;
    cout << "ID: " << newCStations.Id << endl;
    cout << "����� ��� ��: ";
    in.ignore();
    getline(in, newCStations.Name);
    INPUT_LINE(in, newCStations.Name);
    cout << "����� ����� ���� �����: ";
    newCStations.totalWorkshops = GetCorrectData(1, 10000);
    cout << "����� ����� �������� �����: ";
    newCStations.ActWorkshops = GetCorrectData(1, newCStations.totalWorkshops);
    cout << "����� ������������ ����� (�� 0 �� 1 �������� �������) ";
    newCStations.Efficiency = GetCorrectData(0.0, 1.0);
    return in;
}

ostream& operator << (ostream& out, const CStations& newCStations)
{
    if (newCStations.Name == "Nothing")
    {
        out << "��� ��������� ��!\n";
    }
    else
    {
        out << "ID: " << newCStations.Id << ";" << "\t���: " << newCStations.Name << ";" << "\t����: " << newCStations.totalWorkshops
            << ";" << "\t���� � ������: " << newCStations.ActWorkshops << ";" << "\t�������������: " << newCStations.Efficiency << ";" << endl;
        PRINT_PARAM(cout, newCStations.Id);
        PRINT_PARAM(cout, newCStations.Name);
        PRINT_PARAM(cout, newCStations.totalWorkshops);
        PRINT_PARAM(cout, newCStations.ActWorkshops);
        PRINT_PARAM(cout, newCStations.Efficiency);
    }
    return out;
}

ifstream& operator >> (ifstream& flin, CStations& newCStations)
{
    flin >> newCStations.Id;
    newCStations.maxId = newCStations.Id;
    flin.ignore();
    getline(flin, newCStations.Name);
    flin >> newCStations.totalWorkshops;
    flin >> newCStations.ActWorkshops;
    flin >> newCStations.Efficiency;
    return flin;
}

ofstream& operator << (ofstream& fout, const CStations& newCStations)
{
    fout << newCStations.Id << endl;
    fout << newCStations.Name << endl;
    fout << newCStations.totalWorkshops << endl;
    fout << newCStations.ActWorkshops << endl;
    fout << newCStations.Efficiency << endl;
    return fout;
}

/*
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
namespace CCStations {
    class CompressorCStations {
    private:
        string name = "Nothing"; //�������� ������������� �������
        int totalShops = 0; // ����� ���������� �����
        int activatedShops = 0; // ���������� ����� � ������
        double efficiency = 0.0; // ������������� (���������� ����������)
    public:
        static CompressorCStations Add_CStations() { //2. �������� �� 
            CompressorCStations new_CStations;
            cout << "�������� ���� ��: " << endl;
            getline(cin >> ws, new_CStations.name);
            cout << "������� ���������� �����: " << endl;
            new_CStations.totalShops = check_int(0, 1);
            cout << "������� ���������� ������� �����: " << endl;
            new_CStations.activatedShops = check_int(0, -1);
            cout << "������� ������������� ��(� ���������): " << endl;
            new_CStations.efficiency = floatcheck(0, 0.0);
            return new_CStations;
        }
        void CS_info() const { //���������� � �� //!!!!
            cout << "���������� � ����� ������������� �������:" << endl;
            if (name == "Nothing") {
                cout << "�����������..." << endl;
            }
            else {
                cout << "��� ������������� �������: " << name << endl;
                cout << "���-�� �����: " << totalShops << endl;
                cout << "������� ����: " << activatedShops << " ��." << endl;
                cout << "�������������: " << efficiency << " %" << endl;
            }
        }
        void editCS() {
            int m = 0;
            if (totalShops > 0) {
                cout << "�������� �������� ��� ��������������: " << endl
                    << "1) ���������� ������� �����" << endl
                    << "0) ����� � ����" << endl
                    << "����� �������: ";
                m = check_int(1, 0);
                if (m == 0) return;

                cout << "����� �����: " << totalShops << "; ������ ���������� ������� �����: " << activatedShops << endl;
                cout << "������� ����� ���������� ������� �����: ";
                activatedShops = check_int(totalShops, 0);
            }
            else {
                cout << "�� ��� �� �������� ������������� �������." << endl;
            }
        }
        void save(ofstream& fout) const {
            fout << name << endl
                << totalShops << endl
                << activatedShops << endl
                << efficiency << endl;
        }

        void load(ifstream& fin) {
            getline(fin >> ws, name);
            fin >> totalShops >> activatedShops >> efficiency;
        }
        string getName() const {
            return name;
        }
    private:
        static int check_int(int max, int low) {
            int z;
            cin >> z;
            cin.ignore();
            while (true) {
                if (cin.fail()) {
                    cout << "Error. Not an integer or a character is entered! Try again: ";
                    cin.clear();
                    while (cin.get() != '\n');
                }
                else if (z < low) {
                    cout << "Error. A negative number or zero is entered! Try again: ";
                }
                else if (max != 0 && z > max) {
                    cout << "Error. A number greater than the maximum has been entered! Try again: ";
                }
                else {
                    break;
                }
                cin >> z;
                cin.ignore();
            }
            return z;
        }

        static float floatcheck(float max, float low) {
            float z;
            cin >> z;
            cin.ignore();
            while (true) {
                if (cin.fail()) {
                    cout << "Error. Not a float or a character is entered! Try again: ";
                    cin.clear();
                    while (cin.get() != '\n');
                }
                else if (z < low) {
                    cout << "Error. A negative number or zero is entered! Try again: ";
                }
                else if (max != 0 && z > max) {
                    cout << "Error. A number greater than the maximum has been entered! Try again: ";
                }
                else {
                    break;
                }
                cin >> z;
                cin.ignore();
            }
            return z;
        }

        static bool boolCheck() {
            int inp;
            while (true) {
                cin >> inp;

                if (cin.fail()) {
                    cout << "Error. Not an integer entered! Try again." << endl;
                    cin.clear();
                    cin.ignore();
                }
                else if (inp != 0 && inp != 1) {
                    cout << "Error. Please enter either 0 or 1! Try again." << endl;
                }
                else {
                    break;
                }
            }

            return static_cast<bool>(inp);
        }
    };
    int check_int(int max, int low) {
        int z;
        cin >> z;
        cin.ignore();
        while (true) {
            if (cin.fail()) {
                cout << "Error. Not an integer or a character is entered! Try again: ";
                cin.clear();
                while (cin.get() != '\n');
            }
            else if (z < low) {
                cout << "Error. A negative number or zero is entered! Try again: ";
            }
            else if (max != 0 && z > max) {
                cout << "Error. A number greater than the maximum has been entered! Try again: ";
            }
            else {
                break;
            }
            cin >> z;
            cin.ignore();
        }
        return z;
    }
}*/