#include <iostream>
void static fizzbuzz(int value)
{
    for (int i{ 1 }; i <= value; ++i)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            std::cout << "FizzBuzz ";
        }
        else if (i % 3 == 0)
        {
            std::cout << "Fizz ";
        }
        else if (i % 5 == 0)
        {
            std::cout << "Buzz ";
        }
        else
        {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    fizzbuzz(20);

    return 0;
}
