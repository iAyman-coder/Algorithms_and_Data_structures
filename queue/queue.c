#include <stdlib.h>
#include <stdio.h>

typedef struct qNode {
    char data;
    struct qNode *next;
}qNode;


qNode **make_queue (char arr[], size_t len, qNode *head_and_tail_ptrs[2]) {
    if (len <= 0) {
        fprintf(stderr, "\033[0;31mError: Can't form a queue. arr must contain one element at least.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    qNode *head = NULL;
    qNode *tail = NULL;

    qNode *prev_node = NULL;

    for (int i = 0; i < len; i++) {
        qNode *current_node = malloc(sizeof(qNode));
        current_node->data = arr[i];
        current_node->next = NULL;

        if (i == 0) {
            head = current_node;
        }
        else if (i == len - 1) {
            tail = current_node;
        }

        if (prev_node != NULL) {
            prev_node->next = current_node;
        }

        prev_node = current_node;
    }

    head_and_tail_ptrs[0] = head;
    head_and_tail_ptrs[1] = tail;


    return head_and_tail_ptrs;
}