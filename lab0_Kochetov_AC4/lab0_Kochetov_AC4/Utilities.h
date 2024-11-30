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
			cin >> key;//!!!!!!!!!
		}
	}
}

string inputString(istream& in = cin);

template <typename T> // template to check different types of variables
T inputNumber(istream& in = cin) // check type
{
	T x;
	while ((in >> x).fail()	// check type
		|| in.peek() != '\n')	// is buffer empty (int/float check)
	{
		in.clear();
		in.ignore(10000, '\n');
		cout << "ERROR wrong type --> try again: ";
		cerr << x << endl; // LOGGING!!!!!!!
	}
	cerr << x << endl; // LOGGING!!!!!!!
	return x;
}
template int inputNumber(istream& in);
template double inputNumber(istream& in);

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

