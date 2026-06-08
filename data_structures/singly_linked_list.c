#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    char data;
    struct node *next;
}node;


node *make_linked_list(char arr[], size_t len) {
    node *prev_node = NULL;
    node *head = NULL;

    for (int i = 0; i < len; i++) {
        node *nd = malloc(sizeof(node));

        nd->data = arr[i];
        nd->next = NULL;

        if (prev_node != NULL) {
            prev_node->next = nd;
        }

        if (i == 0) {
            head = nd;
        }

        prev_node = nd;
    }

    return head;
}

node *insert_node(node *head, node *nd, int pos) {
    if (pos == 0) {
        nd->next = head;
        return nd;
    }

    node *prev_node = head;
    node *next_node = NULL;

    int i = 1;
    while (prev_node->next != NULL) {
        if (i == pos) {
            break;
        }

        prev_node = prev_node->next;

        i++;
    }

    next_node = prev_node->next;
    nd->next = next_node;
    prev_node->next = nd;

    return head;
}

int remove_node() {
    
}

int *search_linked_list() {
    
}

void delete_linked_list() {
    
}

int main(void) {
   
}