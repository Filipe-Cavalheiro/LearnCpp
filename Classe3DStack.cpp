#include <iostream>
#include <array>
#include <cassert>

namespace config {
	const int arrSize{ 10 };
}

class Stack{
	std::array<int, config::arrSize> m_arr{};
	int m_size{0};
public:
	void reset() {
		m_size = 0;
	}

	bool push(int toAdd) {
		if (m_size == config::arrSize)
			return false;
		m_arr[m_size] = toAdd;
		++m_size;
		return true;
	}

	int pop() {
		assert(m_size > 0 && "Can not pop empty stack");
		return m_arr[--m_size];
	}

	void print() {
		std::cout << "( ";
		for (int i{ 0 }; i < m_size; ++i) {
			std::cout << m_arr[i] << ' ';
		}
		std::cout << ")\n";
	}
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}