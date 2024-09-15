#include <iostream>;
#include <string>;
#include "windows.h";
struct Pipe {
    std::string kilometricMark; // Километровая отметка (название)
    double length; // Длина, км
    double diameter; // Диаметр, мм
    bool isUnderRepair; // Признак "в ремонте"
};
struct CompressorStation {
    std::string name; // Название компрессорной станции
    int totalShops; // Общее количество цехов
    int activatedShops; // Количество цехов в работе
    double efficiency; // Эффективность (обобщающий показатель)
};
int main() {
    CompressorStation station;
    bool running = true;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    while (running) {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Задать объект компрессорной станции" << std::endl;
        std::cout << "2. Вывести информацию о компрессорной станции" << std::endl;
        std::cout << "3. Выйти из программы" << std::endl;
        std::cout << "Введите номер пункта меню: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите название компрессорной станции: ";
            std::cin.ignore(); // Очистка буфера ввода
            std::getline(std::cin, station.name);

            std::cout << "Введите общее количество цехов: ";
            std::cin >> station.totalShops;

            std::cout << "Введите количество цехов в работе: ";
            std::cin >> station.activatedShops;

            std::cout << "Введите показатель эффективности (от 0 до 1): ";
            std::cin >> station.efficiency;

            std::cout << "Объект компрессорной станции успешно создан." << std::endl;
            break;

        case 2:
            std::cout << "Информация о компрессорной станции:" << std::endl;
            std::cout << "Название: " << station.name << std::endl;
            std::cout << "Общее количество цехов: " << station.totalShops << std::endl;
            std::cout << "Количество цехов в работе: " << station.activatedShops << std::endl;
            std::cout << "Эффективность: " << station.efficiency << std::endl;
            break;

        case 3:
            std::cout << "Выход из программы." << std::endl;
            running = false;
            break;

        default:
            std::cout << "Неверный выбор. Попробуйте еще раз." << std::endl;
            break;
        }

        std::cout << std::endl;
    }

    return 0;
}