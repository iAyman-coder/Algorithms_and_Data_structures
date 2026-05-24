#include <stddef.h>

int binary_search(int arr[], size_t len, int target) {
    size_t start_index = 0;
    size_t end_index = len - 1;
    size_t middle_element = end_index / 2;

    while (start_index < end_index) {
        if (target == arr[middle_element]) {
            return middle_element;
        }
        else if (target < arr[middle_element]) {
            end_index = middle_element;
        }
        else if (target > arr[middle_element]) {
            start_index = middle_element;
        }

        middle_element = (start_index + end_index) / 2;
    }

    return -1;
}