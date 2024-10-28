#include <iostream>
#include <string>
#include "windows.h"
#include <fstream> 
#include "Pipe.h"
#include "CStation.h"
#include "LOG.h"

using namespace std;
using namespace pipe;
using namespace CStation;

void saveToFile(const Pipe& p, const CompressorStation& cs) {
    std::ofstream fout("saved_Pipe_CS.txt");
    if (fout) {
        int npipe = (p.getMark() == "Nothing") ? 0 : 1;
        fout << npipe << endl;
        if (npipe > 0) p.save(fout);

        int nCS = (cs.getName() == "Nothing") ? 0 : 1;
        fout << nCS << endl;
        if (nCS > 0) cs.save(fout);

        cout << "Труба сохранена = " << npipe << endl
            << "КС сохранена = " << nCS << endl;
    }
    else {
        cout << "Ошибка загрузки в файл" << endl;
    }
}

void loadFromFile(Pipe& p, CompressorStation& cs) {
    std::ifstream fin("saved_Pipe_CS.txt");
    if (fin) {
        int npipe, nCS;
        fin >> npipe;
        if (npipe > 0) p.load(fin);
        else p = Pipe();

        fin >> nCS;
        if (nCS > 0) cs.load(fin);
        else cs = CompressorStation();

        cout << "Pipe loaded = " << npipe << endl
            << "CS loaded = " << nCS << endl;
    }
    else {
        cout << "Ошибка загрузки" << endl;
    }
}


int main() {
    CompressorStation station;
    Pipe pipes;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    LOG::Logger logger("logfile.txt"); // Создание экземпляра логгера
    logger.log(LOG::INFO, "Program started."); // Пример логирования
    while (1) {
        cout << "Меню:" << endl;
        cout << "1. Добавить трубу" << endl;
        cout << "2. Редактировать трубу" << endl;
        cout << "3. Просмотреть информацию о трубах и КС" << endl;
        cout << "4. Добавить компрессорную станцию" << endl;
        cout << "5. Редактировать компрессорную станцию" << endl;
        cout << "6. Сохранить информацию о трубах и КС в файл" << endl;
        cout << "7. Загрузить информацию о трубах и КС из файла" << endl;
        cout << "8. Выйти из программы \n" << endl;

        int choice;//!!!
        while (true) {
            cout << "Введите номер пункта меню: ";
            choice = check_int(0, 0);
            break;
        }


        switch (choice) {
        case 1:
        {
            pipes = Pipe::addPipe();
            break;
        }
        case 2:
        {
            pipes.editPipe();
            break;
        }
        case 3:
        {

            pipes.pipe_info();
            cout << "\n" << endl;
            station.CS_info();
            break;
        }
        case 4:
        {
            station = CompressorStation::Add_station();
            break;
        }
        case 5:
        {
            station.editCS();
            break;
        }
        case 6:
        {
        saveToFile(pipes, station);
        break;
        }
        case 7:
        {
        loadFromFile(pipes, station);
        break;
        }
        case 8:
        {
            return 0;
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте еще раз. \n" << endl;
            break;
        }
        }

    }
    return 0;
}