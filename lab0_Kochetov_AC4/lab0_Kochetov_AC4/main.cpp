#include <iostream>;
using namespace std;
int divide(int x, int y) {
	if (y == 0) {
		std::cout << "Error: division by zero!" << std::endl;
		return 0;  // Возвращаем 0 в случае деления на ноль
	}
	return x / y;
}

int main()
{
	cout << "hello world!" << endl;
	char userInput;
	int x, y;
	int div;
	cout << "input x: ";
	cin >> x;
	cout << "input y ";
	cin >> y;
	int result = divide(x, y);
	std::cout << "Division equals: " << result << std::endl;
	return 0;
}