
#include <iostream>
#include <limits>
#include <cstdlib>

void clearInputStream()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

bool clearFailedExtraction()
{
    if (!std::cin)
    {
        if (!std::cin.eof())
        {
            std::exit(0);
        }
		std::cin.clear();
        clearInputStream();

        return true;
    }
	return false;
}

double getDouble()
{
    while (true)
    {
    std::cout << "Enter a decimal number: ";
    double x{};
    std::cin >> x;
    return x;

    if (clearFailedExtraction())
    {
		std::cout << "Oops, that input is invalid.  Please try again.\n";
        continue;
    }
	clearInputStream();
	return x;
    }
}

char getOperator()
{
    while (true)
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;

        if (!clearFailedExtraction)

			clearInputStream();

        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation; 
        default: 
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
    } 
}

void printResult(double x, char operation, double y)
{
    std::cout << x << ' ' << operation << ' ' << y << " is ";

    switch (operation)
    {
    case'+':
        std::cout << (x + y) << '\n';
		break;
    case'-':
	    std::cout << (x - y) << '\n';
		break;
    case'*':
		std::cout << (x * y) << '\n';
        break;
    case'/':
        if (y != 0)
        std::cout << (x / y) << '\n';
    else
	    std::cout << "undefined (cannot divide by zero)\n";
	    break;
     default:
        std::cout << "unknown (this should never happen)\n";
		break;      
    }
}

int main()
{
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);

    return 0;
}
