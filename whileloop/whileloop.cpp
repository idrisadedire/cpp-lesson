#include <iostream>

int main()
{
skip:
    std::cout << "Enter a positive integer: ";
    int num{};
    std::cin >> num;

    if (num <= 0)
        goto skip;

    int count{ 1 };
    while (count <= num)
    {
        std::cout << count << ' ';
        if (count % 1 == 0) 
        {
        std::cout << '\n';
		}
    
        ++count;
    }

    std::cout << "done!\n";

    return 0;
}