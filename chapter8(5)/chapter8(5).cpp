#include <iostream>
int static sumTo(int value)
{
    int sum{ 0 };
    for (int i{ 1 }; i <= value; ++i)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    std::cout << sumTo(20);

    std::cout << '\n';
    return 0;
}
