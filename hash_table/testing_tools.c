#include <stdio.h>
#include <stdbool.h>

void test_result(int actual_result, int expected_result, char *test_name) {
    if (actual_result != expected_result) {
        printf("%s \033[0;31m[FAILED]\033[0;0m\n", test_name); 
        printf("Expected: %i | Got: %i\n", expected_result, actual_result);
        return;
    }

    printf("%s \033[0;32m[PASSED]\033[0;0m\n", test_name);
}

void test_boolean(bool actual_result, char *test_name) {
    if (!actual_result) {
        printf("%s \033[0;31m[FAILED]\033[0;0m\n", test_name); 
        return;
    }

    printf("%s \033[0;32m[PASSED]\033[0;0m\n", test_name);
}