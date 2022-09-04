#include <iostream>
#include <functional>

void clearInput() {
    std::cin.clear(); // reset failbit
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getInteger() {
    int num1{0};
    while (true) {
        std::cout << "choose a number: ";
        std::cin >> num1;
        if (std::cin.fail()) {
            clearInput();
            continue;
        }
        break;
    }

    return num1;
}

char getOperator() {
    char op{};
    while (op != '+' && op != '-' && op != '*' && op != '/') {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    }

    return op;
}

int add(int num1, int num2) {
    return  num1 + num2;
}

int subtract(int num1, int num2) {
    return num1 - num2;
}

int multiply(int num1, int num2) {
    return num1 * num2;
}

int devide(int num1, int num2) {
    return num1 / num2;
}

using ArithmeticFunction_type = std::function<int(int, int)>;

ArithmeticFunction_type getArithmeticFunction(char operator1) {
    switch (operator1) {
    case '+': return &add; break;
    case '-': return &subtract; break;
    case '*': return &multiply; break;
    case '/': return &devide; break;
    }

    return nullptr;
}

int main()
{
    int num1{ getInteger() };
    char operator1{ getOperator() };
    int num2{ getInteger() };

    ArithmeticFunction_type fcn{ getArithmeticFunction(operator1) };
    if (fcn)
        std::cout << num1 << ' ' << operator1 << ' ' << num2 << " = " << fcn(num1, num2) << '\n';

    return 0;
}