#pragma once
#include <unordered_map>
#include "Pipe.h"
#include "CStations.h"

class Operations
{
public:
	int id_entry;
	int id_pipe;
	int id_out;

	void EditPipe(Pipe& pipe);
	void EditPipes(unordered_map<int, Pipe>& pipes);
	void searchPipe(unordered_map<int, Pipe>& Pipes);


	void EditCStation(CStations& CStation);
	void EditCStations(unordered_map <int, CStations>& CStations);
	void searchCStations(unordered_map<int, CStations>& CStations);

	template <typename T>
	static void Show(std::unordered_map<int, T> objs)
	{
		if (objs.size() == 0)
			cout << "\nno objects!" << endl;
		for (const auto& [id, obj] : objs)
			cout << obj;
	}
};

