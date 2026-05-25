#include <stddef.h>

int *selection_sort(int arr[], size_t len) {
    int i = 0;

    while (1) {
        if (i == len - 1) {
            break;
        }

        int min = arr[i];
        int min_index = i;

        for (int j = i + 1; j < len; j++) {
            if (arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
        }

        if (min_index == i) {
            i++;
            continue;
        }

        int temp = arr[i];
        arr[i] = min;
        arr[min_index] = temp;

        i++;
    }

    
    return arr;
}