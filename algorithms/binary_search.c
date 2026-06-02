#include <stddef.h>

int binary_search(int arr[], size_t len, int target) {
    int start_index = 0;
    int end_index = len - 1;

    // Early return if target is out of boundaries
    // This is valid because arrays passed to binary search are already sorted
    if (target < arr[start_index] || target > arr[end_index]) {
        return -1;
    }

    while (start_index <= end_index) {
        int middle_index = start_index + (end_index - start_index) / 2;

        if (target == arr[middle_index]) {
            return middle_index;
        }
        else if (target < arr[middle_index]) {
            end_index = middle_index - 1;
        }
        else if (target > arr[middle_index]) {
            start_index = middle_index + 1;
        }
    }

    return -1;
}