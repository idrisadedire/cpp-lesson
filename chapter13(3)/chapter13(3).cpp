#include <iostream>

struct Fraction
{
	int nominator{};
	int denominator{ 1 };
};

void print(const Fraction& f)
{
	std::cout << f.nominator << '/' << f.denominator << '\n';
}

Fraction product(const Fraction& a, const Fraction& b)
{
	Fraction result{};
	result.nominator = a.nominator * b.nominator;
	result.denominator = a.denominator * b.denominator;
	return result;
}

int main()
{
	std::cout << "Enter a fraction (nominator/denominator): ";
	Fraction x{};
	char slash{};
	std::cin >> x.nominator >> slash >> x.denominator;

	std::cout << "Enter another fraction (nominator/denominator): ";
	Fraction y{};
	char slash2{};
	std::cin >> y.nominator >> slash >> y.denominator;

	std::cout << "The product of the two fractions is ";

	x = product(x, y);
	print(x);
	return 0;
}