#include <iostream>
#include <string>

int main()
{
    const std::string_view names[]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

    std::cout << "Enter a name: ";
    std::string username{};
    std::cin >> username;

    for (std::string_view name : names) {
        if (username == name) {
            std::cout << username << " was found.\n";
            return 0;
        }
    }
    std::cout << username << " was not found.\n";

    return 0;
}
