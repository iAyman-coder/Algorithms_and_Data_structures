#include <stddef.h>

int *insertion_sort(int arr[], size_t len) {
    if (len <= 1) {
        // Immediate return for single-element or empty arrays.
        return arr;
    }

    for (int i = 1; i < len; i++) {
        int temp = arr[i];

        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            /*
                This loop keeps pushing elements to the right until either an 
                element is smaller than temp or we reached the start of the array. 
            */
            arr[j + 1] = arr[j];
            j--;
        }

        int new_pos = j + 1;

        if (new_pos == i) {
            // If element is in its correct position we don't perform any swapping.
            continue;
        }
        else {
            arr[new_pos] = temp;
        }
    }

    return arr;
}