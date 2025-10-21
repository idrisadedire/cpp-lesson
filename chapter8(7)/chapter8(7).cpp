#include <iostream>
void static fizzbuzz(int value)
{
    for (int i{ 1 }; i <= value; ++i)
    {
        bool printed{ false };
        if (i % 3 == 0)
        {
            std::cout << "Fizz ";
            printed = true;
        }
        if (i % 5 == 0)
        {
            std::cout << "Buzz ";
            printed = true;
        }
        if (i % 7 == 0)
        {
            std::cout << "pop ";
            printed = true;
        }
        if
            (!printed)
            std::cout << i << ' ';

        std::cout << '\n';
    }
}

int main()
{
    fizzbuzz(150);

    return 0;
}
