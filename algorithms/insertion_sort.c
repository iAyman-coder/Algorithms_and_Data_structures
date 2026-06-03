#include <stddef.h>

int *insertion_sort(int arr[], size_t len) {
    if (len <= 1) {
        return arr;
    }

    for (int i = 1; i < len; i++) {
        int temp = arr[i];

        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        int new_pos = j + 1;

        if (new_pos == i) {
            continue;
        }
        else {
            arr[new_pos] = temp;
        }
    }

    return arr;
}