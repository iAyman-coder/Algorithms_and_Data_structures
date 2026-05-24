#include <stddef.h>

int binary_search(int arr[], size_t len, int target) {
    int start_index = 0;
    int end_index = len - 1;
    int middle_element = end_index / 2;

    while (start_index < end_index) {
        if (middle_element == start_index || middle_element == end_index) {
            return (target == arr[middle_element]) ? middle_element : -1;
        }
        else if (target == arr[middle_element]) {
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