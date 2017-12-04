
#include <iostream>
using namespace std;

int Size = 5;

class array {
	private:
		int* a;
		int size;
		int el_numb;
	public:
		array();
		array(int Size);
		~array();
		int get_size();
		void push_back(int);
		void print_array();
		int& operator[] (int el) {
			if (el>size) {
				cout << "Out of size " << endl;
				cout << a[0];
				}
			return this->a[el];
			}
	};

array::array() {
	size = 5;
	el_numb = 0;
	a = new int[size]; 
	}

array::array(int Size){
	size = Size;
	el_numb = 0;
	a = new int[size];
	}

array::~array() {
	delete [] a;
	}

int array::get_size() {
	return size;
	}

void array::push_back(int new_el) {
	if (el_numb < size) {
		(*this)[el_numb] = new_el;
		++el_numb;
		}
	else {
		int* a1 = new int[el_numb];
		for (int i = 0; i < el_numb; i++)
			a1[i] = a[i];
		delete [] a;
		a = a1;
		}
	a[el_numb] = new_el;
	el_numb++;
	}

void array::print_array() {
	for (int i = 0; i < (*this).el_numb; i++)
		cout << (*this)[i] << "";
	cout << endl;
	}	

int main() {
	array a;
	cout << "Size is " << a.get_size() << endl;
	a.push_back(2);
	a.print_array();
	a.push_back(3);
	a.print_array();
	a.push_back(4);
	a.print_array();
	cout << "Size is " << a.get_size() << endl;
	return 0;
	}
		
	
