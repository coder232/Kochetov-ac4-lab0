#include "Pipe.h"
#include "Utilities.h"

int Pipe::maxId = 0;

int Pipe::GetId() 
{
    return Id;
}
int Pipe::GetDiameter() const
{
    return Diameter;
}

string Pipe::Getname() const
{
    return kilometricMark;
}

bool Pipe::GetRepairStatus()
{
    return isUnderRepair;
}
void Pipe::SetRepairStatus(bool status)
{
    isUnderRepair = status;
}

void Pipe::PrintRepairStatus()
{
    if (GetRepairStatus() == true)
    {
        cout << "Труба в ремонте [=1]\n";
    }
    else
        cout << "Труба в исправном состоянии [=0]\n";
}
void Pipe::EditPipe() {
    cout << "Статус \"В ремонте\" будет изменен, вы уверены?" << endl;
    cout << "1. Да" << endl;
    cout << "2. Нет" << endl;
    cout << "Введите ваш выбор: ";
    switch (GetCorrectData(1, 2))
    {
    case 1:
    {
        cout << "Введите статус \"в ремонте\": ";
        bool pipeRepair = GetCorrectData(false, true);
        SetRepairStatus(pipeRepair);
        PrintRepairStatus();
        break;
    }
    case 2:
        return;
    default:
        cout << "Пожалуйста, введите корректную команду!\n" << endl;
        break;
    }
}



istream& operator >> (istream& in, Pipe& newPipe)
{
    newPipe.Id = ++newPipe.maxId;
    cout << "ID: " << newPipe.Id << endl;
    cout << "Введите километровую марку(имя): ";
    in.ignore();
    getline(in, newPipe.kilometricMark);
    INPUT_LINE(in, newPipe.kilometricMark);
    cout << "Введите длину трубы(в метрах): ";
    newPipe.Length = GetCorrectData(0.0, 10000.0);
    cout << "Введите диаметр трубы (в миллиметрах): ";
    newPipe.Diameter = GetCorrectData(0.0, 1000.0);
    cout << "Введите статус \"в ремонте\": ";
    newPipe.isUnderRepair = GetCorrectData(0, 1);
    return in;
}

ostream& operator << (ostream& out, const Pipe& newPipe)
{
    if (newPipe.kilometricMark == "Nothing")
    {
        out << "Нет доступных труб!\n";
    }
    else
    {
        out << "ID: " << newPipe.Id << ";" << "\tКилометровая марка: " << newPipe.kilometricMark << ";" << "\tДлина: " << newPipe.Length
            << ";" << "\tДиаметр: " << newPipe.Diameter << ";" << "\tСтатус \"в ремонте\": " << newPipe.isUnderRepair << ";" << endl;
        PRINT_PARAM(cout, newPipe.Id);
        PRINT_PARAM(cout, newPipe.kilometricMark);
        PRINT_PARAM(cout, newPipe.Diameter);
        PRINT_PARAM(cout, newPipe.isUnderRepair);
    }
    return out;
}

ifstream& operator >> (ifstream& flin, Pipe& newPipe)
{
    flin >> newPipe.Id;
    newPipe.maxId = newPipe.Id;
    flin.ignore();
    getline(flin, newPipe.kilometricMark);
    flin >> newPipe.Length;
    flin >> newPipe.Diameter;
    flin >> newPipe.isUnderRepair;
    return flin;
}

ofstream& operator << (ofstream& fout, const Pipe& newPipe)
{
    fout << newPipe.Id << endl;
    fout << newPipe.kilometricMark << endl;
    fout << newPipe.Length << endl;
    fout << newPipe.Diameter << endl;
    fout << newPipe.isUnderRepair << endl;
    return fout;
}
/*class Pipe
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
};*/
