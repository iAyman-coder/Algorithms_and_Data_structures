#include <stdio.h>
#include <stddef.h>
#include "testing_tools.h"
#include "stack.h"

int main(void) {
    char arr[5] = {'s', 't', 'a', 'c', 'k'};

    stNode *top = make_stack(arr, 5);

    char correct1[5] = {'s', 't', 'a', 'c', 'k'};
    test_stack(top, correct1, 5, "Forming initial stack");

    size_t stack_len = len_stack(top);
    test_result(stack_len, 5, "Length: 5 (initial)");

    printf("\n");
    printf("==========Initial Stack==========\n");
    peek(top);
    printf("##########################################\n");
    print_stack(top);
    printf("==========================================\n");
    printf("\n");

    top = push(top, 'X');

    char correct2[6] = {'X', 's', 't', 'a', 'c', 'k'};
    test_stack(top, correct2, 6, "Pushing 'X'");

    stack_len = len_stack(top);
    test_result(stack_len, 6, "Length: 6 (Pushing)");

    top = push(top, 'Y');

    char correct3[7] = {'Y', 'X', 's', 't', 'a', 'c', 'k'};
    test_stack(top, correct3, 7, "Pushing 'Y'");

    stack_len = len_stack(top);
    test_result(stack_len, 7, "Length: 7 (Pushing)");

    top = push(top, 'Z');

    char correct4[8] = {'Z', 'Y', 'X', 's', 't', 'a', 'c', 'k'};
    test_stack(top, correct4, 8, "Pushing 'Z'");

    stack_len = len_stack(top);
    test_result(stack_len, 8, "Length: 8 (Pushing)");

    printf("\n");
    printf("==========Modified Stack==========\n");
    peek(top);
    printf("##########################################\n");
    print_stack(top);
    printf("==========================================\n");
    printf("\n");

    top = pop(top);

    char correct5[7] = {'Y', 'X', 's', 't', 'a', 'c', 'k'};
    test_stack(top, correct5, 7, "Poping 'Z'");

    stack_len = len_stack(top);
    test_result(stack_len, 7, "Length: 7 (Poping)");

    top = pop(top);

    char correct6[6] = {'X', 's', 't', 'a', 'c', 'k'};
    test_stack(top, correct6, 6, "Poping 'Y'");

    stack_len = len_stack(top);
    test_result(stack_len, 6, "Length: 6 (Poping)");

    top = pop(top);

    char correct7[5] = {'s', 't', 'a', 'c', 'k'};
    test_stack(top, correct7, 5, "Poping 'X'");

    stack_len = len_stack(top);
    test_result(stack_len, 5, "Length: 5 (Poping)");

    printf("\n");
    printf("==========Stack After Deletion==========\n");
    peek(top);
    printf("##########################################\n");
    print_stack(top);
    printf("==========================================\n");
    printf("\n");

    top = delete_stack(top);

    if (top == NULL) {
        printf("\033[0;32m[stack was deleted successfully]\033[0;0m\n");
    }
    else {
        printf("\033[0;31m[stack was not deleted]\033[0;0m\n");
    }
}