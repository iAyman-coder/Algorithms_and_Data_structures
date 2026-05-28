#include <stdlib.h>
#include <math.h>

int *merge(int arr[], int left_half[], int right_half[], size_t left_len, size_t right_len) {
    int i = 0, j = 0, k = 0;

    while (k < (left_len + right_len)) {
        if (i == left_len || j == right_len) {
            break;
        }

        if (left_half[i] < right_half[j]) {
            arr[k] = left_half[i];
            i++;
            k++;
        }
        else {
            arr[k] = right_half[j];
            j++;
            k++;
        }
    }

    if (i == left_len) {
        for (j; j < right_len; j++) {
            arr[k] = right_half[j];
            k++;
        }
    }
    else if (j == right_len) {
        for (i; i < left_len; i++) {
            arr[k] = left_half[i];
            k++;
        }
    }

    return arr;
}


int *merge_sort(int arr[], size_t len) {
    if (len == 1) {
        return arr;
    }

    int start_1 = 0;
    int end_1 = (len - 1) / 2;
    int start_2 = end_1 + 1;
    int end_2 = len - 1;

    size_t left_half_len = round(len / 2.0);
    int *left_half = calloc(left_half_len, sizeof(int));
    
    for (int i = start_1; i <= end_1; i++) {
        left_half[i] = arr[i];
    }

    size_t right_half_len = len - left_half_len;
    int *right_half = calloc(right_half_len, sizeof(int));

    for (int j = 0, k = start_2; k <= end_2; j++, k++) {
        right_half[j] = arr[k];
    }

    int *left_sorted = merge_sort(left_half, left_half_len);
    int *right_sorted = merge_sort(right_half, right_half_len);

    int *new_arr = merge(arr, left_sorted, right_sorted, left_half_len, right_half_len);
    free(left_sorted);
    free(right_sorted);

    return new_arr;
}