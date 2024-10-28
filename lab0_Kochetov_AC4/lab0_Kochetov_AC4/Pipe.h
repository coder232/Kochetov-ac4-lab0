#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
namespace pipe {
    class Pipe
    {
    private:
        string kilometricMark = "Nothing";
        double length = 0.0;
        int diameter = 0;
        bool isUnderRepair = false;
    public:
        static Pipe addPipe() {
            Pipe newPipe;
            cout << "������� ������������ �������: ";
            getline(cin >> ws, newPipe.kilometricMark);

            cout << "������� ����� ����� (��): ";
            newPipe.length = floatcheck(0, 0.1);

            cout << "������� ������� ����� (��): ";
            newPipe.diameter = check_int(0, 1);

            cout << "������� �� ������� (0 - ���, 1 - ��): ";
            int repairStatus;
            newPipe.isUnderRepair = boolCheck();
            cout << "����� ������� ���������." << endl;
            return newPipe;
        }
        void pipe_info() const { //���������� � ������//!!!!
            cout << "���������� � ����� �����:" << endl;
            if (kilometricMark == "Nothing") {
                cout << "�����������..." << endl;
            }
            else {
                cout << "������������ �����: " << kilometricMark << endl;
                cout << "�����: " << length << " ������." << endl;
                cout << "�������: " << diameter << " �����������." << endl;
                if (isUnderRepair == 0) {//!!
                    cout << "������: �����" << endl;
                }
                else {
                    cout << "������: � �������" << endl;
                }
            }
        }
        void editPipe() {
            int m = 0;
            if (diameter > 0) {
                cout << "�������� �������� ��� ��������������: " << endl
                    << "1) ������ '� �������'" << endl
                    << "0) ����� � ����" << endl
                    << "����� �������: ";
                m = check_int(1, 0);
                if (m == 0) return;

                cout << "������ ������ �����: � ������� " << std::boolalpha << isUnderRepair << endl;
                cout << "�������� ����� ������ �����: " << endl
                    << "0) �� � �������" << endl
                    << "1) � �������" << endl
                    << "������� ����� �������: ";
                isUnderRepair = boolCheck();
            }
            else {
                cout << "�� ��� �� �������� ����� � �� ������ ����������� � ���������." << endl;
            }
        }
        void save(std::ofstream& fout) const {
            fout << kilometricMark << endl
                << length << endl
                << diameter << endl
                << isUnderRepair << endl;
        }

        void load(std::ifstream& fin) {
            getline(fin >> ws, kilometricMark);
            fin >> length >> diameter >> isUnderRepair;
        }
        std::string getMark() const {
            return kilometricMark;
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
}