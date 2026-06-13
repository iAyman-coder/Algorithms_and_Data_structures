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
    if (strcasecmp(direction, "forward") == 0) {
        if (pos == 0) {
            new_node->next = head_or_tail;
            new_node->prev = NULL;
            head_or_tail->prev = new_node;

            return new_node;
        }

        dNode *prev_node = head_or_tail;

        for (int i = 1; prev_node->next != NULL; i++) {
            if (i == pos) {
                break;
            }

            prev_node = prev_node->next;
        }

        dNode *next_node = prev_node->next;

        prev_node->next = new_node;
        new_node->prev = prev_node;

        new_node->next = next_node;
        if (next_node != NULL) {
            next_node->prev = new_node;
        }

        return head_or_tail;
    }
    else if (strcasecmp(direction, "backward") == 0) {
        if (pos == 0) {
            new_node->next = NULL;
            new_node->prev = head_or_tail;
            head_or_tail->next = new_node;

            return new_node;
        }

        dNode *next_node = head_or_tail;

        for (int i = 1; next_node->prev != NULL; i++) {
            if (i == pos) {
                break;
            }

            next_node = next_node->prev;
        }

        dNode *prev_node = next_node->prev;

        new_node->prev = prev_node;
        if (prev_node != NULL) {
            prev_node->next = new_node;
        }

        new_node->next = next_node;
        next_node->prev = new_node;

        return head_or_tail;
    }
    else {
        printf("new_node was not inserted.\n");
        printf("direction string was unrecognized. Make sure you entered 'forward' or 'backward'.\n");
        return head_or_tail;
    }
}

dNode *remove_dnode(dNode *head_or_tail, char *direction, int pos) {

}

dNode *search_dlinked_list(dNode *head_or_tail, char *direction, char target) {

}

dNode *delete_dlinked_list(dNode *head_or_tail, char *direction) {

}