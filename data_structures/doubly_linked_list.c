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
        printf("Direction string was unrecognized. Make sure you entered 'forward' or 'backward' correctly.\n");
        return head_or_tail;
    }
}

dNode *remove_dnode(dNode *head_or_tail, char *direction, int pos) {
    if (strcasecmp(direction, "forward") == 0) {
        if (pos == 0) {
            dNode *new_head = head_or_tail->next;
            new_head->prev = NULL;

            free(head_or_tail);

            return new_head;
        }

        dNode *current_node = head_or_tail->next;
        dNode *prev_node;
        dNode *next_node;

        for (int i = 1; current_node != NULL; i++) {
            prev_node = current_node->prev;
            next_node = current_node->next;

            if (i == pos) {
                break;
            }

            current_node = current_node->next;
        }

        prev_node->next = next_node;
        if (next_node != NULL) {
            next_node->prev = prev_node;
        }

        free(current_node);

        return head_or_tail;
    }
    else if (strcasecmp(direction, "forward") == 0) {
        if (pos == 0) {
            dNode *new_tail = head_or_tail->prev;
            new_tail->next = NULL;

            free(head_or_tail);

            return new_tail;
        }

        dNode *current_node = head_or_tail->prev;
        dNode *prev_node;
        dNode *next_node;

        for (int i = 1; current_node != NULL; i++) {
            prev_node = current_node->prev;
            next_node = current_node->next;

            if (i == pos) {
                break;
            }

            current_node = current_node->prev;
        }

        next_node->prev = prev_node;
        if (prev_node != NULL) {
            prev_node->next = next_node;
        }

        free(current_node);

        return head_or_tail;
    }
    else {
        printf("No node was removed.\n");
        printf("Direction string was unrecognized. Make sure you entered 'forward' or 'backward' correctly.\n");
        return head_or_tail;
    }
}

dNode *search_dlinked_list(dNode *head_or_tail, char *direction, char target) {
    int direction_forward = strcasecmp(direction, "forward");
    int direction_backward = strcasecmp(direction, "backward");

    if (direction_forward != 0 && direction_backward != 0) {
        printf("Search did not happen.\n");
        printf("Direction string was unrecognized. Make sure you entered 'forward' or 'backward' correctly.\n");
        return NULL;
    }

    dNode *current_node = head_or_tail;

    while (current_node != NULL) {
        if (current_node->data == target) {
            return current_node;
        }
        else if (direction_forward == 0) {
            current_node = current_node->next;
        }
        else if (direction_backward == 0) {
            current_node = current_node->prev;
        }
    }

    return NULL;
}

dNode *delete_dlinked_list(dNode *head_or_tail, char *direction) {
    if (strcasecmp(direction, "forward") == 0) {
        dNode *current_node = head_or_tail;
        dNode *next_node;

        while (current_node != NULL) {
            next_node = current_node->next;

            free(current_node);

            current_node = next_node;
        }

        return NULL;
    }
    else if (strcasecmp(direction, "backward") == 0) {
        dNode *current_node = head_or_tail;
        dNode *prev_node;

        while (current_node != NULL) {
            prev_node = current_node->prev;

            free(current_node);

            current_node = prev_node;
        }

        return NULL;
    }
    else {
        printf("Doubly linked list was not delted.\n");
        printf("Direction string was unrecognized. Make sure you entered 'forward' or 'backward' correctly.\n");
        return NULL;
    }
}