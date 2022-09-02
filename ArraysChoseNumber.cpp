#include <iostream>
#include <iterator>

int main()
{
	constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
	constexpr int arraySize{ static_cast<int>(std::size(array)) };
	int choice{};
	do {
		std::cout << "Enter a number between 1 and 9: ";
		std::cin >> choice;
		if (std::cin.fail())
		{
			std::cin.clear(); // reset any error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
		}
	} while (choice < 1 || choice > 9);

	int choiceIndex{};
	for (int index{ 0 }; index < arraySize; ++index) {
		std::cout << array[index] << ' ';
		if (array[index] == choice)
			choiceIndex = index;
	}
	std::cout << "\nThe number "<< choice << " has index " << choiceIndex << '\n';

	return 0;
}
