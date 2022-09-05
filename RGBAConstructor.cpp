#include <iostream>
#include <cstdint>


class RGBA {
	using rgba_type = std::uint8_t;

private:
	rgba_type m_red{};
	rgba_type m_green{};
	rgba_type m_blue{};
	rgba_type m_alpha{};

public:
	RGBA(rgba_type red = 0, rgba_type green = 0, rgba_type blue = 0, rgba_type alpha = 255) :
		m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
	{
	}

	void print() {
		std::cout << "r = " << static_cast<int>(m_red)
			<< " g = " << static_cast<int>(m_green)
			<< " b = " << static_cast<int>(m_blue)
			<< " a = " << static_cast<int>(m_alpha)
			<< '\n';
	}
};

int main()
{
	RGBA teal{ 0, 127, 127 };
	teal.print();

	return 0;
}