#include <iostream>
#include "my_dyn_array.h"

int main(int argc, char const *argv[])
{
    MyDynamicArray<int> arr;

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
