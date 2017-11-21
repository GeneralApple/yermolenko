#include "stdafx.h"
#include <iostream>
#include "Vector.h"

int main()
{
	Vector<double> vector;
	double last_element;
	int lenght;

	for (int i = 0; i < 11; i++) {
		vector.addElement(i);
	}

	last_element = vector.removeLastElement();
	lenght = vector.getLen();

	std::cout << "Last element: " << last_element << std::endl;
	std::cout << "Length: " << lenght << std::endl;
	std::cout << "Elem at index: " << vector.getElementAtIndex(7) << std::endl;

	system("pause");

	return 0;
}

