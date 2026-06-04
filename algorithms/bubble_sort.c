#include <stddef.h>

int *bubble_sort(int arr[], size_t len) {
    if (len <= 1) {
        // Immediate return for single-element or empty arrays.
        return arr;
    }

    int end_index = len - 1;

    while (end_index > 0) {
        /*
            This for loop points at two elements in each iteration, and
            is responsible for swapping adjacent elements if the left
            element is larger than the right element.
        */
        for (int i = 0; i < end_index; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }

        end_index--;
    }

    /*
        After breaking out of the while loop, we check if the two leftmost
        elements are in their correct positions. If not, we swap them.
    */
    if (arr[0] > arr[1]) {
        int temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }


    return arr;
}