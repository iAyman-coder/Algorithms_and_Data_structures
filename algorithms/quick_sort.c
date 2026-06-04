#include <stddef.h>

void find_pivot(int arr[], int start_index, int middle_index, int end_index) {
    if (arr[start_index] <= arr[middle_index] && arr[start_index] <= arr[end_index]) {
        /*
            This conditional only swaps elements at the middle and end if
            the element at the middle is larger than the element at the end. 
        */
        if (arr[middle_index] > arr[end_index]) {
            int temp = arr[middle_index];
            arr[middle_index] = arr[end_index];
            arr[end_index] = temp;
        }
    }
    else if(arr[middle_index] <= arr[start_index] && arr[middle_index] <= arr[end_index]) {
        /*
            This conditional first swaps the element at the beginning with the
            element at the middle.
            Then, it swaps the element at the middle with the element at the end
            if the element at the middle is larger than the one at the end.
        */
        int temp = arr[start_index];
        arr[start_index] = arr[middle_index];
        arr[middle_index] = temp;

        if (arr[middle_index] > arr[end_index]) {
            temp = arr[middle_index];
            arr[middle_index] = arr[end_index];
            arr[end_index] = temp;
        }
    }
    else {
        /*
            This conditional first swaps the element at the beginning with the
            element at the end.
            Then, it swaps the element at the middle with the element at the end
            if the element at the middle is larger than the one at the end. 
        */
        int temp = arr[start_index];
        arr[start_index] = arr[end_index];
        arr[end_index] = temp;

        if (arr[middle_index] > arr[end_index]) {
            temp = arr[middle_index];
            arr[middle_index] = arr[end_index];
            arr[end_index] = temp;
        }
    }
}

int *quick_sort(int arr[], size_t len, int start_index, int end_index) {
    if (len <= 1) {
        // Immediate return for single-element or empty arrays.
        return arr;
    }

    int middle_index = start_index + (end_index - start_index) / 2;

    // Find the pivot and put it in the middle of the array.
    find_pivot(arr, start_index, middle_index, end_index); 

    int temp;
    
    // Put the pivot at the end of the array.
    temp = arr[middle_index];
    arr[middle_index] = arr[end_index];
    arr[end_index] = temp;

    int i = start_index;
    int j = end_index - 1;
    int pivot = arr[end_index];
    while (1) {
        if (i > j) {
            /*  This conditional puts the pivot in its correct position.  */
            temp = arr[i];
            arr[i] = arr[end_index];
            arr[end_index] = temp;
            break;
        }
        else if(arr[i] > pivot) {
            if (arr[j] < pivot) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
            else {
                j--;
            }
        }
        else if(arr[i] <= pivot) {
            i++;
        }
    }

    /*  From here the index of the pivot is stored in the i variable.  */

    size_t left_half_len = i - start_index;
    quick_sort(arr, left_half_len, start_index, i - 1);

    size_t right_half_len = end_index - i;
    quick_sort(arr, right_half_len, i + 1, end_index);

    return arr;
}