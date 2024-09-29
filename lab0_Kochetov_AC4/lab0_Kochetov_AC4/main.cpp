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
void edit_CS(CompressorStation newst) { //4. Редактировать КС 
    int newTotal_shops, newActivated_shops, newEfficiency;
    std::string newName;
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
void SAVE_pipe(Pipe pipes) {
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
        outp << station.totalShops << std::endl;
        outp << station.efficiency << std::endl;
        std::cout << "данные записаны в файл saved_Pipe_CS.txt" << std::endl;
        outp.close(); // Закрытие файла
    }
    else {
        std::cout << "Не получается открыть файл." << std::endl;
    }
}
void LOAD_pipe(Pipe& p) {
    std::ifstream inp("saved_Pipe_CS.txt");
    if (!inp) {
        std::cout << "Не удалось открыть файл!" << std::endl;
        return;
    }

    std::getline(inp, p.kilometricMark); // Чтение километрической отметки
    inp >> p.length;                      // Чтение длины
    inp >> p.diameter;                    // Чтение диаметра
    int repairStatus;
    inp >> repairStatus;                  // Чтение статуса ремонта
    p.isUnderRepair = (repairStatus == 1); // Присваивание статуса

    inp.close();
    std::cout << "Данные о трубе загружены." << std::endl;
}
void LOAD_CS(CompressorStation& st) {   // Загрузка данных о КС из файла
    std::ifstream inp("saved_Pipe_CS2.txt");
    if (!inp) {
        std::cout << "Не удалось открыть файл!" << std::endl;
        return;
    }

    std::getline(inp, st.name); 
    inp >> st.totalShops;                      
    inp >> st.activatedShops;                    
    inp >> st.efficiency;

    inp.close();
    std::cout << "Данные о КС загружены." << std::endl;
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
        std::cout << "6. Сохранить информацию о трубах в файл" << std::endl;
        std::cout << "7. Сохранить информацию о компрессорной станции в файл" << std::endl;
        std::cout << "8. Загрузить информацию о трубах из файла" << std::endl;
        std::cout << "9. Загрузить информацию о компрессорной станции из файла" << std::endl;
        std::cout << "10. Выйти из программы \n" << std::endl;
        std::cout << "Введите номер пункта меню: ";

        int choice;
        std::cin >> choice;

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
            if (pipes.kilometricMark == "Nothing") {
                std::cout << "Труба не задана, нечего сохранить! \n";
            }
            else {
                SAVE_pipe(pipes);
            }
            break;
        }
        case 7:
        {
            if (station.name == "Nothing") {
                std::cout << "КС не задана, нечего сохранить! \n";

            }
            else {
                SAVE_CS(station);
            }
            break;
        }
        case 8:
        {
            LOAD_pipe(pipes);
            pipe_info(pipes);
            break;
        }
        case 9:
        {
            LOAD_CS(station);
            CS_info(station);
            break;
        }
        case 10:
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