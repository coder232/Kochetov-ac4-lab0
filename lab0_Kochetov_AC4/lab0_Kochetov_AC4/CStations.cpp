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

