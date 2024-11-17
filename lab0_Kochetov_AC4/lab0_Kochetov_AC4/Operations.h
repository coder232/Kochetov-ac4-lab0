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
	void EditPipes(vector <Pipe*>& pipes);
	void searchPipe(unordered_map<int, Pipe>& Pipes);

	void EditCStation(CStations& CStation);
	void EditCStations(vector <CStations*> CStations);
	void searchCStations(unordered_map<int, CStations>& CStations);
};

