#include <iostream>

class IntPair{
public:
	int m_num1{};
	int m_num2{};

	void set(int a,int b) 
	{
		m_num1 = a;
		m_num2 = b;
	}
	void print() 
	{
		std::cout << "Pair(" << m_num1 << ", " << m_num2 << ")\n";
	}
};

int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	return 0;
}