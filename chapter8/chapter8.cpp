#include <iostream>


int calculator(int num1, int num2, char operation)
{
 switch (operation)
 {
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return  static_cast<double>(num1) / static_cast<double>(num2);
	case '%':
		return num1 % num2;
	default:
		std::cout << "Invalid operation" << std::endl;
		return 0;
	}
}

int main() {
	int num1, num2;
	char operation;
	int result = 0;
	tryAgain:
	std::cout << "Enter first number: ";
	std::cin >> num1;
	if (num1 < 0) {
		std::cout << "Please enter a non-negative number." << std::endl;
		goto tryAgain;
	}

	reTry:
	std::cout << "Enter second number: ";
	std::cin >> num2;
	if (num2 < 0) {
		std::cout << "Please enter a non-negative number." << std::endl;
		goto reTry;
	}

	std::cout << "Enter operation (+, -, *, /, %): ";
	std::cin >> operation;
	result = calculator(num1, num2, operation);

	std::cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result;

}