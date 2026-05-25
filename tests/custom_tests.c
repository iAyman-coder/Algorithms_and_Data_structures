#include <stdio.h>

void test_result(int actual_result, int expected_result, char *test_name) {
    if (actual_result != expected_result) {
        printf("%s \033[0;31m[FAILED]\033[0;0m\n", test_name); 
        printf("Expected: %i | Got: %i\n", expected_result, actual_result);
        return;
    }

    printf("%s \033[0;32m[PASSED]\033[0;0m\n", test_name);
}


void test_array(int result_arr[], int expected_arr[], size_t len, char *test_name) {
    for (int i = 0; i < len; i++) {
        if (result_arr[i] != expected_arr[i]) {
            printf("%s \033[0;31m[FAILED]\033[0;0m\n", test_name);
            printf("At index: %i -> Expected: %i | Got: %i\n", i, expected_arr[i], result_arr[i]);
            return;
        }
    }

    printf("%s \033[0;32m[PASSED]\033[0;0m\n", test_name);
}