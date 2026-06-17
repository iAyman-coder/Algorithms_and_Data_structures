#include <stdlib.h>
#include <stdio.h>

typedef struct qNode {
    char data;
    struct qNode *next;
}qNode;


qNode **make_queue (char arr[], size_t len, qNode *front_and_rear_ptrs[2]) {
    if (len <= 0) {
        fprintf(stderr, "\033[0;31mError: Can't form a queue. arr must contain one element at least.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    qNode *front = NULL;
    qNode *rear = NULL;

    qNode *prev_node = NULL;

    for (int i = 0; i < len; i++) {
        qNode *current_node = malloc(sizeof(qNode));
        current_node->data = arr[i];
        current_node->next = NULL;

        if (i == 0) {
            front = current_node;
        }
        else if (i == len - 1) {
            rear = current_node;
        }

        if (prev_node != NULL) {
            prev_node->next = current_node;
        }

        prev_node = current_node;
    }

    front_and_rear_ptrs[0] = front;
    front_and_rear_ptrs[1] = rear;


    return front_and_rear_ptrs;
}

qNode *enqueue(qNode *rear, char data) {
    if (rear == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't enqueue a new node. rear can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    qNode *new_node = malloc(sizeof(qNode));
    new_node->data = data;
    new_node->next = NULL;

    rear->next = new_node;

    return new_node;
}