#include "../algorithms/my_algorithms.h"
#include "custom_tests.h"

int main(void) {
    int arr1[8] = {42, 12, 89, 7, 23, 54, 91, 31};
    test_result(linear_search(arr1, 8, 23), 4, "Random test");

    int arr2[9] = {65, 8, 19, 74, 3, 99, 41, 12, 57};
    test_result(linear_search(arr2, 9, 65), 0, "Best case: Element at the beginning");
    
    int arr3[9] = {11, 83, 4, 38, 92, 67, 15, 50, 76};
    test_result(linear_search(arr3, 9, 76), 8, "Worst case: Element at the end");
    
    int arr4[5] = {80, 29, 57, 26, 90};
    test_result(linear_search(arr4, 5, 13), -1, "Worst case: Element doesn't exist");

    int arr5[1] = {};   // Array initialize with 1 because you can't initialize an array with a zero
    test_result(linear_search(arr5, 0, 1), -1, "Empty array");

    int arr6[1] = {42};
    test_result(linear_search(arr6, 1, 42), 0, "Single-element match");

    int arr7[1] = {7};
    test_result(linear_search(arr7, 1, 14), -1, "Single-element mismatch");

    int arr8[5] = {5, 2, 7, 5, 9};
    test_result(linear_search(arr8, 5, 5), 0, "Array with duplicates");

    int arr9[4] = {-15, 0, 3, -2};
    test_result(linear_search(arr9, 4, -2), 3, "Array with negative numbers and zeros");

    return 0;
}