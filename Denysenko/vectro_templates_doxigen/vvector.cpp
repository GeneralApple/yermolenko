#include "stdafx.h"
#include <iostream>
#include "vvector.h"

int main()
{
	vvector<double> vector;
	double last_element;
	int lenght;

	for (int i = 0; i < 11; i++) {
		vector.add(i);
	}

	last_element = vector.pull_last();
	lenght = vector.size();

	std::cout << "Last element: " << last_element << std::endl;
	std::cout << "Length: " << lenght << std::endl;
	std::cout << "Elem at index: " << vector.get_index_element(7) << std::endl;

	system("pause");

	return 0;
}
