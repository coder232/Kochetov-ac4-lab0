#include <iostream>
#include <string>
#include "windows.h"
#include <fstream> 
#include "Pipe.h"
#include "CStations.h"
#include <vector>

using namespace std;

void saveToFile(const vector<Pipe>& pipes, const vector<CompressorStation>& cs) {
    ofstream fout("saved_Pipe_CS.txt");
    if (fout) {
        if (pipes.size() == 0)
            cout << "Нет труб для загрузки" << endl;
        else {
            fout << pipes.size() << endl;
            for (const auto& p : pipes) {
                p.save(fout);
            }
        }
        if (cs.size() == 0)
            cout << "Нет КС для загрузки" << endl;
        else {
            fout << cs.size() << endl;
            for (const auto& CS : cs) {
                CS.save(fout);
            }
        }
    
        cout << "Труб сохранено: " << pipes.size() << endl
            << "КС сохранена = " << cs.size() << endl;
    }
    else {
        cout << "Ошибка загрузки файла" << endl;
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
void pipeCScheck(const vector<CompressorStation>& station, const vector<Pipe>&  pipes) {
    if (pipes.size() == 0) {
        cout << "Отсутствуют трубы" << endl;
    }
    else {
        for (size_t i = 0; i < pipes.size(); ++i) {
            cout << i + 1 << ". Труба " << i + 1 << endl;
        }
    }
    if (station.size() == 0) {
        cout << "Отсутствуют КС" << endl;
    }
    else {
        for (const auto& Station : station) {
            Station.CS_info();
            cout << endl;
        }
    }
}

int main() {
    vector<CompressorStation> station;
    vector<Pipe>  pipes;
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
            Pipe newPipes = Pipe::addPipe();
            pipes.push_back(newPipes);
            break;
        }
        case 2:
        {
            // Выбор трубы для редактирования
            int index;
            cout << "Введите номер трубы для редактирования: ";
            cin >> index;
            if (index > 0 && index <= pipes.size()) {
                pipes[index - 1].editPipe(); // Редактируем выбранную трубу
            }
            else {
                cout << "Неверный номер трубы." << endl;
            }
            break;
        }
        case 3:
        {
            pipeCScheck(pipes, station);
            break;
        }
        case 4:
        {
            CompressorStation newst = CompressorStation::Add_station();
            station.push_back(newst);
            break;
        }
        case 5:
        {
            for (size_t i = 0; i < station.size(); ++i) {
                cout << i + 1 << ". КС " << i + 1 << endl;
            }
            int index;
            cout << "Введите номер КС для редактирования: ";
            cin >> index;
            if (index > 0 && index <= station.size()) {
                station[index - 1].editCS(); // Редактируем выбранную трубу
            }
            else {
                cout << "Неверный номер KC." << endl;
            }
            break;
        }
        case 6:
        {
        
        saveToFile(pipes, station);
        break;
        }
        case 7:
        {
        //loadFromFile(pipes, station);
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