#include <iostream>

int* find(int* arrStart, int* arrLast, int key) {
    while (arrStart != arrLast) {
        if (*arrStart == key)
            return arrStart;
        ++arrStart;
    }
    return arrLast;
}

int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Search for the first element with value 20.
    int* found{ find(std::begin(arr), std::end(arr), 12) };

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }

    return 0;
}
