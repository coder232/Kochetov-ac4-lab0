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
    cout << "в данный момент " << ActWorkshops <<
        " из " << totalWorkshops << " цехов находятся в работе" << endl;
}
void CStations::EditCStation()
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
        int active = GetCorrectData(1, totalWorkshops);
        SetActWorkshops(active);
        PrintWorkshops();
        
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
istream& operator >> (istream& in, CStations& newCStations)
{
    newCStations.Id = ++newCStations.maxId;
    cout << "ID: " << newCStations.Id << endl;
    cout << "Введи имя КС: ";
    in.ignore();
    getline(in, newCStations.Name);
    INPUT_LINE(in, newCStations.Name);
    cout << "Введи номер всех цехов: ";
    newCStations.totalWorkshops = GetCorrectData(1, 10000);
    cout << "Введи номер активных цехов: ";
    newCStations.ActWorkshops = GetCorrectData(1, newCStations.totalWorkshops);
    cout << "Введи эффекивность цехов (от 0 до 1 дробными числами) ";
    newCStations.Efficiency = GetCorrectData(0.0, 1.0);
    return in;
}

ostream& operator << (ostream& out, const CStations& newCStations)
{
    if (newCStations.Name == "Nothing")
    {
        out << "Нет доступных КС!\n";
    }
    else
    {
        out << "ID: " << newCStations.Id << ";" << "\tИмя: " << newCStations.Name << ";" << "\tЦеха: " << newCStations.totalWorkshops
            << ";" << "\tЦеха в работе: " << newCStations.ActWorkshops << ";" << "\tЭффективность: " << newCStations.Efficiency << ";" << endl;
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
        string name = "Nothing"; //Название компрессорной станции
        int totalShops = 0; // Общее количество цехов
        int activatedShops = 0; // Количество цехов в работе
        double efficiency = 0.0; // Эффективность (обобщающий показатель)
    public:
        static CompressorCStations Add_CStations() { //2. Добавить КС 
            CompressorCStations new_CStations;
            cout << "Назовите свою КС: " << endl;
            getline(cin >> ws, new_CStations.name);
            cout << "Укажите количество цехов: " << endl;
            new_CStations.totalShops = check_int(0, 1);
            cout << "Укажите количество РАБОЧИХ цехов: " << endl;
            new_CStations.activatedShops = check_int(0, -1);
            cout << "Укажите эффективность КС(В процентах): " << endl;
            new_CStations.efficiency = floatcheck(0, 0.0);
            return new_CStations;
        }
        void CS_info() const { //информация о КС //!!!!
            cout << "Информация о вашей компрессорной станции:" << endl;
            if (name == "Nothing") {
                cout << "Отсутствуют..." << endl;
            }
            else {
                cout << "Имя Компрессорной станции: " << name << endl;
                cout << "Кол-во цехов: " << totalShops << endl;
                cout << "Рабочие цеха: " << activatedShops << " шт." << endl;
                cout << "Эффективность: " << efficiency << " %" << endl;
            }
        }
        void editCS() {
            int m = 0;
            if (totalShops > 0) {
                cout << "Выберите параметр для редактирования: " << endl
                    << "1) Количество рабочих цехов" << endl
                    << "0) Выйти в меню" << endl
                    << "Номер команды: ";
                m = check_int(1, 0);
                if (m == 0) return;

                cout << "Всего цехов: " << totalShops << "; Старое количество рабочих цехов: " << activatedShops << endl;
                cout << "Введите новое количество рабочих цехов: ";
                activatedShops = check_int(totalShops, 0);
            }
            else {
                cout << "Вы еще не добавили компрессорную станцию." << endl;
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