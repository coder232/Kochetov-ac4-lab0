#include <iostream>
#include <string>
#include "windows.h"
#include <vector>
#include <fstream> 

struct Pipe {
    std::string kilometricMark = "Nothing"; // Километровая отметка 
    double length = 0.0; // Длина, км
    int diameter = 0; // Диаметр, мм
    bool isUnderRepair = false; // Признак "в ремонте"
};
struct CompressorStation {
    std::string name = "Nothing"; //Название компрессорной станции
    int totalShops = 0; // Общее количество цехов
    int activatedShops = 0; // Количество цехов в работе
    double efficiency = 0.0; // Эффективность (обобщающий показатель)
};
int check_int(int max, int low) {
    int z;
    std::cin >> z;
    std::cin.ignore();
    while (true) {
        if (std::cin.fail()) {
            std::cout << "Error. Not an integer or a character is entered! Try again: ";
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
        else if (z < low) {
            std::cout << "Error. A negative number or zero is entered! Try again: ";
        }
        else if (max != 0 && z > max) {
            std::cout << "Error. A number greater than the maximum has been entered! Try again: ";
        }
        else {
            break;
        }
        std::cin >> z;
        std::cin.ignore();
    }
    return z;
}

float floatcheck(float max, float low) {
    float z;
    std::cin >> z;
    std::cin.ignore();
    while (true) {
        if (std::cin.fail()) {
            std::cout << "Error. Not an integer or a character is entered! Try again: ";
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
        else if (z < low) {
            std::cout << "Error. A negative number or zero is entered! Try again: ";
        }
        else if (max != 0 && z > max) {
            std::cout << "Error. A number greater than the maximum has been entered! Try again: ";
        }
        else {
            break;
        }
        std::cin >> z;
        std::cin.ignore();
    }
    return z;
}
bool boolCheck() {
    int inp; 
    while (true) {
        std::cin >> inp;

        if (std::cin.fail()) {
            std::cout << "Error. Not an integer entered! Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(); 
        }
        else if (inp != 0 && inp != 1) {
            std::cout << "Error. Please enter either 0 or 1! Try again." << std::endl;
        }
        else {
            break; 
        }
    }

    return static_cast<bool>(inp);
}
Pipe addPipe() {
    Pipe newPipe;
    std::cout << "Введите километровую отметку: ";
    std::getline(std::cin >>std::ws, newPipe.kilometricMark);

    std::cout << "Введите длину трубы (км): ";
    newPipe.length = floatcheck(0, 0.1);

    std::cout << "Введите диаметр трубы (мм): ";
    newPipe.diameter = check_int(0, 1);

    std::cout << "Признак «в ремонте» (0 - нет, 1 - да): ";
    int repairStatus;
    newPipe.isUnderRepair = boolCheck();
    std::cout << "Труба успешно добавлена." << std::endl;
    return newPipe;
}
CompressorStation Add_station() { //2. Добавить КС 
    CompressorStation new_station;
    std::cout << "Назовите свою КС: " << std::endl;
    std::getline(std::cin >> std::ws, new_station.name);
    std::cout << "Укажите количество цехов: " << std::endl;
    new_station.totalShops = check_int(0, 1);
    std::cout << "Укажите количество РАБОЧИХ цехов: " << std::endl;
    new_station.activatedShops = check_int(0, -1);
    std::cout << "Укажите эффективность КС(В процентах): " << std::endl;
    new_station.efficiency = floatcheck(0,0.0);
    return new_station;
}

void pipe_info(Pipe new_pipe) { //информация о трубах//!!!!
    std::cout << "Информация о вашей трубе:" << std::endl;
    if (new_pipe.kilometricMark == "Nothing") {
        std::cout << "Отсутствуют..." << std::endl;
    }
    else {
        std::cout << "Километровая марка: " << new_pipe.kilometricMark << std::endl;
        std::cout << "Длина: " << new_pipe.length << " метров." << std::endl;
        std::cout << "Диаметр: " << new_pipe.diameter << " миллиметров." << std::endl;
        if (new_pipe.isUnderRepair == 0) {//!!
            std::cout << "Статус: Готов" << std::endl;
        }
        else {
            std::cout << "Статус: В ремонте" << std::endl;
        }
    }
}
void CS_info(CompressorStation newcs) { //информация о КС //!!!!
    std::cout << "Информация о вашей компрессорной станции:" << std::endl;
    if (newcs.name == "Nothing") {
        std::cout << "Отсутствуют..." << std::endl;
    }
    else {
        std::cout << "Имя Компрессорной станции: " << newcs.name << std::endl;
        std::cout << "Кол-во цехов: " << newcs.totalShops << std::endl;
        std::cout << "Рабочие цеха: " << newcs.activatedShops << " шт." << std::endl;
        std::cout << "Эффективность: " << newcs.efficiency << " %" << std::endl;
    }
}
void edit_Pipe(Pipe& P) {
    int m = 0;
    if (P.diameter > 0)
    {
        std::cout << "Select the parameter you want to edit: " << std::endl << "1) 'Under repair' status" << std::endl << "0) Exit to menu" << std::endl << "Command number: ";
        m = check_int(1, 0);
        if (m == 0)
            return;
        std::cout << "Old pipe status: under repair " << std::boolalpha << P.isUnderRepair << std::endl;
        std::cout << "Select the new pipe status: " << std::endl << "0) Not under repair" << std::endl << "1) Under repair" << std::endl << "Enter the command number: ";
        P.isUnderRepair = check_int(1, 0);
    }
    else {
        std::cout << "You haven't added a pipe yet and cannot view its parameters. Please configure the pipe in the menu (option 1)" << std::endl;
    }
}
void edit_CS(CompressorStation& CS) {
    int m = 0;
    if (CS.totalShops > 0)
    {
        std::cout << "Select the parameter you want to edit: " << std::endl << "1) Number of workshops in operation" << std::endl << "0) Exit to menu" << std::endl << "Command number: ";
        m = check_int(1, 0);
        if (m == 0)
            return;
        std::cout << "Total number of workshops: " << CS.totalShops << "; Old number of workshops in operation: " << CS.totalShops << std::endl;
        std::cout << "Enter the new number of workshops in operation: ";
        CS.totalShops = check_int(CS.totalShops, 0);
    }
    else {
        std::cout << "" << std::endl;
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
        std::cout << "Труба сохранена = " << npipe << std::endl
            << "КС сохранена = " << nCS << std::endl;
    }
    else
        std::cout << "Ошибка зарузки в файл" << std::endl;
    fout.close(); 
}
/*void SAVE_pipe(Pipe pipes) {
    std::ofstream outp("saved_Pipe_CS.txt");
    if (outp.is_open()) {
        outp << pipes.kilometricMark << std::endl;
        outp  << pipes.length << std::endl;
        outp  << pipes.diameter << std::endl;
        outp  << pipes.isUnderRepair << std::endl;
        outp.close(); // Закрытие файла


        std::cout << "данные записаны в файл saved_Pipe_CS.txt" << std::endl;
    }
    else {
        std::cout << "Не получается открыть файл." << std::endl;
    }
}
void SAVE_CS(CompressorStation station) {
    std::ofstream outp("saved_Pipe_CS.txt");
    if (outp.is_open()) {
        outp <<  station.name << std::endl;
        outp << station.totalShops << std::endl;
        outp << station.activatedShops << std::endl;
        outp << station.efficiency << std::endl;
        std::cout << "данные записаны в файл saved_Pipe_CS.txt" << std::endl;
        outp.close(); // Закрытие файла
    }
    else {
        std::cout << "Не получается открыть файл." << std::endl;
    }
}*/
void load_Pipe(Pipe& p, std::ifstream& flin)
{;
    std::getline(flin>>std::ws, p.kilometricMark);
    flin >> p.length;
    flin >> p.diameter;
    flin >> p.isUnderRepair;
}

void load_CS(CompressorStation& cs, std::ifstream& flin)
{
    std::getline(flin >> std::ws, cs.name);
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
        if (npipe > 0) // проверка кол-ва труб
            load_Pipe(p, flin);
        else
        {
            Pipe empty_p;
            p = empty_p;
        }


        flin >> nCS;
        if (nCS > 0)
            load_CS(cs, flin); //проверка кол-ва кс
        else
        {
            CompressorStation empty_cs;
            cs = empty_cs;
        }

        std::cout << "Pipe loaded = " << npipe << std::endl
            << "CS loaded = " << nCS << std::endl;
    }
    else
        std::cout << "Ошибка загрузки" << std::endl;
    flin.close(); 
}
/*void loadPipe(Pipe& P, std::ifstream& in)
{
    if (in.is_open()) {
        std::getline(,in >> P.kilometricMark);
        in >> P.length >> P.diameter >> P.isUnderRepair;
    }
}
void loadCS(CompressorStation& CS, std::ifstream& in) {
    if (in.is_open()) {
        std::getline(in >> ws, CS.name);
        in >> CS.totalShops >> CS.activatedShops >> CS.efficiency;
    }
}
void load(Pipe& P, CompressorStation& CS) {
    std::ifstream in("saved_Pipe_CS.txt");
    if (!in.is_open())
    {
        std::cout << "not found" << std::endl;
        return;
    }
    P = {};
    CS = {};
    std::string finde;
    while (std::getline(in >> ws, finde)) {
        if (finde == "data Pipe:") {
            loadPipe(P, in);
            std::cout << "The data from the pipe file is recorded" << std::endl;
        }
        if (finde == "data CS:") {
            loadCS(CS, in);
            std::cout << "The data from the CS file is recorded" << std::endl;
        }
    }
}*/


int main() {
    CompressorStation station;
    Pipe pipes;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    while (1) {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Добавить трубу" << std::endl;
        std::cout << "2. Редактировать трубу" << std::endl;
        std::cout << "3. Просмотреть информацию о трубах и КС" << std::endl;
        std::cout << "4. Добавить компрессорную станцию" << std::endl;
        std::cout << "5. Редактировать компрессорную станцию" << std::endl;
        std::cout << "6. Сохранить информацию о трубах и КС в файл" << std::endl;
        std::cout << "7. Загрузить информацию о трубах и КС из файла" << std::endl;
        std::cout << "8. Выйти из программы \n" << std::endl;

        int choice;//!!!
        while (true) {
            std::cout << "Введите номер пункта меню: ";
            choice = check_int(0, 0);
            break;
        }


        switch (choice) {
        case 1:
        {
            pipes = addPipe();
            break;
        }
        case 2:
        {
            edit_Pipe(pipes);
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
            std::cout << "Неверный выбор. Попробуйте еще раз. \n" << std::endl;
            break;
        }
        }

    }
    return 0;
}