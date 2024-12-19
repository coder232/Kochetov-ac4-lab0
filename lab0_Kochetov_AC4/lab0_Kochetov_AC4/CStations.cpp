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

int CStations::Get_Id_in() const {
    return id_in;
}

int CStations::Get_Id_out() const {
    return id_out;

}
int CStations::GetShortestPath() const {
    return shortest_path;
}

void CStations::Set_Id_in(int in) {
    id_in = in;
}

void CStations::Set_Id_out(int out) {
    id_out = out;
}

void CStations::SetActWorkshops(int cnt)
{
    ActWorkshops = cnt;
}
void CStations::SetShortestPath(int sh) {
    shortest_path = sh;
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
        /*PRINT_PARAM(cout, newCStations.Id);
        PRINT_PARAM(cout, newCStations.Name);
        PRINT_PARAM(cout, newCStations.totalWorkshops);
        PRINT_PARAM(cout, newCStations.ActWorkshops);
        PRINT_PARAM(cout, newCStations.Efficiency);*/
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

