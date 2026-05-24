#include "../algorithms/my_algorithms.h"
#include "custom_tests.c"

int main(void) {
    int arr1[8] = {42, 12, 89, 7, 23, 54, 91, 31};
    test_result(linear_search(arr1, 8, 23), 4, "Random test");

    int arr2[9] = {65, 8, 19, 74, 3, 99, 41, 12, 57};
    test_result(linear_search(arr2, 9, 65), 0, "Best case");
    
    int arr3[9] = {11, 83, 4, 38, 92, 67, 15, 50, 76};
    test_result(linear_search(arr3, 9, 76), 8, "Worst case 1");
    
    int arr4[5] = {80, 29, 57, 26, 90};
    test_result(linear_search(arr4, 5, 13), -1, "Worst case 2");

    int arr5[1] = {};
    test_result(linear_search(arr5, 0, 1), -1, "Worst case 3");

    return 0;
}