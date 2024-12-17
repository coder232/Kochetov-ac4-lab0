#include "GTS.h"
#include "Pipe.h"
#include "CStations.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include "Connections.h"

/*bool GTS::HasConnection(const unordered_map<int, Pipe>& Pipes, const int& CSid1, const int& CSid2)
{
	bool hasPipe = false;
	for (auto& elem : Pipes)
	{
		if ((elem.second.GetCSid1() == CSid1 && elem.second.GetCSid2() == CSid2)
			|| (elem.second.GetCSid1() == CSid2 && elem.second.GetCSid2() == CSid1))
		{
			hasPipe = true;
		}
	}
	return hasPipe;
}

void GTS::ConnectInGTS(unordered_map<int, Pipe>& Pipes, unordered_map<int, CStations>& Stations)
{
	int pipeDiameter = 0;
	cout << "Введите диаметр трубы: ";
	pipeDiameter = GetCorrectDiameter(500, 1400);
	int idConnectedPipe = 0;

	for (auto& elem : Pipes)
	{
		if (elem.second.GetDiameter() == pipeDiameter && elem.second.ConnectionNotBusy())
		{
			idConnectedPipe = elem.first;
			break;
		}
	}

	if (idConnectedPipe == 0)
	{
		bool flag = true;
		while (flag)
		{
			cout << "Нет труб с таким диаметром!\nВы хотите добавить новую трубу?" << endl
				<< "1) Да" << endl
				<< "2) Нет" << endl
				<< "Пожалуйста, введите команду: ";
			switch (GetCorrectData(1, 2))
			{
			case 1:
			{
				Pipe pipe0;
				cin >> pipe0;
				pipe0.SetDiameter(pipeDiameter);
				Pipes.insert(make_pair(pipe0.GetId(), pipe0));
				idConnectedPipe = pipe0.GetId();
				flag = false;
			}
			break;
			case 2:
				return;
			default:
				cout << "Такой команды нет, попробуйте еще раз" << endl;
				break;
			}
		}
	}

	if (idConnectedPipe != 0)
	{
		cout << "Введите Id первой КС: ";
		int CSid1;
		CSid1 = GetCorrectData(1, int(Stations.size()));
		while (Stations.find(CSid1) == Stations.end())
		{
			cout << "\nКС с таким Id не существует! Попробуйте еще раз:" << endl;
			CSid1 = GetCorrectData(1, int(Stations.size()));
		}

		cout << "Введите Id второй КС: ";
		int CSid2;
		CSid2 = GetCorrectData(1, int(Stations.size()));
		while (Stations.find(CSid2) == Stations.end() || CSid2 == CSid1 || HasConnection(Pipes, CSid1, CSid2))
		{
			cout << "\nКС с таким Id не существует, она занята или уже соединена с первой КС! Попробуйте еще раз:" << endl;
			CSid2 = GetCorrectData(1, int(Stations.size()));
		}
		Pipes[idConnectedPipe].Connect(CSid1, CSid2);
	}
}*/

void GTS::ConnectInGTS1(unordered_map<int, Pipe>& Pipes, unordered_map<int, CStations>& Stations, unordered_map<int, connections>& Connections)
{
	if (Stations.size() == 0)
	{
		cout << "Недостаточно КС!";
		return;
	}
	if (Pipes.size() == 0)
	{
		cout << "Недостаточно труб!";
		return;
	}
	int k = 0;
	vector<int> free_cs;
	for (auto& elem : Stations)
	{
		if (elem.second.Get_Id_in() + elem.second.Get_Id_out() < 2)
		{
			k += 1;
			free_cs.push_back(elem.first);
		}
	}
	if (k < 2)
	{
		cout << "У вас нет незанятых КС!";
		return;
	}

	int n = 0;
	vector<int> free_pipes;
	for (auto& elem : Pipes)
	{
		if (elem.second.Get_free())
		{
			n += 1;
			free_pipes.push_back(elem.first);
		}
	}
	if (n < 1)
	{
		cout << "У вас нет незанятых труб!";
		return;
	}

	connections pipe_connect;
	cout << "Введите Id входной КС: ";
	pipe_connect.id_entry = inputNumber<int>(cin);
	if (find(free_cs.begin(), free_cs.end(), pipe_connect.id_entry) == free_cs.end())
	{
		while (true)
		{
			cout << "Нет свободной КС с таким Id, попробуйте еще раз: ";
			pipe_connect.id_entry = inputNumber<int>(cin);
			if (find(free_cs.begin(), free_cs.end(), pipe_connect.id_entry) != free_cs.end())
			{
				Stations[pipe_connect.id_entry].Set_Id_in(Stations[pipe_connect.id_entry].Get_Id_in() + 1);
				break;
			}
		}
	}
	else
	{
		Stations[pipe_connect.id_entry].Set_Id_in(Stations[pipe_connect.id_entry].Get_Id_in() + 1);
	}

	cout << "Введите Id выходной КС: ";
	pipe_connect.id_out = inputNumber<int>(cin);
	if (find(free_cs.begin(), free_cs.end(), pipe_connect.id_out) == free_cs.end() || (pipe_connect.id_out == pipe_connect.id_entry))
	{
		while (true)
		{
			cout << "Нет КС с таким Id, попробуйте еще раз: ";
			pipe_connect.id_out = inputNumber<int>(cin);
			if (find(free_cs.begin(), free_cs.end(), pipe_connect.id_out) != free_cs.end() && (pipe_connect.id_out != pipe_connect.id_entry))
			{
				Stations[pipe_connect.id_out].Set_Id_out(Stations[pipe_connect.id_out].Get_Id_out() + 1);
				break;
			}
		}
	}
	else
	{
		Stations[pipe_connect.id_out].Set_Id_out(Stations[pipe_connect.id_out].Get_Id_out() + 1);
	}

	int i = 0;
	int pipe_diameter;
	while (true)
	{
		cout << "Введите диаметр труб, которые вы хотите использовать (500, 700, 1000, 1400): ";
		pipe_diameter = GetCorrectDiameter(500, 1400);
		for (auto& idp : free_pipes)
		{
			if (Pipes[idp].GetDiameter() == pipe_diameter)
			{
				pipe_connect.id_pipe = idp;
				i += 1;
				Pipes[idp].Set_free(0);
				break;
			}
		}
		if (i == 1)
		{
			Connections[pipe_connect.id_entry] = pipe_connect;
			break;
		}
		else
		{
			cout << "Нет свободных труб с таким диаметром!";
			int new_id_pipe = AddNewPipeConnect(Pipes, pipe_diameter);
			pipe_connect.id_pipe = new_id_pipe;
			Pipes[new_id_pipe].Set_free(0);
			Connections[pipe_connect.id_entry] = pipe_connect;
			break;
		}
	}
}

int GTS::AddNewPipeConnect(unordered_map<int, Pipe>& Pipes, int diameter)
{
	cout << "Отсутствующий диаметр будет установлен:" << endl;
	Pipe pipe;
	cin >> pipe;
	pipe.SetDiameter(diameter);
	int new_pipe_id = pipe.GetId();
	Pipes.insert({ new_pipe_id, pipe });
	return new_pipe_id;
}

void GTS::ShowGTS(unordered_map<int,connections>& Connections)
{
	cout << "[ID ВХОДНОЙ  КС] | [ID ТРУБЫ] | [ID ВЫХОДНОЙ КС]" << endl;
	if (Connections.size() == 0)
	{
		cout << "Отсутствуют соединения!" << endl;
	}
	else
	{
		for (const auto& elem : Connections)
		{
			cout << "\t[" << elem.second.id_entry << "] \t[" << elem.second.id_pipe << "] \t[" << elem.second.id_out << "]\n";
		}
	}
}

void GTS::DeleteConnection(unordered_map<int,connections>& Connections, unordered_map<int, Pipe>& Pipes)
{
	cout << "Пожалуйста, введите id трубы, от которой хотите разорвать соединение: ";
	int idp = GetCorrectData(1, int(Pipes.size()));
	for (auto it = Connections.begin(); it != Connections.end();)
	{
		if (it->second.id_pipe == idp)
		{
			it = Connections.erase(it);
		}
		else
		{
			++it;
		}
	}
}
void GTS::dfs(int stationId, unordered_map<int, connections>& Connections, unordered_map<int, int>& state, vector<int>& result, bool& hasCycle) {
	if (state[stationId] == 1) {
		hasCycle = true;
		return;
	}
	if (state[stationId] == 0) {
		state[stationId] = 1; 
		for (auto& elem : Connections) {
			if (elem.second.id_entry == stationId) {
				dfs(elem.second.id_out, Connections, state, result, hasCycle);
			}
		}
		state[stationId] = 2;
		result.push_back(stationId);
	}
}

vector<int> GTS::topologSort(unordered_map<int, Pipe>& Pipes, unordered_map<int, CStations>& Stations, unordered_map<int, connections>& Connections)
{
	vector<int> result;
	unordered_map<int, int> enterEdges;
	unordered_map<int, int> outEdges;
	unordered_map<int, int> state;
	bool hasCycle = false;

	for (auto& elem : Connections)
	{
		if (elem.second.id_out != 0)
			enterEdges[elem.second.id_out]++;
	}
	for (auto& elem : Connections)
	{
		if (elem.second.id_entry != 0)
			outEdges[elem.second.id_entry]++;
	}

	for (auto& elem : Stations) {
		state[elem.first] = 0; 
	}

	for (auto& elem : Stations) {
		if (enterEdges.find(elem.first) == enterEdges.end() && outEdges.find(elem.first) != outEdges.end()) {
			dfs(elem.first, Connections, state, result, hasCycle);
		}
	}

	for (auto& elem : Stations) {
		if (state[elem.first] == 0) {
			dfs(elem.first, Connections, state, result, hasCycle);
		}
	}

	if (hasCycle) {
		return {};
	}

	reverse(result.begin(), result.end());
	return result;
}