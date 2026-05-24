#include "../algorithms/my_algorithms.h"
#include "custom_tests.c"

int main(void) {
    int arr1[10] = {12, 27, 34, 49, 53, 61, 78, 82, 95, 99};
    test_result(binary_search(arr1, 10, 61), 5, "Random test 2");
    
    int arr2[8] = {3, 14, 29, 35, 42, 58, 66, 74};
    test_result(binary_search(arr2, 8, 14), 1, "Random test 2");
    
    int arr3[10] = {5, 18, 22, 41, 57, 63, 71, 80, 89, 94};
    test_result(binary_search(arr3, 10, 57), 4, "Best case");
    
    int arr4[5] = {6, 19, 22, 25, 33};
    test_result(binary_search(arr4, 5, 13), -1, "Worst case lower bound");

    int arr5[5] = {12, 45, 67, 89, 102};
    test_result(binary_search(arr5, 5, 200), -1, "Worst case upper bound");

    int arr6[1] = {};
    test_result(binary_search(arr6, 0, 1), -1, "Worst case");

    return 0;
}