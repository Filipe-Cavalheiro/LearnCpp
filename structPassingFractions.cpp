#include <iostream>

struct Fraction
{
    int numerator{0};
    int denominator{1};
};

Fraction getFraction()
{
    Fraction temp;
    std::cout << "Enter a value for the numerator: ";
    std::cin >> temp.numerator;
    std::cout << "Enter a value for the denominator: ";
    std::cin >> temp.denominator;

    return temp;
}

void printFractionMultiplication(const Fraction& num1, const Fraction& num2)
{
    std::cout << "Your fractions multiplied together: " << num1.numerator * num2.numerator << '/' << num1.denominator * num2.denominator;
}

int main()
{
    Fraction fraction1 { getFraction() };
    Fraction fraction2 { getFraction() };

    printFractionMultiplication(fraction1, fraction2);
    return 0;
}
