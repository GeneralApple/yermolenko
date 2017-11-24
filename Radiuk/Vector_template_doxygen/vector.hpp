
/**
* std::vector implementation
* @author Andrii Radiuk
* @version 0.0.1
*/

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdio.h>

/** \class Vector
* \brief 'Vector' class implementation
*
* This class allows a comfortable manipulation of allocated memory via such implemented methods:\n
*	getElements() - return the number of existing elements in array\n
*	getSize() - return the total array size\n
*	push_back() - add an element to the end\n
*	pop_back() - delete last element from the array\n
*	erase(int it) - delete element from the array requested by it\n
*
* \return class Vector
*/

template <class type>

class Vector
{
private:
	int size;	/**< vector size	*/
	int elements;	/**< number of existing elements in the array */
	type * vector;	/**< pointer for operating with array */
	void reallocate();	/**< increase vector size by reallocating it to another place */

public:
	/** \brief Constructor\n
	 *	Constructor which can take an int as a size of array
	 */
	Vector(int s = 100);

	/** \brief Destructor\n
	 *	Plain and simple. Free previously allocated memory
	 */
	~Vector();

	/**	\brief getElements()\n
	 *	Returns number of filled array cells
	 */
	int getElements() {return elements;};

	/** \brief getSize()\n
	 *	Returns array size
	 */
	int getSize() {return size;};

	/**	\brief push_back()\n
	 *	Adds an element to the end of array
	 */
	void push_back(type elem);

	/**	\brief pop_back()\n
	 *	Removes the last element from the array
	 */
	void pop_back();

	/**	\erase()\n
	 *	Remove requested element from array
	 */
	void erase(int it);

	/**	operator[]\n
	 *	Return an element by its index
	 */
	type & operator[](int it) {return (vector[it]);};
};

/**	\fn Vector(int s)
*	\brief Constructor
*	\param s - requested array getSize
*/
template <class type>
Vector<type>::Vector(int s) : size(s), elements(0)
{
	vector = new type[size];
}

/**	\fn ~Vector()
*	\brief Destructor
*	\param None
*/
template <class type>
Vector<type>::~Vector()
{
	std::cout << "here?";
	fflush(stdout);
	delete[] vector;
}

/**	\fn reallocate()
*	\brief Increases vector size
*	\param None
*/
template <class type>
void Vector<type>::reallocate()
{
	type * newVector = new type[size * 2];

	for (int i = 0; i < elements; ++i)
		newVector[i] = vector[i];

	delete[] vector;
	vector = newVector;
}

/**	\fn push_back(type elem)
*	\brief Adds an element to the end of array
*	\param elem - element to put into the array
*/
template <class type>
void Vector<type>::push_back(type elem)
{
	if (elements >= size)
		reallocate();

	vector[elements] = elem;
	elements++;
}

/**	\fn pop_back()
*	\brief Removes the last element from the array
*	\param None
*/
template <class type>
void Vector<type>::pop_back()
{
	if (elements == size)
		elements--;
	size--;

	type * newVector = new type[size];

	for (int i = 0;i < elements &&  i < size; ++i)
		newVector[i] = vector[i];

	delete[] vector;
	vector = newVector;
}

/**	\fn erase(int it)
*	\brief Remove requested element from array
*	\param it - requested element index
*/
template <class type>
void Vector<type>::erase(int it)
{
	if (it <= elements)
		elements--;
	size--;

	type * newVector = new type[size];

	for (int i = 0, j = 0; i < elements; ++j)
	{
		if (j == it)
			continue;
		else
			newVector[i++] = vector[j];
	}
	delete[] vector;
	vector = newVector;
}

#endif //	Vector_HPP
