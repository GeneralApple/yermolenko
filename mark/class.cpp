#include <iostream>
using namespace std;

class Array 
{
	private:
		int *ptr;
		int size;
		int numEl;
	public:
		Array ();
		Array (int SIZE);
		~Array ();
		int getSize ();
		void pushback (int);
		int& operator[] (int el)
		{
			if (el>size)
			{
				cout << "Element out of bounds\n";
				cout << ptr[0];
			}
			return this->ptr[el];
		}
		void printArray ()
		{
			for (int i=0; i < (*this).numEl; i++)
				cout<<(*this)[i]<<" ";
			cout << endl;
		}
};

Array::Array()
{
	size = 5;
	numEl = 0;
	ptr = new int[size];
}

Array::Array(int SIZE)
{
	size = SIZE;
	numEl = 0;
	ptr = new int[size];
}

Array::~Array()
{
  if(ptr) delete [] ptr;
}

int Array::getSize()
{
  return size;
}

void Array::pushback (int newEl)
{
	if (numEl == size)
	{
		size*=2;
		int* ptr1 = new int[size];
		for (int i=0; i < size; i++)
			ptr1[i] = ptr[i];
		delete [] ptr;
		ptr = ptr1;
	}
	ptr[numEl] = newEl;
	numEl++;
}


int main (int argc, char *argv[])
{
	Array A;
	int sz = A.getSize();
	cout << "Size = " << sz << endl;
	A.pushback(1);
	A.printArray();
	A.pushback(2);
	A.printArray();
	A.pushback(2);
	A.printArray();
	A.pushback(2);
	A.printArray();
	A.pushback(2);
	A.printArray();
	A.pushback(3);
	A.printArray();
	cout << "Size = " << A.getSize() << endl;
	return 0;
}


