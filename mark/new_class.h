#include <iostream>
using namespace std;

/**
 * @brief 
 * 
 * My array class
 * 
 * @return template T class Array
 */
template <class T>
class Array 
{
	private:
		T* ptr;
		size_t size;
		size_t numEl;
	public:
		Array ();
		Array (size_t SIZE);
		~Array ();
		size_t getSize ();
		void pushback (T &newEl);
		T& operator[] (size_t el);
		void printArray ();
};

/**
 * @brief 
 * 
 * Constructor
 * 
 * @return object class Array
 */
template <class T>
Array<T>::Array()
{	
	size = 5;
	numEl = 0;
	ptr = new T[size];
}

/**
 * @brief 
 * 
 * Constructor for SIZE elements
 * 
 * @return object class Array with SIZE element
 */
template <class T>
Array<T>::Array(size_t SIZE)
{
	size = SIZE;
	numEl = 0;
	ptr = new T[size];
} 

/**
 * @brief 
 * 
 * Destructor
 */
template <class T>
Array<T>::~Array()
{
	if(ptr)	delete [] ptr;
}

/**
 * @brief 
 * 
 * Get size function
 * 
 * @return size_t size
 */
template <class T>
size_t Array<T>::getSize()
{
	return size;
}

/**
 * @brief 
 * 
 * Pushback
 * 
 * @return nothing
 */
template <class T>
void Array<T>::pushback(T &newEl)
{
	if (numEl == size)
	{
		size*=2;
		T* ptr1 = new T[size];
		for (int i=0; i < size; i++)
			ptr1[i] = ptr[i];
		delete [] ptr;
		ptr = ptr1;
	}
	ptr[numEl] = newEl;
	numEl++;
}

/**
 * @brief 
 * 
 * Operator []
 * 
 * @return element with index el
 */
template <class T>
T& Array<T>::operator[] (size_t el)
{
	if (el>size)
	{
		cout << "Element out of bounds\n";
		cout << ptr[0];
	}
	return this->ptr[el];
}

/**
 * @brief 
 * 
 * print array function
 * 
 * @return nothing
 */
template <class T>
void Array<T>::printArray()
{
	for (int i=0; i < (*this).numEl; i++)
		cout<<(*this)[i]<<" ";
	cout << endl;
}