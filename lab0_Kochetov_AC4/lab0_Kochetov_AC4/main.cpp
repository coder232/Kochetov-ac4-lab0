#include <iostream>;
#include <string>;
#include "windows.h";
struct Pipe {
    std::string kilometricMark; // ������������ ������� (��������)
    double length; // �����, ��
    double diameter; // �������, ��
    bool isUnderRepair; // ������� "� �������"
};
struct CompressorStation {
    std::string name; // �������� ������������� �������
    int totalShops; // ����� ���������� �����
    int activatedShops; // ���������� ����� � ������
    double efficiency; // ������������� (���������� ����������)
};
int main() {
    CompressorStation station;
    bool running = true;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    while (running) {
        std::cout << "����:" << std::endl;
        std::cout << "1. ������ ������ ������������� �������" << std::endl;
        std::cout << "2. ������� ���������� � ������������� �������" << std::endl;
        std::cout << "3. ����� �� ���������" << std::endl;
        std::cout << "������� ����� ������ ����: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "������� �������� ������������� �������: ";
            std::cin.ignore(); // ������� ������ �����
            std::getline(std::cin, station.name);

            std::cout << "������� ����� ���������� �����: ";
            std::cin >> station.totalShops;

            std::cout << "������� ���������� ����� � ������: ";
            std::cin >> station.activatedShops;

            std::cout << "������� ���������� ������������� (�� 0 �� 1): ";
            std::cin >> station.efficiency;

            std::cout << "������ ������������� ������� ������� ������." << std::endl;
            break;

        case 2:
            std::cout << "���������� � ������������� �������:" << std::endl;
            std::cout << "��������: " << station.name << std::endl;
            std::cout << "����� ���������� �����: " << station.totalShops << std::endl;
            std::cout << "���������� ����� � ������: " << station.activatedShops << std::endl;
            std::cout << "�������������: " << station.efficiency << std::endl;
            break;

        case 3:
            std::cout << "����� �� ���������." << std::endl;
            running = false;
            break;

        default:
            std::cout << "�������� �����. ���������� ��� ���." << std::endl;
            break;
        }

        std::cout << std::endl;
    }

    return 0;
}