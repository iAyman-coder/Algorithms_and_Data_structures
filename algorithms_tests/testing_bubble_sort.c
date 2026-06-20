#include "../algorithms/my_algorithms.h"
#include "testing_tools.h"

int main(void) {
    int arr1[10] = {42, 7, 89, 23, 11, 56, 94, 2, 67, 35};
    int correct1[10] = {2, 7, 11, 23, 35, 42, 56, 67, 89, 94};
    test_array(bubble_sort(arr1, 10), correct1, 10, "Random test 1");

    int arr2[12] = {115, 8, 47, 92, 13, 74, 3, 61, 29, 83, 50, 101};
    int correct2[12] = {3, 8, 13, 29, 47, 50, 61, 74, 83, 92, 101, 115};
    test_array(bubble_sort(arr2, 12), correct2, 12, "Random test 2");

    int arr3[8] = {88, 69, 62, 53, 39, 26, 23, 11};
    int correct3[8] = {11, 23, 26, 39, 53, 62, 69, 88};
    test_array(bubble_sort(arr3, 8), correct3, 8, "Reversed array");

    int arr4[12] = {24, 7, 42, 15, 7, 89, 42, 15, 3, 24, 91, 7};
    int correct4[12] = {3, 7, 7, 7, 15, 15, 24, 24, 42, 42, 89, 91};
    test_array(bubble_sort(arr4, 12), correct4, 12, "Array with duplicates");

    int arr5[6] = {1, 2, 3, 4, 5, 6};
    int correct5[6] = {1, 2, 3, 4, 5, 6};
    test_array(bubble_sort(arr5, 6), correct5, 6, "Sorted array");

    int arr6[1] = {};   // Array initialized with 1 because you can't initialize an array with a zero.
    int correct6[1] = {};
    test_array(bubble_sort(arr6, 0), correct6, 0, "Empty array");

    int arr7[1] = {9};
    int correct7[1] = {9};
    test_array(bubble_sort(arr7, 1), correct7, 1, "Array with single element");

    int arr8[2] = {20, 10};
    int correct8[2] = {10, 20};
    test_array(bubble_sort(arr8, 2), correct8, 2, "Array of size 2");

    int arr9[5] = {2, 3, 4, 5, 1};
    int correct9[5] = {1, 2, 3, 4, 5};
    test_array(bubble_sort(arr9, 5), correct9, 5, "Smallest element at the end");

    int arr10[5] = {-3, -1, -5, -2, -4};
    int correct10[5] = {-5, -4, -3, -2, -1};
    test_array(bubble_sort(arr10, 5), correct10, 5, "Array with negative numbers");

    int arr11[5] = {0, -10, 5, -2, 3};
    int correct11[5] = {-10, -2, 0, 3, 5};
    test_array(bubble_sort(arr11, 5), correct11, 5, "Array with positive and negative numbers");

    return 0;
}