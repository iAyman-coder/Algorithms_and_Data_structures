#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct dNode {
    char data;
    struct dNode *prev;
    struct dNode *next;
}dNode;


dNode **make_dlinked_list(char arr[], size_t len, dNode *head_and_tail_ptrs[2]) {
    if (len <= 1) {
        fprintf(stderr, "\033[0;31mError: Can't form a doubly linked list. arr must contain two elements at least.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

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

dNode *insert_new_head(dNode *head, dNode *new_node) {
    if (head == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't insert a new head. head can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if (new_node == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't insert a new head. new_node can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    new_node->next = head;
    new_node->prev = NULL;

    head->prev = new_node;

    return new_node;
}

dNode *insert_new_tail(dNode *tail, dNode *new_node) {
    if (tail == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't insert a new tail. tail can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if (new_node == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't insert a new tail. new_node can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    new_node->next = NULL;
    new_node->prev = tail;

    tail->next = new_node;

    return new_node;
}

dNode *insert_dnode_after_head(dNode *head, size_t list_len, dNode *new_node, int pos) {
    if (head == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't insert node. head can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if (list_len <= 0) {
        fprintf(stderr, "\033[0;31mError: Can't insert node. (%i) list_len is invalid.\033[0;0m\n", list_len);
        exit(EXIT_FAILURE);
    }
    else if (new_node == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't insert node. new_node can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if (pos < 1 || pos > list_len - 1) {
        fprintf(stderr, "\033[0;31mError: Can't insert node. (%i) pos is invalid in a list with (%i) nodes.\033[0;0m\n", pos, list_len);
        exit(EXIT_FAILURE);
    }

    dNode *prev_node = head;

    for (int i = 1; i < list_len; i++) {
        if (i == pos) {
            break;
        }
        
        prev_node = prev_node->next;
    }

    dNode *next_node = prev_node->next;

    prev_node->next = new_node;
    new_node->prev = prev_node;

    next_node->prev = new_node;
    new_node->next = next_node;

    return head;
}

dNode *insert_dnode_before_tail(dNode *tail, size_t list_len, dNode *new_node, int pos) {
    if (tail == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't insert node. tail can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if (list_len <= 0) {
        fprintf(stderr, "\033[0;31mError: Can't insert node. (%i) list_len is invalid.\033[0;0m\n", list_len);
        exit(EXIT_FAILURE);
    }
    else if (new_node == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't insert node. new_node can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if (pos < 1 || pos > list_len - 1) {
        fprintf(stderr, "\033[0;31mError: Can't insert node. (%i) pos is invalid in a list with (%i) nodes.\033[0;0m\n", pos, list_len);
        exit(EXIT_FAILURE);
    }

    dNode *next_node = tail;

    for (int i = list_len - 1; i > 0; i--) {
        if (i == pos) {
            break;
        }

        next_node = next_node->prev;
    }

    dNode *prev_node = next_node->prev;

    prev_node->next = new_node;
    new_node->prev = prev_node;

    next_node->prev = new_node;
    new_node->next = next_node;

    return tail;
}

dNode *remove_head(dNode *head) {
    if (head == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't remove head. head can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    dNode *new_head = head->next;
    new_head->prev = NULL;

    free(head);

    return new_head;
}

dNode *remove_tail(dNode *tail) {
    if (tail == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't remove tail. tail can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    dNode *new_tail = tail->prev;
    new_tail->next = NULL;

    free(tail);

    return new_tail;
}

dNode *remove_dnode_after_head(dNode *head, size_t list_len, int pos) {
    if (head == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't remove node. head can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if (list_len <= 0) {
        fprintf(stderr, "\033[0;31mError: Can't remove node. (%i) list_len is invalid.\033[0;0m\n", list_len);
        exit(EXIT_FAILURE);
    }
    else if (pos < 1 || pos > list_len - 2) {
        fprintf(stderr, "\033[0;31mError: Can't remove node. (%i) pos is invalid in a list with (%i) nodes.\033[0;0m\n", pos, list_len);
        exit(EXIT_FAILURE);
    }

    dNode *current_node = head->next;

    for (int i = 1; i < list_len - 1; i++) {
        if (i == pos) {
            break;
        }

        current_node = current_node->next;
    }

    dNode *prev_node = current_node->prev;
    dNode *next_node = current_node->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;

    free(current_node);

    return head;
}

dNode *remove_dnode_before_tail(dNode *tail, size_t list_len, int pos) {
    if (tail == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't remove node. tail can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if (list_len <= 0) {
        fprintf(stderr, "\033[0;31mError: Can't remove node. (%i) list_len is invalid.\033[0;0m\n", list_len);
        exit(EXIT_FAILURE);
    }
    else if (pos < 1 || pos > list_len - 2) {
        fprintf(stderr, "\033[0;31mError: Can't remove node. (%i) pos is invalid in a list with (%i) nodes.\033[0;0m\n", pos, list_len);
        exit(EXIT_FAILURE);
    }

    dNode *current_node = tail->prev;

    for (int i = list_len - 2; i > 0; i--) {
        if (i == pos) {
            break;
        }

        current_node = current_node->prev;
    }

    dNode *prev_node = current_node->prev;
    dNode *next_node = current_node->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;

    free(current_node);

    return tail;
}

dNode *search_dlinked_list_forward(dNode *head, char target) {
    if (head == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't search. head can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    dNode *current_node = head;

    while (current_node != NULL) {
        if (current_node->data == target) {
            return current_node;
        }
        else {
            current_node = current_node->next;
        }
    }

    return NULL;
}

dNode *search_dlinked_list_backward(dNode *tail, char target) {
    if (tail == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't search. tail can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    dNode *current_node = tail;

    while (current_node != NULL) {
        if (current_node->data == target) {
            return current_node;
        }
        else {
            current_node = current_node->prev;
        }
    }

    return NULL;
}

void print_dlinked_list_forward(dNode *head) {
    if (head == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't print doubly linked list. head can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    dNode *current_node = head;

    printf("Pos | Data\n");
    for (int i = 0; current_node != NULL; i++) {
        printf("%i | %c\n", i, current_node->data);
        current_node = current_node->next;
    }
}

void print_dlinked_list_backward(dNode *tail, size_t list_len) {
    if (tail == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't print doubly linked list. tail can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    dNode *current_node = tail;

    printf("Pos | Data\n");
    for (int i = list_len - 1; current_node != NULL; i--) {
        printf("%i | %c\n", i, current_node->data);
        current_node = current_node->prev;
    }
}

size_t len_dlinked_list(dNode *head_or_tail, char *direction) {
    if (head_or_tail == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't find the length of the doubly linked list. head_or_tail can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    int direction_forward = strcasecmp(direction, "forward");
    int direction_backward = strcasecmp(direction, "backward");

    if (direction_forward != 0 && direction_backward != 0) {
        fprintf(stderr, "\033[0;31mError: Can't find the length of the doubly linked list. direction string was unrecognized.\033[0;0m\n");
        fprintf(stderr, "\033[0;34mHint: Make sure you entered 'forward' or 'backward' correctly!\033[0;0m\n");
        exit(EXIT_FAILURE);
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

dNode *delete_dlinked_list_forward(dNode *head) {
    if (head == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't delete doubly linked list. head can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    dNode *current_node = head;
    dNode *next_node;

    while (current_node != NULL) {
        next_node = current_node->next;

        free(current_node);

        current_node = next_node;
    }

    return NULL;
}

dNode *delete_dlinked_list_backward(dNode *tail) {
    if (tail == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't delete doubly linked list. tail can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    dNode *current_node = tail;
    dNode *prev_node;

    while (current_node != NULL) {
        prev_node = current_node->prev;

        free(current_node);

        current_node = prev_node;
    }

    return NULL;
}