#include <algorithm> 
#include <cmath>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using list_type = std::vector<int>;

namespace config
{
    constexpr int multiplierMin{ 2 };
    constexpr int multiplierMax{ 4 };
    constexpr int maximumWrongAnswer{ 4 };
}

void clearInput() {
    std::cin.clear(); // reset failbit
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getInteger() {
    int num1{ 0 };
    while (true) {
        std::cin >> num1;
        if (std::cin.fail()) {
            clearInput();
            continue;
        }
        break;
    }

    return num1;
}

int getRandomInt(int min, int max)
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    return std::uniform_int_distribution{ min, max }(mt);
}

list_type getNumbersVectors(int numNumbers, int start, int randMult) {
    list_type vec(static_cast<list_type::size_type>(numNumbers));

    int i{ start };
    for (int& number : vec)
    {
        number = (i * i * randMult);
        ++i;
    }

    return vec;
}

bool findAndRemove(list_type& numbers, int guess)
{
    auto found{ std::find(numbers.begin(), numbers.end(), guess) };

    if (found == numbers.end())
    {
        return false;
    }
    else
    {
        numbers.erase(found);
        return true;
    }
}

int findClosestNumber(int guess, const list_type& numbers)
{
    return *std::min_element(numbers.begin(), numbers.end(), [=](int a, int b) {
            return (std::abs(a - guess) < std::abs(b - guess));
        });
}

void printSuccess(list_type::size_type numbersLeft)
{
    std::cout << "Nice! ";

    if (numbersLeft == 0)
    {
        std::cout << "You found all numbers, good job!\n";
    }
    else
    {
        std::cout << numbersLeft << " number(s) left.\n";
    }
}

void endGame(int guess, list_type& vec) {
    int closest{ findClosestNumber(guess, vec) };
    if (std::abs(closest - guess) >= config::maximumWrongAnswer)
    {
        std::cout << " Try " << closest << " next time.\n";
        exit(0);
    }
    else
    {
        std::cout << "You\'re close\n";
    }
}

list_type startGame() {
    std::cout << "Start where? ";
    int start{ getInteger() };

    std::cout << "How many? ";
    int numNumbers{ getInteger() };

    int randMult{ getRandomInt(config::multiplierMin, config::multiplierMax) };

    list_type numbersVec{ getNumbersVectors(numNumbers, start, randMult) };

    std::cout << "I generated " << numNumbers << " square numbers. Do you know what each number is after multiplying it by " << randMult << " ? \n";

    return numbersVec;
}

int main()
{   
    list_type numbersVec{ startGame() };

    int guess{};
    while(!numbersVec.empty()){
        std::cout << '<';
        guess = getInteger();
        if (!findAndRemove(numbersVec, guess)) {
            endGame(guess, numbersVec);
        }
        else {
            printSuccess(numbersVec.size());
        }
    }

    return 0;
}