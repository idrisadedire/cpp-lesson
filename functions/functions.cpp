#include <iostream> // for std::cout

void doB()
{
    std::cout << "In doB()\n";
}

void doA()
{
    std::cout << "In doA()\n";

    doB();
}

void doC()
{
    std::cout << "My name is:  Idris Adedire Akorede\n";
}

// Definition of function main()
int main()
{
    std::cout << "Starting main()\n";
          
    doA();
    doB();
	doC();

    std::cout << "Ending main()\n";

    return 0;
}