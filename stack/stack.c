#include <stdlib.h>
#include <stdio.h>

typedef struct stNode {
    char data;
    struct stNode *next;
}stNode;


stNode *make_stack(char arr[], size_t len) {
    if (len <= 0) {
        fprintf(stderr, "\033[0;31mError: Can't form a stack. arr must contain one element at least.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    stNode *top = NULL;

    stNode *prev_node = NULL;

    for (int i = 0; i < len; i++) {
        stNode *current_node = malloc(sizeof(stNode));
        current_node->data = arr[i];
        current_node->next = NULL;

        if (i == 0) {
            top = current_node;
        }

        if (prev_node != NULL) {
            prev_node->next = current_node;
        }

        prev_node = current_node;
    }

    return top;
}

stNode *push(stNode *top, char data) {
   if (top == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't push a new node. top can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
   } 

   stNode *new_node = malloc(sizeof(stNode));
   new_node->data = data;
   new_node->next = top;

   return new_node;
}

stNode *pop(stNode *top) {
   if (top == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't pop the top node. top can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
   } 

   stNode *new_top = top->next;

   free(top);

   return new_top;
}

size_t len_stack() {

}

void peek() {

}

stNode *delete_stack() {

}