#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;

#define INPUT_LINE(in, str) getline(in>>std::ws, str); \
						std::cerr << str << std::endl
#define PRINT_PARAM(out, x) out<< #x << "=" << x << std::endl
template <typename T>
T GetCorrectData(T min, T max)
	{
	T x;
	while ((std::cin >> x).fail() || std::cin.peek() != '\n' || x < min || x > max)
	{
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		std::cout << "\nПожалуйста, введите корректные данные. Данные должны быть в диапазоне [" << min << " - " << max << "]" << std::endl;
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
		cout << "Превышение количества допустимых элементов!" << endl
			<< "Попробуйте еще раз (Число элементов: " << notes.size() << "): ";
	}
}

template <typename T>
T GetCorrectDiameter(T min, T max)
{
	T diam;
	cin >> diam;
	while (((diam != 500) && (diam != 700) && (diam != 1000) && (diam != 1400)) || diam < min || diam > max || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "Please, enter the correct pipe diameter [500, 700, 1000, 1400]: ";
		cin >> diam;
	}
	cerr << diam << endl;
	return diam;
}


template <typename K>
unordered_map<int, K> removeKeyIfExists(unordered_map<int, K>& notes, int key) {
	while (true) {
		auto it = notes.find(key);
		if (it != notes.end()) {
			notes.erase(it);
			cout << "Удаление прошло успешно!" << endl;
			return notes;
		}
		else {
			cout << "Ключ " << key << " не существует!\nПожалуйста, введите существующий ключ: ";
			key = GetCorrectData(1, findMaxId(notes));
		}
	}
}
string inputString(istream& in = cin);
template<typename K, typename V>
K findMaxId(const std::unordered_map<K, V>& map) {
	if (map.empty()) {
		throw std::runtime_error("The unordered_map is empty.");
	}

	K maxId = std::numeric_limits<K>::min();

	for (const auto& pair : map) {
		if (pair.first > maxId) {
			maxId = pair.first;
		}
	}
	return maxId;
}

template <typename T> 
T inputNumber(istream& in = cin) 
{
	T x;
	while ((in >> x).fail()	// check type
		|| in.peek() != '\n')	// is buffer empty (int/float check)
	{
		in.clear();
		in.ignore(10000, '\n');
		cout << "ERROR wrong type --> try again: ";
	}
	cerr << x << endl; 
	return x;
}

class redirect_output_wrapper
{
	std::ios& stream;
	std::streambuf* const old_buf;
public:
	redirect_output_wrapper(std::ios& src)
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

