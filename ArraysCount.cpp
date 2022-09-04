#include <array>
#include <numeric> // std::reduce
#include <iostream>


enum Items 
{
    healthPotion,
    torches,
    arrows,
    max_items
};

using inventory_t = std::array<int, Items::max_items>;

int countTotalItems(inventory_t arr) {
    return std::reduce(arr.begin(), arr.end());
}

int main()
{
    inventory_t inventory{ 2, 5, 10 };


    std::cout << "The player has " << countTotalItems(inventory) << " item(s) in total.\n";
    std::cout << "The player has " << inventory[Items::torches] << " torch(es)\n";
    return 0;
}
