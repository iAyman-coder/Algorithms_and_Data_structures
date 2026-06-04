#include "../algorithms/my_algorithms.h"
#include "custom_tests.h"

int main(void) {
    int arr1[10] = {12, 27, 34, 49, 53, 61, 78, 82, 95, 99};
    test_result(binary_search(arr1, 10, 78), 6, "Random test: right side");
    
    int arr2[7] = {3, 14, 29, 35, 42, 58, 66};
    test_result(binary_search(arr2, 7, 14), 1, "Random test: left side");
    
    int arr3[10] = {5, 18, 22, 41, 57, 63, 71, 80, 89, 94};
    test_result(binary_search(arr3, 10, 57), 4, "Best case: Even size");
    
    int arr4[5] = {6, 19, 22, 25, 33};
    test_result(binary_search(arr4, 5, 22), 2, "Best case: Odd size");

    int arr5[5] = {12, 45, 67, 89, 102};
    test_result(binary_search(arr5, 5, 35), -1, "Worst case: Element doesn't exist (lower bound)");

    int arr6[5] = {6, 19, 22, 25, 33};
    test_result(binary_search(arr6, 5, 30), -1, "Worst case: Element doesn't exist (upper bound)");

    int arr7[7] = {3, 8, 15, 22, 42, 55, 91};
    test_result(binary_search(arr7, 7, 3), 0, "First element");

    int arr8[7] = {10, 23, 32, 45, 52, 76, 88};
    test_result(binary_search(arr8, 7, 88), 6, "Last element");

    int arr9[1] = {};   // array initialize with 1 because you can't initialize an array with a zero
    test_result(binary_search(arr9, 0, 9), -1, "Empty array");

    int arr10[1] = {7};
    test_result(binary_search(arr10, 1, 7), 0, "Single-element match");

    int arr11[1] = {32};
    test_result(binary_search(arr11, 1, 4), -1, "Single-element mismatch");

    int arr12[4] = {1, 3, 5, 7};
    test_result(binary_search(arr12, 4, 4), -1, "Element doesn't exist");

    int arr13[6] = {2, 4, 4, 4, 7, 9};
    test_result(binary_search(arr13, 6, 4), 2, "Array with duplicates");


    return 0;
}