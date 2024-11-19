#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;

template <typename T>
T GetCorrectData(T min, T max)
{
	T x;
	while ((std::cin >> x).fail() || std::cin.peek() != '\n' || x < min || x > max)
	{
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		std::cout << "\n����������, ������� ���������� ������. ������ ������ ���� � ��������� [" << min << " - " << max << "]" << std::endl;
	}
	cerr << x << endl;

	return x;
}
template <typename T>
T& SelectElement(unordered_map<int, T>& notes, int key)
{
	auto it = notes.find(key);
	if (it != notes.end())
	{
		return it->second;
	}
	else
	{
		cout << "���������� ���������� ���������� ���������!" << endl
			<< "���������� ��� ��� (����� ���������: " << notes.size() << "): ";
	}
}


template <typename K>
unordered_map<int, K> removeKeyIfExists(std::unordered_map<int, K>& notes, int key) {
	if (notes.find(key) != notes.end()) {
		notes.erase(key);
		cout << "�������� ������ �������!" << endl;
		return notes;
	}
	else {
		cout << "���� " << key << " �� ����������!\n����������, ������� ������������ ����: ";
		int newKey;
		cin >> newKey;
		return removeKeyIfExists(notes, newKey);
	}
}

class redirect_output_wrapper
{
	std::ostream& stream;
	std::streambuf* const old_buf;
public:
	redirect_output_wrapper(std::ostream& src)
		:old_buf(src.rdbuf()), stream(src)
	{
	}

	~redirect_output_wrapper() {
		stream.rdbuf(old_buf);
	}
	void redirect(std::ostream& dest)
	{
		stream.rdbuf(dest.rdbuf());
	}
};