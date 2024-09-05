#include <iostream>;
using namespace std;

int main()
{
	cout << "hello world!" << endl;
	char userInput;

	std::cout << "Введите символ: ";
	std::cin >> userInput;

	std::cout << "Вы ввели: " << userInput << std::endl;

	return 0;
}