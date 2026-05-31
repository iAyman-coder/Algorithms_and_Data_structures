#include <stddef.h>
#include <stdlib.h>
#include <math.h>

int *merge_quick_sort(int arr[], int left_half[], int left_len, int right_half[], int right_len, int pivot) {
    int i = 0;

    for (int j = 0; j < left_len; j++, i++) {
        arr[i] = left_half[j];
    }

    arr[i] = pivot;
    i++;

    for (int k = 0; k < right_len; k++, i++) {
        arr[i] = right_half[k];
    }

    return arr;
}

int find_median_index(int arr[], int start_index, int middle_index, int end_index) {
    if (arr[start_index] <= arr[middle_index] && arr[start_index] <= arr[end_index]) {
        return start_index;
    }
    else if (arr[middle_index] <= arr[start_index] && arr[middle_index] <= arr[end_index]) {
        return middle_index;
    }
    else {
        return end_index;
    }
}

int *quick_sort(int arr[], size_t len) {
    if (len <= 1) {
        return arr;
    }

    int pivot = find_median_index(arr, 0, (len - 1) / 2, len - 1);

    int halfs_size = round(len / 2.0);
    int *left_half = calloc(halfs_size, sizeof(int));
    int *right_half = calloc(halfs_size, sizeof(int));

    int left_half_len = 0;
    int right_half_len = 0;

    for (int i = 0, j = 0, k = 0; i < len; i++) {
        if (arr[i] <= arr[pivot] && i != pivot) {
            left_half[j] = arr[i];
            left_half_len++;
            j++;
        }
        else if (arr[i] > arr[pivot]) {
            right_half[k] = arr[i];
            right_half_len++;
            k++;
        }
    }

    int *sorted_left = quick_sort(left_half, left_half_len);
    int *sorted_right = quick_sort(right_half, right_half_len);

    int *new_arr = merge_quick_sort(arr, sorted_left, left_half_len, sorted_right, right_half_len, arr[pivot]);
    free(sorted_left);
    free(sorted_right);

    return new_arr;
}