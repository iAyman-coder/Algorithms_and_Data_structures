#include <stddef.h>

int *bubble_sort(int arr[], size_t len) {
    int end_index = len - 1;

    while (1) {
        for (int i = 0; i < end_index; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }

        end_index--;

        if (end_index == 0) {
            break;
        }
    }

    if (arr[0] > arr[1]) {
        int temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }


    return arr;
}