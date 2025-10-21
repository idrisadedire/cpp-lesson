#include <iostream>

// write your sub function template here
template <typename T, typename W >
auto sub(T a, W b)
{
	return a - b;
}

int main()
{
	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}