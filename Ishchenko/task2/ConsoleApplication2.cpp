
// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include "Header.h"
#include <vector>

int main()
{
	Vector<double> vector;
	int lenght;
	const int a = 1203;
	int b = 1;
	for (int i = 0; i < 100; i++) {
		vector.addElement(i);
	}
	
	lenght = vector.getLen();   

	
	std::cout << "Length: " << lenght << std::endl;
	std::cout << "add a to vector = " << vector.addElement(a) << std::endl;
	std::cout << "my add const = " << a << std::endl;
	std::cout << "Elem at index : " << vector.getElementAtIndex(99) << std::endl;
	std::cout << "add b to vector = " << vector.addElement(b) << std::endl;
	std::cout << "removed element = " << vector.removeLastElement() << std::endl;
	std::cout << "removed two elements  = " << vector.removeLastElement2() << std::endl;

	system("pause");

	return 0;
}
