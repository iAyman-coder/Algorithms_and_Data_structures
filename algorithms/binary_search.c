#include <stddef.h>

int binary_search(int arr[], size_t len, int target) {
    int start_index = 0;
    int middle_index = (len - 1) / 2;
    int end_index = len - 1;

    // Early return if target is out of boundaries
    // This is valid because arrays passed to binary search are already sorted
    if (target < arr[start_index] || target > arr[end_index]) {
        return -1;
    }

    while (start_index < end_index) {
        if (middle_index == start_index || middle_index == end_index) {
            /*
                This conditional prevents the case where target is not in the array, but
                its value exists between the range of the two leftmost or rightmost elements.
                For example: in the array {6, 11, 16, 21, 26, 31}
                8 is not in the array but its value exists between 6 and 11
                27 is not in the array but its value exists between 26 and 31 
            */
            return (target == arr[middle_index]) ? middle_index : -1;
        }
        else if (target == arr[middle_index]) {
            return middle_index;
        }
        else if (target < arr[middle_index]) {
            end_index = middle_index;
        }
        else if (target > arr[middle_index]) {
            start_index = middle_index;
        }

        middle_index = (start_index + end_index) / 2;
    }

    return -1;
}