#include <cstdlib>
#include <iostream>

using std::size_t;

/**
 * @brief 
 * 
 * Custom vector class.
 * 
 * @return template <class elem> class MyDynamicArray
 */
template <class elem> 
class MyDynamicArray {
private:
    size_t size;        // size of array in array
    size_t capacity;    // maximum current capacity
    elem* array;           // pointer to actual items in memory
    
    const static int initial_size = 32;
    const static int size_multiply = 2;

    void resize();
public:
    MyDynamicArray();
    ~MyDynamicArray();

    std::size_t get_size();
    void push_back(elem &item);
    elem& operator[] (size_t index);
};

/**
 * @brief 
 * 
 * Constructor of vector.
 * 
 * @return template <class elem>
 */
template <class elem> 
MyDynamicArray<elem>::MyDynamicArray() {
    size = 0;
    capacity = initial_size;

    array = new elem[capacity];
}

template <class elem> 
MyDynamicArray<elem>::~MyDynamicArray() {
    if (array) {
        delete[] array;
    }
}

/**
 * @brief 
 * 
 * Return current size of vector.
 * 
 * @return template <class elem> size_t
 */
template <class elem>
size_t MyDynamicArray<elem>::get_size(){
    return size;
}

/**
 * @brief 
 * 
 * Increase size of internal array by size_multiply factor (2 by default).
 * 
 * @return nothing
 */
template <class elem>
void MyDynamicArray<elem>::resize(){
    capacity *= size_multiply;
    elem *new_array = new elem[capacity];

    for (size_t i=0;i<size;i++){
        new_array[i] = array[i];
    }

    delete[] array;
    array = new_array;
}

/**
 * @brief 
 * 
 * Add element to the end of the array. If not enough space, call resize method.
 * 
 * @param item
 * 
 * @return nothing
 */
template <class elem>
void MyDynamicArray<elem>::push_back(elem &item){
    if (size >= capacity) {
        resize();
    };

    array[size] = item;
    ++size;
}

/**
 * @brief 
 * 
 * Return the element that corresponds to index.
 * 
 * @param index of element.
 * 
 * @return element
 */
template <class elem>
elem& MyDynamicArray<elem>::operator[] (size_t index) {
    if (index < size - 1) {
        return array[index];
    } else {
        std::cout << "Index out of range.\n";
        // TODO: add exception throw
    }
}