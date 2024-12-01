#include <iostream>
#include <fstream>
#include <cstdlib>  
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <format>
#include <queue>
#include "Pipe.h"
#include "CStations.h"
#include "Operations.h"
#include "Utilities.h"
#include "filtherr.h"
using namespace std;
using namespace chrono;

int MainMenu()
{
	cout << endl << "Меню:" << endl;
	cout << "1. Добавить трубу" << endl;
	cout << "2. Добавить КС" << endl;
	cout << "3. Показать все объекты" << endl;
	cout << "4. Редактировать трубу" << endl;
	cout << "5. Редактировать КС" << endl;
	cout << "6. Удалить трубу" << endl;
	cout << "7. Удалить КС" << endl;
	cout << "8. Сохранить" << endl;
	cout << "9. Загрузить" << endl;
	cout << "10. Поиск по фильтру" << endl;
	cout << "0. Выход" << endl;
	cout << endl << "Пожалуйста, введите номер команды: ";
	return GetCorrectData(0, 10);
}

void save_d(unordered_map<int, Pipe>& Pipes, unordered_map<int, CStations>& Stations) {
	cout << "\n[8] Сохранение в файл" << endl;
	ofstream fout;
	string fileName;
	cout << "Пожалуйста, введите имя файла: ";
	cin.ignore();
	getline(cin, fileName);///!!!!!!!!!!!!!!!!
	fout.open(fileName);
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else {
		fout << Pipes.size() << endl;
		for (const auto& elem : Pipes)
			fout << elem.second;
		cout << "Данные о трубах были успешно сохранены!" << endl;

		fout << Stations.size() << endl;
		for (const auto& elem : Stations)
			fout << elem.second;
		cout << "Данные о КС быи успешно сохранены!" << endl;
	}
	fout.close();
}
void load_d(unordered_map<int, Pipe>& Pipes, unordered_map<int, CStations>& Stations) {
	cout << "\n[9] Загрузка из файла" << endl;
	ifstream fin;
	string fileName;
	cout << "Пожалуйста, введите имя файла: ";
	cin.ignore();
	getline(cin, fileName);//!!!!!!!!!!!!!
	fin.open(fileName);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else {
		int pipesSize;
		fin >> pipesSize;
		if (pipesSize == 0)
			cout << "Нет информации о трубах!" << endl;
		else {
			cout << "Данные о трубах были успешно загружены!" << endl;
		}
		while (pipesSize-- > 0)
		{
			Pipe pipe0;
			fin >> pipe0;
			Pipes.insert({ pipe0.GetId(), pipe0 });
		}

		int csSize;
		fin >> csSize;
		if (csSize == 0)
			cout << "нет информации о КС!" << endl;
		else {
			cout << "Данные о КС были успешно загружены!" << endl;
		}
		while (csSize-- > 0)
		{
			CStations station0;
			fin >> station0;
			Stations.insert({ station0.GetId(), station0 });
		}
		fin.close();
	}
}
void filtering(unordered_map<int, Pipe>& Pipes, unordered_map<int, CStations>& Stations, Operations& operations) {
	bool flag = true;
	while (flag) {
		cout << "\n[10] Поиск" << endl;
		cout << "Что вы хотите найти?" << endl;
		cout << "1. Трубы" << endl;
		cout << "2. КС" << endl;
		cout << "3. Вернуться" << endl;
		cout << "Введите команду: ";
		int cm = GetCorrectData(1, 3);
		unordered_set<int> nameResults;
		switch (cm) {
		case 1: {
			nameResults = selectByChosenFilter(Pipes);
			if (nameResults.empty()) {
				cout << "Нет труб с таким именем!" << endl;
			}
			else {
				cout << "Найдены трубы:" << endl;
				// Вывод идентификаторов найденных труб
				for (int id : nameResults) {
					auto it = Pipes.find(id);
					if (it != Pipes.end()) {
						cout << "Труба с ID " << id << ": ";
						cout << it->second;
					}
				}
				cout << endl;
				operations.EditPipes(Pipes, nameResults);
			}
			break;
		}
		case 2: {
			cout << "\nПоиск КС..." << endl;
			nameResults = selectByChosenFilter(Stations);
			if (nameResults.empty()) {
				cout << "Нет КС с таким именем!" << endl;
			}
			else {
				cout << "Найдены КС:" << endl;
				for (int id : nameResults) {
					auto it = Stations.find(id);
					if (it != Stations.end()) {
						cout << "KC с ID " << id << ": ";
						cout << it->second;
					}
				}
				cout << endl;
				operations.EditCStations(Stations, nameResults);
			}
			break;
		}
		case 3:
			flag = false;
			break;
		default:
			cout << "Пожалуйста, введите точную команду!" << endl;
			break;
		}
	}
}

using std::cin;
using std::cout;

int main()
{
	system("chcp 1251");
	redirect_output_wrapper cerr_out(cerr);
	string time = format("{:%d_%m_%Y %H_%M_%OS}", system_clock::now() + hours(3));
	ofstream logfile("log_" + time);
	if (logfile) {
		cerr_out.redirect(logfile);
		//cout << endl << "CIN:" << endl;
		//cin_out.redirect(logfile);
	}
	unordered_map<int, Pipe> Pipes = {};
	unordered_map<int, CStations> Stations = {};
	Operations operations;
	while (true) {
		switch (MainMenu())
		{
		case 1:
		{
			cout << "\n[1] Добавление новой трубы..." << endl;
			Pipe pipe0;
			cin >> pipe0;
			Pipes.insert({ pipe0.GetId(), pipe0 });
			break;
		}
		case 2:
		{
			cout << "\n[2] Добавление новой КС..." << endl;
			CStations station0;
			cin >> station0;
			Stations.insert({ station0.GetId(), station0 });
			break;
		}
		case 3:
		{
			cout << "\n[3] Показать все объекты: " << endl;
			
			Operations::Show(Pipes);
			Operations::Show(Stations);
			break;
		}
		case 4:
		{
			if (Pipes.size() == 0) {
				cout << "\n0 труб доступно!" << endl;
			}
			else {
				cout << "\n[4] редактирование трубы: " << endl;
				cout << "Введите ID: ";
				int id;
				while (true) {
					id = GetCorrectData(1, numeric_limits<int>::max());
					if (Pipes.find(id) != Pipes.end())
						break;
					else
						cout << "Трубы с таким id не существует, попробуйте еще раз!" << endl;
				}
				Pipe& pipe0 = SelectElement(Pipes, id);
				pipe0.EditPipe();
			}
			break;
		}
		case 5:
		{
			if (Stations.size() == 0) {
				cout << "\n0 КС доступно!" << endl;
			}
			else {
				cout << "\n[5] Редактирование КС: " << endl;
				cout << "Введите ID: ";
				int id;
				while (true) {
					id = GetCorrectData(1, numeric_limits<int>::max());
					if (Stations.find(id) != Stations.end())
						break;
					else
						cout << "КС с таким id не существует, попробуйте еще раз!" << endl;
				}
				CStations& station0 = SelectElement(Stations, id);
				station0.EditCStation();
			}
			
			break;
		}
		case 6:
		{
			if (Pipes.size() == 0) {
				cout << "\n0 труб доступно!" << endl;
			}
			else {
				cout << "\n[6] Удаление трубы: " << endl;
				cout << "Введите ID: ";
				int key0;
				cin >> key0;///!!!!!!!!!!!!!!!!!
				removeKeyIfExists(Pipes, key0);
			}
			break;
		}
		case 7:
		{
			if (Stations.size() == 0) {
				cout << "\n0 станций доступно!" << endl;
			}
			else {
				cout << "\n[7] удаление станции: " << endl;
				cout << "Введите ID: ";
				int key0;
				cin >> key0;//!!!!!!!!!!!!
				removeKeyIfExists(Stations, key0);
			}
			break;
		}
		case 8:
		{
			save_d(Pipes, Stations);
			break;
		}
		case 9:
		{
			load_d(Pipes, Stations);
			break;
		}
		case 10:
		{
			filtering(Pipes, Stations, operations);
			break;
		}
		case 0:
		{
			return false;
			break;
		}
		default:
		{
			cout << endl << "В системе нет такой команды, попробуйте еще раз" << endl;
			break;
		}
		}
	}
	return 0;
}

