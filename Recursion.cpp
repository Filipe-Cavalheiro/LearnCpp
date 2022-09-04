#include <iostream>

int recursive(int num) {
	if (!(num / 10))
		return num;
	else
		return recursive(num / 10) + num % 10;
}

int main()
{
	std::cout << recursive(12);

    return 0;
}