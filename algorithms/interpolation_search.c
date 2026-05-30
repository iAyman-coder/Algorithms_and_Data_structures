#include <stddef.h>

int calculate_interpolation_position(int target, int low, int high, int arr_low, int arr_high) {
    int numerator = (target - arr_low) * (high - low);
    int denominator = arr_high - arr_low;
    int frac = numerator / denominator;

    return low + frac;
}

int interpolation_search(int arr[], size_t len, int target) {
    int start_index = 0;
    int end_index = len - 1;

    while (start_index < end_index) {
        int pos = calculate_interpolation_position(target, start_index, end_index, arr[start_index], arr[end_index]);
        
        if (pos == start_index || pos == end_index) {
            return (target == arr[pos]) ? pos : -1;
        }

        if (target == arr[pos]) {
            return pos;
        }
        else if (target < arr[pos]) {
            end_index = pos - 1;
        }
        else if (target > arr[pos]) {
            start_index = pos + 1;
        }
    }

    return -1;
}