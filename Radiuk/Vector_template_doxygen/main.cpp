#include <iostream>
#include "vector.hpp"

int main()
{
	Vector<int> vec(3);

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	for (int i = 0; i < vec.getElements(); ++i)
		std::cout << i << ": " << vec[i] << std::endl;

	vec.pop_back();
	std::cout << std::endl;
	for (int i = 0; i < vec.getElements(); ++i)
		std::cout << i << ": " << vec[i] << std::endl;

	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::cout << std::endl;
	for (int i = 0; i < vec.getElements(); ++i)
		std::cout << i << ": " << vec[i] << std::endl;
	vec.erase(3);
	std::cout << std::endl;
	for (int i = 0; i < vec.getElements(); ++i)
		std::cout << i << ": " << vec[i] << std::endl;
}
