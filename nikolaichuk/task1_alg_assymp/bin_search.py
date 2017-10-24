import numpy as np
from time import clock
import matplotlib.pyplot as plt

def binary_search(alist, item):
    """
    Return index of item in sorted list. If item not in list,
    return -1.
    """

    first, last = 0, len(alist) - 1  # 2

    while first <= last:  # log(N) times
        midpoint = (first + last) // 2  # 1

        cur_item = alist[midpoint]
        if cur_item == item:
            return midpoint
        else:
            if item < cur_item:
                last = midpoint - 1
            else:
                first = midpoint + 1

    # if not found
    return -1


def get_exec_time(func, arr_size):
    test_arr = np.arange(arr_size)
    
    first_time = clock()

    for _ in range(10):
        binary_search(test_arr, 7)
        binary_search(test_arr, arr_size - 2)
        
    
    exec_time = (clock() - first_time) / 20

    return exec_time


def main():
    all_sizes = [8 ** i for i in range(1, 10)]

    ys = [get_exec_time(binary_search, arr_size) for arr_size in all_sizes]

    print(ys)

    plt.plot(all_sizes, ys, 'b*')
    plt.semilogx()
    plt.show()


if __name__ == '__main__':
    main()

