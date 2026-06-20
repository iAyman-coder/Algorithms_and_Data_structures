#include "../algorithms/my_algorithms.h"
#include "testing_tools.h"

int main(void) {
    int arr1[10] = {42, 7, 89, 23, 11, 56, 94, 2, 67, 35};
    int correct1[10] = {2, 7, 11, 23, 35, 42, 56, 67, 89, 94};
    test_array(merge_sort(arr1, 10), correct1, 10, "Random test 1");

    int arr2[12] = {115, 8, 47, 92, 13, 74, 3, 61, 29, 83, 50, 101};
    int correct2[12] = {3, 8, 13, 29, 47, 50, 61, 74, 83, 92, 101, 115};
    test_array(merge_sort(arr2, 12), correct2, 12, "Random test 2");

    int arr3[8] = {88, 69, 62, 53, 39, 26, 23, 11};
    int correct3[8] = {11, 23, 26, 39, 53, 62, 69, 88};
    test_array(merge_sort(arr3, 8), correct3, 8, "Reversed array");

    int arr4[12] = {24, 7, 42, 15, 7, 89, 42, 15, 3, 24, 91, 7};
    int correct4[12] = {3, 7, 7, 7, 15, 15, 24, 24, 42, 42, 89, 91};
    test_array(merge_sort(arr4, 12), correct4, 12, "Array with duplicates");

    int arr5[6] = {1, 2, 3, 4, 5, 6};
    int correct5[6] = {1, 2, 3, 4, 5, 6};
    test_array(merge_sort(arr5, 6), correct5, 6, "Sorted array");

    int arr6[9] = {42, 7, 89, 12, 55, 23, 91, 3, 66};
    int correct6[9] = {3, 7, 12, 23, 42, 55, 66, 89, 91};
    test_array(merge_sort(arr6, 9), correct6, 9, "Array with odd size");


    int arr7[1] = {};   // Array initialized with 1 because you can't initialize an array with a zero.
    int correct7[1] = {};
    test_array(merge_sort(arr7, 0), correct7, 0, "Empty array");

    int arr8[1] = {8};
    int correct8[1] = {8};
    test_array(merge_sort(arr8, 1), correct8, 1, "Array with single element");

    int arr9[2] = {2, 1};
    int correct9[2] = {1, 2};
    test_array(merge_sort(arr9, 2), correct9, 2, "Array of size 2");

    int arr10[4] = {2, 1, 9, 8};
    int correct10[4] = {1, 2, 8, 9};
    test_array(merge_sort(arr10, 4), correct10, 4, "Left half elements are all smaller than right half elements");

    int arr11[4] = {9, 8, 2, 1};
    int correct11[4] = {1, 2, 8, 9};
    test_array(merge_sort(arr11, 4), correct11, 4, "Right half elements are all smaller than left half elements");
    
    int arr12[5] = {-3, -1, -5, -2, -4};
    int correct12[5] = {-5, -4, -3, -2, -1};
    test_array(merge_sort(arr12, 5), correct12, 5, "Array with negative numbers");

    int arr13[5] = {0, -10, 5, -2, 3};
    int correct13[5] = {-10, -2, 0, 3, 5};
    test_array(merge_sort(arr13, 5), correct13, 5, "Array with positive and negative numbers");

    return 0;
}