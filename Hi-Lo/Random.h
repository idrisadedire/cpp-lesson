#ifndef RANDOM_H
#define RANDOM_H
#include <random>
namespace Random
{
	int get(int min, int max)
	{
		static std::random_device rd; 
		static std::mt19937 mt(rd()); 
		std::uniform_int_distribution<int> dist(min, max);
		return dist(mt);
	}
}

#endif // !
