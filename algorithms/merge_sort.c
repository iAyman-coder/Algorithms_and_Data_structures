#include <stdlib.h>
#include <math.h>

int *merge(int arr[], int left_half[], int right_half[], size_t left_len, size_t right_len) {
    /*
        i: is the index for arr.
        j: is the index for left_half.
        k: is the index for right_hlf. 
    */
    int i = 0, j = 0, k = 0;

    while (i < (left_len + right_len)) {
        if (j == left_len || k == right_len) {
            break;
        }

        if (left_half[j] < right_half[k]) {
            arr[i] = left_half[j];
            i++;
            j++;
        }
        else {
            arr[i] = right_half[k];
            i++;
            k++;
        }
    }

    if (j == left_len) {
        /*
            This conditional works if all elements of left_half have been
            copied successfully into arr, and there are still elements in
            right_half that needs to be copied. 
        */
        for (k; k < right_len; k++, i++) {
            arr[i] = right_half[k];
        }
    }
    else if (k == right_len) {
        /*
            This conditional works if all elements of right_half have been
            copied successfully into arr, and there are still elements in 
            left_half that needs to be copied. 
        */
        for (j; j < left_len; j++, i++) {
            arr[i] = left_half[j];
        }
    }

    return arr;
}


int *merge_sort(int arr[], size_t len) {
    if (len <= 1) {
        // Immediate return for single-element or empty arrays.
        return arr;
    }

    // Start and end indexes of the left half of arr.
    int start_1 = 0;
    int end_1 = (len - 1) / 2;

    // Start and end indexes of the right half of arr.
    int start_2 = end_1 + 1;
    int end_2 = len - 1;

    size_t left_half_len = round(len / 2.0);
    int *left_half = calloc(left_half_len, sizeof(int));
    
    // Copy elements from the left half of arr into left_half array.
    for (int i = start_1; i <= end_1; i++) {
        left_half[i] = arr[i];
    }

    size_t right_half_len = len - left_half_len;
    int *right_half = calloc(right_half_len, sizeof(int));

    // Copy elements from the right half or arr into right_half array.
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