#include "../algorithms/my_algorithms.h"
#include "custom_tests.h"

int main(void) {
    int arr1[10] = {12, 27, 34, 49, 53, 61, 78, 82, 95, 99};
    test_result(interpolation_search(arr1, 10, 95), 8, "Random test 1");
    
    int arr2[8] = {3, 14, 29, 35, 42, 58, 66, 74};
    test_result(interpolation_search(arr2, 8, 14), 1, "Random test 2");
    
    int arr3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    test_result(interpolation_search(arr3, 10, 7), 6, "Best case");
    
    int arr4[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    test_result(interpolation_search(arr4, 10, 256), 8, "Worst case: Exponentially increasing elements");

    int arr5[5] = {12, 45, 67, 89, 102};
    test_result(interpolation_search(arr5, 5, 200), -1, "Element doesn't exist");

    int arr6[1] = {};   // Array initialize with 1 because you can't initialize an array with a zero.
    test_result(interpolation_search(arr6, 0, 1), -1, "Empty array");

    int arr7[5] = {10, 20, 30, 40, 50};
    test_result(interpolation_search(arr7, 5, 5), -1, "Element out of bound: Small");

    int arr8[4] = {30, 35, 40, 45};
    test_result(interpolation_search(arr8, 4, 50), -1, "Element out of bound: Large");

    int arr9[1] = {42};
    test_result(interpolation_search(arr9, 1, 42), 0, "Single-element match");

    int arr10[1] = {7};
    test_result(interpolation_search(arr10, 1, 14), -1, "Single-element mismatch");

    int arr11[5] = {7, 7, 7, 7, 7};
    test_result(interpolation_search(arr11, 5, 7), 0, "Array with identical elements");

    int arr12[6] = {1, 2, 3, 4, 5, 1000};
    test_result(interpolation_search(arr12, 6, 4), 3, "Array with extreme outlier");

    int arr13[10] = {1, 2, 2, 3, 4, 4, 4 ,5, 6, 6};
    test_result(interpolation_search(arr13, 10, 2), 1, "Array with duplicates");

    int arr14[5] = {-15, -2, 0, 3, 14};
    test_result(interpolation_search(arr14, 5, -2), 1, "Array with negative numbers and zeros");

    return 0;
}