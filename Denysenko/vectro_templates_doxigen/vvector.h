#pragma once

/*!
* Implementation of std::vector
* @author Vadym Denysenko
* @version 1.0.0
*/


/*!
* @brief Custom class "vvector"
*
* Class "vvector" consist basic methods such as add,
																								size,
																								pull_last and
																								get_index_elem.
*
* @return class vvector
*/

template <class type>
class vector {
private:
	int sizev = 10; /*! initial size of vvector */
	int counter; /*! number of elements */
	const int mult = 3; /*! length multiplier */
	type* elementp; /*! pointer to vvector elements  */
	void resize();

public:
	/*!
	* Initialization constructor.
	*/
	vvector();

	/*!
	* Initialization destructor.
	*/
	~vvector();

	/*!
	* Initialization of method add().
	* @param item is an element.
	*/
	void add(type item);

	/*!
	* Initialization of method pull_last().
	*/
	type pull_last();

	/*!
	* Initialization of method size().
	*/
	int size();

	/*!
	* Initialization of method get_index_elem().
	*/
	type get_index_elem(int index);
};

/*!
* @brief Constructor of vvector.
*
* Creates vvector with initial size.
*/
template <class type>
vvector<type>::vvector() {
	elementp = new type[sizev];
	counter = 0;
};

/*!
* @brief Destructor of vvector.
*/
template <class type>
vvector<type>::~vvector() {
	delete[] elementp;
};

/*!
* @brief Method add();
*
* Add element in the end of vvector. Calls resize() method, if counter out of
																													 range elementp array.
*/
template <class type>
void vvector<type>::add(type item) {
	if (counter >= sizev)
		resize();

	elementp[counter] = item;
	counter += 1;
};

/*!
* @brief Method remove_last().
*
* Returns last element of vvector and remove this element.
* @return element
*/
template <class type>
type vvector<type>::pull_last() {
	type lastElem = elementp[counter - 1];
	--counter;
	return lastElem;
};

/*!
* @brief Method get_index_elem().
*
* Returns last element of vvector at this index.
* @return element or NULL if index out of range
*/
template <class type>
type vvector<type>::get_index_elem(int index) {
	if (index > counter - 1 || index < 0) {
		std::cout << "Invalid index: out of range.\n";
		return NULL;
	}

	return elementp[index];
};

/*!
* @brief Method size().
*
* Returns current number of elements in the vvector.
*
* @return counter.
*/
template <class type>
int vvector<type>::size() {
	return counter;
};

/*!
* @brief Method resize().
*
* Increases size of current internal array by mult factor (default value is 3).
*/
template <class type>
void vvector<type>::resize() {
	sizev *= mult;
	type* temp = new type[sizev];

	for (int i = 0; i < counter; i++) {
		temp[i] = elementp[i];
	}
	delete[] elementp;
	elementp = temp;
}
