#include <stddef.h>

int *selection_sort(int arr[], size_t len) {
    int i = 0;

    while (1) {
        if (i == len - 1) {
            break;
        }

        // The index of the minimum value for this iteration.
        int min_index = i;

        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index == i) {
            /*
                This conditional checks if the smallest element in this iteration
                is the element at index i itself. If so, it increments i without
                performing any unnecessary swapping. 
            */
            i++;
            continue;
        }

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

        i++;
    }

    
    return arr;
}