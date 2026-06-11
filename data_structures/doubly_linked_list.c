#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct dNode {
    char data;
    struct dNode *prev;
    struct dNode *next;
}dNode;

dNode **make_dlinked_list(char arr[], size_t len, dNode *head_and_tail_ptrs[2]) {
    dNode *head = NULL;
    dNode *tail = NULL;

    dNode *prev_node = NULL;

    for (int i = 0; i < len; i++) {
        dNode *current_node = malloc(sizeof(dNode));
        current_node->data = arr[i];
        current_node->next = NULL;
        current_node->prev = prev_node;

        if (prev_node != NULL) {
            prev_node->next = current_node;
        }

        if (i == 0) {
            head = current_node;
        }
        else if (i == len - 1) {
            tail = current_node;
        }

        prev_node = current_node;
    }

    head_and_tail_ptrs[0] = head;
    head_and_tail_ptrs[1] = tail;

    return head_and_tail_ptrs;
}

dNode *insert_dnode(dNode *head_or_tail, char *direction, dNode *new_node, int pos) {

}

dNode *remove_dnode(dNode *head_or_tail, char *direction, int pos) {

}

dNode *search_dlinked_list(dNode *head_or_tail, char *direction, char target) {

}

dNode *delete_dlinked_list(dNode *head_or_tail, char *direction) {

}