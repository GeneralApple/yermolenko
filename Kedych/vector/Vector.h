#pragma once

/*!
* Implementation of std::vector
* @author Vadym Kedych
* @version 0.0.1
*/


/*!
* @brief Custom class "Vector"
*
* Class "Vector" consist basic methods such as addElement, getLen, removeLastElement and getElementAtIndex.
*
* @return class Vector
*/

template <class type>
class Vector {
private:
	int size = 10; /*! initial size of vector */
	int elements_counter; /*! number of elements */
	const int mult = 3; /*! length multiplier */ 
	type* elements; /*! pointer to vector elements  */
	void resize();

public:
	/*!
	* Initialization constructor.
	*/
	Vector();

	/*!
	* Initialization destructor.
	*/
	~Vector();

	/*!
	* Initialization of method addElement().
	* @param item is an element.
	*/
	void addElement(type item);

	/*!
	* Initialization of method removeLastElement().
	*/
	type removeLastElement();

	/*!
	* Initialization of method getLen().
	*/
	int getLen();

	/*!
	* Initialization of method getElementAtIndex().
	*/
	type getElementAtIndex(int index);
};

/*!
* @brief Constructor of vector.
*
* Creates vector with initial size.
*/
template <class type>
Vector<type>::Vector() {
	elements = new type[size];
	elements_counter = 0;
};

/*!
* @brief Destructor of vector.
*/
template <class type>
Vector<type>::~Vector() {
	delete[] elements;
};

/*!
* @brief Method addElement();
*
* Adds element in the end of vector. Calls resize() method, if elements_counter out of range elements array.
*/
template <class type>
void Vector<type>::addElement(type item) {
	if (elements_counter >= size)
		resize();

	elements[elements_counter] = item;
	elements_counter += 1;
};

/*!
* @brief Method removeLastElement().
*
* Returns last element of vector and remove this element.
* @return element
*/
template <class type>
type Vector<type>::removeLastElement() {
	type lastElem = elements[elements_counter - 1];
	elements_counter -= 1;
	return lastElem;
};

/*!
* @brief Method getElementAtIndex().
*
* Returns last element of vector at this index.
* @return element or NULL if index out of range
*/
template <class type>
type Vector<type>::getElementAtIndex(int index) {
	if (index > elements_counter - 1 || index < 0) {
		std::cout << "Invalid index: out of range.\n";
		return NULL;
	}

	return elements[index];
};

/*!
* @brief Method getLen().
*
* Returns current number of elements in the vector.
*
* @return elements_counter.
*/
template <class type>
int Vector<type>::getLen() {
	return elements_counter;
};

/*!
* @brief Method resize().
*
* Increases size of current internal array by mult factor (default value is 3).
*/
template <class type>
void Vector<type>::resize() {
	size *= mult;
	type* temp = new type[size];
	
	for (int i = 0; i < elements_counter; i++) {
		temp[i] = elements[i];
	}
	delete[] elements;
	elements = temp;
}