#include <iostream>
#include <array>
#include <algorithm>
#include <string>

struct Student
{
	std::string name{};
	int score{};
};

int main()
{
    std::array<Student, 8> arr{
  { { "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 }, // Dan has the most points (8).
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 } }
    };

    const auto best{
        std::max_element(arr.begin(), arr.end(),[](Student a, Student b) {return (a.score < b.score);})
    };

    std::cout << best->name << " is the best student\n";

	return 0;
}