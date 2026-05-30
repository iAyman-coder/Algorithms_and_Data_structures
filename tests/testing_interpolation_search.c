#include "../algorithms/my_algorithms.h"
#include "custom_tests.c"

int main(void) {
    int arr1[10] = {12, 27, 34, 49, 53, 61, 78, 82, 95, 99};
    test_result(interpolation_search(arr1, 10, 61), 5, "Random test 1");
    
    int arr2[8] = {3, 14, 29, 35, 42, 58, 66, 74};
    test_result(interpolation_search(arr2, 8, 14), 1, "Random test 2");
    
    int arr3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    test_result(interpolation_search(arr3, 10, 7), 6, "Best case");
    
    int arr4[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    test_result(interpolation_search(arr4, 10, 256), 8, "Worst case exponentially increasing elements");

    int arr5[5] = {12, 45, 67, 89, 102};
    test_result(interpolation_search(arr5, 5, 200), -1, "Element doesn't exist");

    int arr6[1] = {};   // array initialize with 1 because you can't initialize an array with a zero
    test_result(interpolation_search(arr6, 0, 1), -1, "Empty array");

    return 0;
}