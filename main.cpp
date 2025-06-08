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

void mapRemaindersToHex(const std::vector<int> &remainders) 
{

	for (int i = remainders.size() - 1; i >= 0; i--) {
		int num{ remainders[i] };
				switch (num) {
			case 10: 
				std::cout << 'A';
				break;
			case 11:
				std::cout << 'B';
				break;
			case 12:
				std::cout << 'C';
				break;
			case 13:
				std::cout << 'D';
				break;
			case 14:
				std::cout << 'E';
				break;
			case 15:
				std::cout << 'F';
				break;
			default:
				std::cout << num;
		}
	}
}

int main()
{
	std::vector<int> v{};
	int number{ readDecimal() };

	std::vector<int> remainders{ getRemainders(number, v) };

	mapRemaindersToHex(remainders);
	return 0;
}