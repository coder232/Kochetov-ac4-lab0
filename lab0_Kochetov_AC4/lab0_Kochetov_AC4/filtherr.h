#pragma once
#include<iostream>
#include <unordered_map>
#include <unordered_set>
#include "Pipe.h"
#include "CStations.h"
#include "Operations.h"
#include "Utilities.h"

template<typename T, typename U>
using Filter = bool(*)(T& val, U param);
template<typename T>
bool checkByName(T& val, string name)
{
	size_t pos = val.Getname().find(name);
	if (pos != std::string::npos) return true;
	else return false;
}
bool checkByRepairStatus(Pipe& p, bool status)
{
	return p.GetRepairStatus() == status;
}
bool checkByWSInWork(CStations& cs, double percent)
{
	return cs.GetPercentOfNonActiveWorkshops() >= percent;
}

template<typename T, typename U>
unordered_set<int> findByFilter(unordered_map<int, T>& map, Filter<T, U> f, U param)
{
	unordered_set<int> res;
	int i = 0;
	for (auto& [id, val] : map)
	{
		if (f(val, param))
			res.emplace(id);
	}
	return res;
}

unordered_set<int> selectByChosenFilter(unordered_map<int, Pipe>& map)
{
	unordered_set<int> res;
	cout << "Choose filter:\n1. Name\n2. Repair status" << endl;
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "Enter part of name: "; string name = inputString();
		res = findByFilter(map, checkByName, name);
		break;
	}
	case 2:
	{
		cout << "Enter status \"in repair\": "; bool status = GetCorrectData<int>(0, 1);
		res = findByFilter(map, checkByRepairStatus, status);
		break;
	}
	default:
		break;
	}
	return res;
}

unordered_set<int> selectByChosenFilter(unordered_map<int, CStations>& map)
{
	unordered_set<int> res;
	cout << "Choose filter:\n1. Name\n2. Percent % of ws in use" << endl;
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "Enter part of name: "; string name = inputString();
		res = findByFilter(map, checkByName, name);
		break;
	}
	case 2:
	{
		cout << "Enter percent %: "; double percent = GetCorrectData<double>(0.0, 100.0);
		res = findByFilter(map, checkByWSInWork, percent);
		break;
	}
	default:
		break;
	}
	return res;
}

template<typename T>
unordered_set<int> selectByChosenID(unordered_map<int, T>& map, unordered_set<int>& set = {})
{
	unordered_set<int> res;
	cout << "Enter all ID\nTo stop enter 0" << endl;
	while (1)
	{
		int id = inputNumber<int>();
		if (id == 0)
			break;
		if (set.size() == 0)
		{
			if (map.contains(id)) res.emplace(id);
		}
		else
			if (map.contains(id) and set.contains(id)) res.emplace(id);
	}
	return res;
}