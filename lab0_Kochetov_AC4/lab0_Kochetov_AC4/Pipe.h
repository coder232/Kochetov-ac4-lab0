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
            cout << "Введите километровую отметку: ";
            getline(cin >> ws, newPipe.kilometricMark);

            cout << "Введите длину трубы (км): ";
            newPipe.length = floatcheck(0, 0.1);

            cout << "Введите диаметр трубы (мм): ";
            newPipe.diameter = check_int(0, 1);

            cout << "Признак «в ремонте» (0 - нет, 1 - да): ";
            int repairStatus;
            newPipe.isUnderRepair = boolCheck();
            cout << "Труба успешно добавлена." << endl;
            return newPipe;
        }
        void pipe_info() const { //информация о трубах//!!!!
            cout << "Информация о вашей трубе:" << endl;
            if (kilometricMark == "Nothing") {
                cout << "Отсутствуют..." << endl;
            }
            else {
                cout << "Километровая марка: " << kilometricMark << endl;
                cout << "Длина: " << length << " метров." << endl;
                cout << "Диаметр: " << diameter << " миллиметров." << endl;
                if (isUnderRepair == 0) {//!!
                    cout << "Статус: Готов" << endl;
                }
                else {
                    cout << "Статус: В ремонте" << endl;
                }
            }
        }
        void editPipe() {
            int m = 0;
            if (diameter > 0) {
                cout << "Выберите параметр для редактирования: " << endl
                    << "1) Статус 'в ремонте'" << endl
                    << "0) Выйти в меню" << endl
                    << "Номер команды: ";
                m = check_int(1, 0);
                if (m == 0) return;

                cout << "Старый статус трубы: в ремонте " << std::boolalpha << isUnderRepair << endl;
                cout << "Выберите новый статус трубы: " << endl
                    << "0) Не в ремонте" << endl
                    << "1) В ремонте" << endl
                    << "Введите номер команды: ";
                isUnderRepair = boolCheck();
            }
            else {
                cout << "Вы еще не добавили трубу и не можете просмотреть её параметры." << endl;
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