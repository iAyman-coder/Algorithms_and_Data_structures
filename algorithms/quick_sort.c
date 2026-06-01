#include <stddef.h>

void find_pivot(int arr[], int start_index, int middle_index, int end_index) {
    if (arr[start_index] <= arr[middle_index] && arr[start_index] <= arr[end_index]) {
        if (arr[middle_index] > arr[end_index]) {
            int temp = arr[middle_index];
            arr[middle_index] = arr[end_index];
            arr[end_index] = temp;
        }
    }
    else if(arr[middle_index] <= arr[start_index] && arr[middle_index] <= arr[end_index]) {
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
        return arr;
    }

    int middle_index = (start_index + end_index) / 2;

    find_pivot(arr, start_index, middle_index, end_index); 

    int temp;
    
    temp = arr[middle_index];
    arr[middle_index] = arr[end_index];
    arr[end_index] = temp;

    int i = start_index;
    int j = end_index - 1;
    int pivot = arr[end_index];
    while (1) {
        if (i > j) {
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

    size_t left_half_len = i - start_index;
    quick_sort(arr, left_half_len, start_index, i - 1);

    size_t right_half_len = end_index - i;
    quick_sort(arr, right_half_len, i + 1, end_index);

    return arr;
}