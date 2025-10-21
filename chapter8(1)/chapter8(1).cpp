#include <iostream>
void static alphabet()
{
	int index = 97;
	while (index <= 122)
	{
		char letter = index;
		std::cout << letter << ' ' << index << '\n';
		++index;
	}
}

int main()
{
	alphabet();
}