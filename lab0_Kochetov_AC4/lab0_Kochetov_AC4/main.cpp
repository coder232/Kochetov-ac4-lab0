#include <iostream>
#include <string>
#include "windows.h"
#include <vector>
#include <fstream> 
#include <csignal>

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
Pipe addPipe() {
    Pipe newPipe;
    std::cout << "Введите километровую отметку: ";
    std::cin.ignore(); // Очистка буфера ввода
    std::getline(std::cin, newPipe.kilometricMark);

    std::cout << "Введите длину трубы (км): ";
    std::cin >> newPipe.length;

    std::cout << "Введите диаметр трубы (мм): ";
    std::cin >> newPipe.diameter;

    std::cout << "Признак «в ремонте» (0 - нет, 1 - да): ";
    int repairStatus;
    std::cin >> repairStatus;
    newPipe.isUnderRepair = (repairStatus == 1);

    
    std::cout << "Труба успешно добавлена." << std::endl;
    return newPipe;
}
CompressorStation Add_station() { //2. Добавить КС 
    CompressorStation new_station;
    std::cout << "Назовите свою КС: " << std::endl;
    std::cin >> new_station.name;
    std::cout << "Укажите количество цехов: " << std::endl;
    std::cin >> new_station.totalShops;
    std::cout << "Укажите количество РАБОЧИХ цехов: " << std::endl;
    std::cin >> new_station.activatedShops;
    std::cout << "Укажите эффективность КС(В процентах): " << std::endl;
    std::cin >> new_station.efficiency;
    return new_station;
}

void pipe_info(Pipe new_pipe) { //информация о трубах
    std::cout << "Информация о вашей трубе:" << std::endl;
    if (new_pipe.kilometricMark == "Nothing") {
        std::cout << "Отсутствуют..." << std::endl;
    }
    else {
        std::cout << "Имя: " << new_pipe.kilometricMark << std::endl;
        std::cout << "Длина: " << new_pipe.length << " метров." << std::endl;
        std::cout << "Диаметр: " << new_pipe.diameter << " миллиметров." << std::endl;
        if (new_pipe.isUnderRepair == 0) {
            std::cout << "Статус: Готов" << std::endl;
        }
        else {
            std::cout << "Статус: В ремонте" << std::endl;
        }
    }
}
void CS_info(CompressorStation newcs) { //информация о КС
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
void edit_pipe(Pipe new_pipe) { //4. Редактировать трубу 
    int num_pipe = 0, new_lenght, new_diameter;
    std::string new_kilometricMark_pipe;
    if (new_pipe.kilometricMark == "Nothing") {
        std::cout << "Отсутствует труба для редактирования \n";
        
    }
    else {
        bool new_repair;
        std::cout << "Что хотите поменять?" << std::endl;
        std::cout << "1. Километровая марка;" << std::endl;
        std::cout << "2. Длина" << std::endl;
        std::cout << "3. Диаметр " << std::endl;
        std::cout << "4. Режим" << std::endl;
        std::cin >> num_pipe;
        switch (num_pipe)
        {
        case 1:
        {
            std::cout << "Введите новую километровую марку: " << std::endl;
            std::cin >> new_kilometricMark_pipe;
            new_pipe.kilometricMark = new_kilometricMark_pipe;
            break;
        }
        case 2:
        {
            std::cout << "Укажите длину трубы: " << std::endl;
            std::cin >> new_lenght;
            new_pipe.length = new_lenght;
            break;
        }
        case 3:
        {
            std::cout << "Укажите диаметр трубы: " << std::endl;
            std::cin >> new_diameter;
            new_pipe.diameter = new_diameter;
            break;
        }
        case 4:
        {
            std::cout << "Укажите режим трубы:" << std::endl;
            std::cout << "0. Готов;" << std::endl;
            std::cout << "1. В ремонте" << std::endl;
            std::cin >> new_repair;
            new_pipe.isUnderRepair = new_repair;
            break;
        }
        default:
        {
            std::cout << "Произошла ошибка. Попробуем снова..." << std::endl;
            edit_pipe(new_pipe);
        }
        }
        pipe_info(new_pipe);
    }
    
}
void edit_CS(CompressorStation newst) { //4. Редактировать КС 
    int newTotal_shops, newActivated_shops, newEfficiency;
    std::string newName;
    if (newst.name == "Nothing") {
        std::cout << "Отсутствует КС для редактирования \n";
    }
    else {
        int numCS = 0;
        std::cout << "Что хотите поменять?" << std::endl;
        std::cout << "1. Имя:" << std::endl;
        std::cout << "2. Количество цехов: " << std::endl;
        std::cout << "3. Кол-во цехов в работе: " << std::endl;
        std::cout << "4. Эффективность" << std::endl;
        std::cin >> numCS;
        switch (numCS)
        {
        case 1:
        {
            std::cout << "Введите название КС: " << std::endl;
            std::cin >> newName;
            newst.name = newName;
            break;
        }
        case 2:
        {
            std::cout << "Укажите количество всех цехов: " << std::endl;
            std::cin >> newTotal_shops;
            newst.totalShops = newTotal_shops;
            break;
        }
        case 3:
        {
            std::cout << "Укажите кол-во цехов в работе: " << std::endl;
            std::cin >> newActivated_shops;
            newst.activatedShops = newActivated_shops;
            break;
        }
        case 4:
        {
            std::cout << "Укажите эффективность КС:" << std::endl;
            std::cin >> newEfficiency;
            newst.efficiency = newEfficiency;
            break;
        }
        default:
        {
            std::cout << "Произошла ошибка. Попробуем снова..." << std::endl;
            edit_CS(newst);
        }
        }
        CS_info(newst);
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
{
    flin >> p.kilometricMark;
    flin >> p.length;
    flin >> p.diameter;
    flin >> p.isUnderRepair;
}

void load_CS(CompressorStation& cs, std::ifstream& flin)
{
    flin >> cs.name;
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

        int choice;
        while (true) {
            std::cout << "Введите номер пункта меню: ";
            if (std::cin >> choice) {
                // Проверка, что введено целое число
                break;
            }
            else {
                // Очистка ошибки в потоке ввода
                std::cin.clear();
                // Удаление всех символов из потока ввода до конца строки
                std::cin.ignore(100, '\n');
                std::cout << "Неверный ввод. Введите целое число.\n";
            }
        }


        switch (choice) {
        case 1:
        {
            pipes = addPipe();
            break;
        }
        case 2:
        {
            edit_pipe(pipes);
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