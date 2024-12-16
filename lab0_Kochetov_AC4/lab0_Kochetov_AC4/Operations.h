#pragma once
#include <unordered_map>
#include <unordered_set>
#include "Pipe.h"
#include "CStations.h"

class Operations
{
public:

	void EditPipes(unordered_map<int, Pipe>& pipes,const unordered_set<int>& selectedPipes);

	void EditCStations(unordered_map <int, CStations>& CStations, unordered_set<int>& selected_stations);

	template <typename T>
	static void Show(std::unordered_map<int, T> objs)
	{
		if (objs.size() == 0)
			cout << "\nno objects!" << endl;
		for (const auto& [id, obj] : objs)
			cout << obj;
	}

};