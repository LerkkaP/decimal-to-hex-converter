#include <iostream>
#include <vector>

int readDecimal()
{
	std::cout << "Enter a decimal number: ";
	int decimal{};
	std::cin >> decimal;
	return decimal;
}

std::vector<int> getRemainders(int number, std::vector<int> &v)
{
	if (number == 0) {
		return v;
	} else {
		int remainder{ number % 16 };
		v.push_back(remainder);
		return getRemainders(number / 16, v);
	}
}

int main()
{
	std::vector<int> v{};
	int number{ readDecimal() };

	std::vector<int> remainders{ getRemainders(number, v) };
	for (int remainder : remainders) {
		std::cout << remainder;
	}

	return 0;
}