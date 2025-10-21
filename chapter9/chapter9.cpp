#include <iostream>
#include "Random.h" 

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

bool playHiLo(int guesses, int min, int max)
{
	std::cout << "Let's play a game. I'm thinking of a number between " << min << " and " << max << ". You have " << guesses << " tries to guess what it is.\n";
	const int number{ Random::get(min, max) };

	for (int count{ 1 }; count <= guesses; ++count)
	{
		std::cout << "Guess #" << count << ": ";

		int guess{};
		std::cin >> guess;
		if (clearFailedExtraction())
		{
			std::cout << "Oops, that input is invalid.  Please try again.\n";
			--count;
			continue;
		}
		clearInputStream();

		if (guess < min || guess > max)
		{
			std::cout << "Your guess is out of range. Please try again.\n";
			--count;
			continue;
		}

		if (guess > number)
			std::cout << "Your guess is too high.\n";
		else if (guess < number)
			std::cout << "Your guess is too low.\n";
		else
		{
			std::cout << "Correct! You win!\n";
			return true;
		}
	}

	std::cout << "Sorry, you lose. The correct number was " << number << '\n';
	return false;
}

bool playAgain()
{
	while (true)
	{
		char ch{};
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> ch;
		if (clearFailedExtraction())
		{
			std::cout << "Oops, that input is invalid.  Please try again.\n";
			continue;
		}
		clearInputStream();

		switch (ch)
		{
		case 'y': return true;
		case 'n': return false;
		}

	}
}

int main()
{
	constexpr int guesses{ 7 };
	constexpr int min{ 1 };
	constexpr int max{ 100 };
	std::cout << "Welcome to Hi-Lo!\n";

	do
	{
		playHiLo(guesses, min, max);
	} while (playAgain());

	std::cout << "Thank you for playing.\n";

	return 0;
}