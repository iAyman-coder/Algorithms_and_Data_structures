#include "../algorithms/my_algorithms.h"
#include "custom_tests.c"

int main(void) {
    int arr1[10] = {42, 7, 89, 23, 11, 56, 94, 2, 67, 35};
    int correct1[10] = {2, 7, 11, 23, 35, 42, 56, 67, 89, 94};
    test_array(selection_sort(arr1, 10), correct1, 10, "Random test 1");

    int arr2[12] = {115, 8, 47, 92, 13, 74, 3, 61, 29, 83, 50, 101};
    int correct2[12] = {3, 8, 13, 29, 47, 50, 61, 74, 83, 92, 101, 115};
    test_array(selection_sort(arr2, 12), correct2, 12, "Random test 2");

    int arr3[8] = {88, 69, 62, 53, 39, 26, 23, 11};
    int correct3[8] = {11, 23, 26, 39, 53, 62, 69, 88};
    test_array(selection_sort(arr3, 8), correct3, 8, "Reversed array");

    int arr4[12] = {24, 7, 42, 15, 7, 89, 42, 15, 3, 24, 91, 7};
    int correct4[12] = {3, 7, 7, 7, 15, 15, 24, 24, 42, 42, 89, 91};
    test_array(selection_sort(arr4, 12), correct4, 12, "Array with duplicates");

    int arr5[6] = {1, 2, 3, 4, 5, 6};
    int correct5[6] = {1, 2, 3, 4, 5, 6};
    test_array(selection_sort(arr5, 6), correct5, 6, "Sorted array");

    return 0;
}