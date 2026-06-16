#include <stdio.h>
#include "singly_linked_list.h"

void test_result(int actual_result, int expected_result, char *test_name) {
    if (actual_result != expected_result) {
        printf("%s \033[0;31m[FAILED]\033[0;0m\n", test_name); 
        printf("Expected: %i | Got: %i\n", expected_result, actual_result);
        return;
    }

    printf("%s \033[0;32m[PASSED]\033[0;0m\n", test_name);
}

void test_linked_list(Node *head, char expected_result[], size_t len, char *test_name) {
    Node *current_node = head;

    for (int i = 0; i < len; i++) {
        char expected = expected_result[i];

        if (current_node == NULL) {
            printf("%s \033[0;31m[FAILED]\033[0;0m\n", test_name);
            printf("At position: %i -> Expected: %c | Got: %p\n", i, expected, current_node);
            return;
        }

        char result = current_node->data;

        if (result != expected) {
            printf("%s \033[0;31m[FAILED]\033[0;0m\n", test_name);
            printf("At position: %i -> Expected: %c | Got: %c\n", i, expected, result);
            return;
        }

        current_node = current_node->next;
    }

    printf("%s \033[0;32m[PASSED]\033[0;0m\n", test_name);
}