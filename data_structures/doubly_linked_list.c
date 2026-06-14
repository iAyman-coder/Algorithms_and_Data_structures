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

dNode *insert_new_head() {

}

dNode *insert_new_tail() {

}

dNode *insert_dnode_after_head() {

}

dNode *insert_dnode_before_tail() {

}

dNode *remove_head() {

}

dNode *remove_tail() {

}

dNode *remove_dnode_after_head() {

}

dNode *remove_dnode_before_tail() {

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

void print_dlinked_list(dNode *head_or_tail, char *direction, size_t len) {
    int direction_forward = strcasecmp(direction, "forward");
    int direction_backward = strcasecmp(direction, "backward");

    if (direction_forward != 0 && direction_backward != 0) {
        printf("Can't print doubly linked list.\n");
        printf("Direction string was unrecognized. Make sure you entered 'forward' or 'backward' correctly.\n");
        return;
    }

    dNode *current_node = head_or_tail;
    int i = (direction_forward == 0) ? 0 : len - 1;

    printf("Pos | Data\n");
    while (current_node != NULL) {
        printf("%i | %c\n", i, current_node->data);

        if (direction_forward == 0) {
            current_node = current_node->next;
            i++;
        }
        else if (direction_backward == 0) {
            current_node = current_node->prev;
            i--;
        }
    }
}

size_t len_dlinked_list(dNode *head_or_tail, char *direction) {
    int direction_forward = strcasecmp(direction, "forward");
    int direction_backward = strcasecmp(direction, "backward");

    if (direction_forward != 0 && direction_backward != 0) {
        printf("Can't find the length of doubly linked list.\n");
        printf("Direction string was unrecognized. Make sure you entered 'forward' or 'backward' correctly.\n");
        return 0;
    }

    size_t len = 0;

    dNode *current_node = head_or_tail;

    while (current_node != NULL) {
        len++;

        if (direction_forward == 0) {
            current_node = current_node->next;
        }
        else if (direction_backward == 0) {
            current_node = current_node->prev;
        }
    }

    return len;
}

dNode *delete_dlinked_list_forward() {

}

dNode *delete_dlinked_list_backward() {

}