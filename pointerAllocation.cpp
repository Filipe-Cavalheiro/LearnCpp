#include <algorithm> // std::sort
#include <iostream>
#include <string>

int main()
{
    int numNames{ 0 };
    std::cout << "How many names would you like to enter? ";
    std::cin >> numNames;
    std::string* namesArray{ new std::string[numNames]{} };
    std::string name{};

    for (int i{ 0 }; i < numNames; ++i) {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, name);
        namesArray[i] = name;
    }
    std::cout << '\n';

    std::sort(namesArray, namesArray + numNames);

    std::cout << "Here is your sorted list :  \n";
    for (int i{ 0 }; i < numNames; ++i)
        std::cout << "Name #" << i + 1 << ": " << namesArray[i] << '\n';

    delete[] namesArray;

    return 0;
}
