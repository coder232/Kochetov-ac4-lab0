#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
namespace CStation {
    class CompressorStation {
    private:
        string name = "Nothing"; //�������� ������������� �������
        int totalShops = 0; // ����� ���������� �����
        int activatedShops = 0; // ���������� ����� � ������
        double efficiency = 0.0; // ������������� (���������� ����������)
    public:
        static CompressorStation Add_station() { //2. �������� �� 
            CompressorStation new_station;
            cout << "�������� ���� ��: " << endl;
            getline(cin >> ws, new_station.name);
            cout << "������� ���������� �����: " << endl;
            new_station.totalShops = check_int(0, 1);
            cout << "������� ���������� ������� �����: " << endl;
            new_station.activatedShops = check_int(0, -1);
            cout << "������� ������������� ��(� ���������): " << endl;
            new_station.efficiency = floatcheck(0, 0.0);
            return new_station;
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
}