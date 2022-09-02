#include <iostream>
#include <iterator> // for std::size
#include <utility>

int main()
{
	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	constexpr int length{ static_cast<int>(std::size(array)) };

	bool change{ true };
	int startIndex{ 0 };// no magic numbers
	int iterations{ 1 };
	while(change)
	{
		change = false;
		for(int currentIndex = startIndex; currentIndex < length - iterations; ++currentIndex){
			if (array[currentIndex] > array[currentIndex + 1])
			{
				std::swap(array[currentIndex], array[currentIndex + 1]);
				change = true;
			}
		}
		++iterations;

	}

	// Now that the whole array is sorted, print our sorted array as proof it works
	for (int index{ 0 }; index < length; ++index)
		std::cout << array[index] << ' ';
	std::cout << '\n';

	return 0;
}
