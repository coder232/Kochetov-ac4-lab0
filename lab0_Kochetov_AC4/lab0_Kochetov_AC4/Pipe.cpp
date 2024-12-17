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

int Pipe::GetCSid1() const{
    return CSid1;
}

int Pipe::GetCSid2() const{
    return CSid2;
}

bool Pipe::Get_free() {
    return free;
}

void Pipe::Set_free(bool status) {
    free = status;
}

void Pipe::SetRepairStatus(bool status)
{
    isUnderRepair = status;
}

void Pipe::SetDiameter(int diam) {
    Diameter = diam;
}

void Pipe::DeleteConnection()
{
    CSid1 = 0;
    CSid2 = 0;
}

bool Pipe::ConnectionNotBusy() const
{
    return CSid1 < 1 || CSid2 < 1;
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
        /*PRINT_PARAM(cout, newPipe.Id);
        PRINT_PARAM(cout, newPipe.kilometricMark);
        PRINT_PARAM(cout, newPipe.Diameter);
        PRINT_PARAM(cout, newPipe.isUnderRepair);*/
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
