/*!
 * Implementation of std::vector
 * @author Mykhailo Nehelia
 * @version 0.0.1
 */

#ifndef vector_h
#define vector_h

/*!
 * @brief Custom class "Vector"
 *
 * Class "Vector" consist basic methods: push, pop, getLength and getElementByIndex.
 *
 * @return class Vector
 */

template <class type>
class Vector {
    private:
        int length = 1; // number of elements
        type* elements; // pointer to elements  
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
     * Initialization of method push().
     * @param item is an element.
     */
    void push(type item);
    
    /*!
     * Initialization of method pop().
     */
    void pop();
    
    /*!
     * Initialization of method getLength().
     */
    int getLength();
    
    /*!
     * Initialization of method getElementByIndex().
     */
    type getElementByIndex(int index);
};

/*!
 * @brief Constructor of vector.
 */
template <class type>
Vector<type>::Vector() {
    elements = new type[0];
    length = 0;
};
/*!
 * @brief Destructor of vector.
 */
template <class type>
Vector<type>::~Vector() {
    delete[] elements;
    length = 0;
};



/*!
 * @brief Method push();
 *
 * Adds element in the end of vector.
 */
template <class type>
void Vector<type>::push(type item) {
    elements[length] = item;
    length++;
};

/*!
 * @brief Method pop().
 *
 * Removes last element.
 */
template <class type>
void Vector<type>::pop() {
    delete elements[length - 1];
    length--;
};

/*!
 * @brief Method getElementByIndex().
 *
 * Returns an element of vector at this index.
 * @return element or false if index is out of range
 */
template <class type>
type Vector<type>::getElementByIndex(int index) {
    return (index < length && index > 0) ? elements[index] : false;
};

/*!
 * @brief Method getLength().
 *
 * Returns current number of elements in the vector.
 *
 * @return length.
 */
template <class type>
int Vector<type>::getLength() {
    return length;
};

#endif /* vector_h */
