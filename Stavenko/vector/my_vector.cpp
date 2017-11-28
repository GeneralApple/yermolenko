#include <cstdlib>
#include <iostream>

using std::size_t;

/**
 * @brief 
 * 
 * Custom vector class.
 * 
 * @return template <class elem> class myVector
 */
template <class T>
class myVector {
private:
    size_t size;        // size of array in array
    size_t max_size;    // maximum current max_size
    T* array;        // pointer to actual items in memory

    void resize();
public:
    myVector();
    ~myVector();

    std::size_t get_size();
    void push_back(T &item);
    T& operator[] (size_t index);
};

/**
 * @brief 
 * 
 * Constructor of vector.
 * 
 * @return template <class T>
 */
template <class T> 
myVector<T>::myVector() {
    size = 0;
    max_size = 32;

    array = new T[max_size];
}

template <class T> 
myVector<T>::~myVector() {
    if (array) {
        delete[] array;
    }
}

/**
 * @brief 
 * 
 * Return current size of vector.
 * 
 * @return template <class T> size_t
 */
template <class T>
size_t myVector<T>::get_size(){
    return size;
}

/**
 * @brief 
 * 
 * Increase size of internal array in 2 times.
 * 
 * @return nothing
 */
template <class T>
void myVector<T>::resize(){
    max_size *= 2;
    T *new_array = new T[max_size];

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
template <class T>
void myVector<T>::push_back(T &item){
    if (size >= max_size) {
        resize();
    };

    array[size] = item;
    ++size;
}

/**
 * @brief 
 * 
 * Return the element that corresponds to index. 
 * If index out of bound, print to console. Throw not implementued.
 * 
 * @param index of element.
 * 
 * @return element
 */
template <class T>
T& myVector<T>::operator[] (size_t index) {
    if (index < size - 1) {
        return array[index];
    } else {
        std::cout << "Index out of range.\n";
        // TODO: add exception throw
    }
}

int main(int argc, char const *argv[])
{
    myVector<int> arr;

    for(int i=0;i<40;i++){
        arr.push_back(i);
    };

    std::cout << "number of elements: " << arr.get_size() << std::endl;

    std::cout << arr[15] << std::endl;
    std::cout << arr[10] << std::endl;
    std::cout << arr[38] << std::endl;

    std::cout << arr[90] << std::endl;

    return 0;
}