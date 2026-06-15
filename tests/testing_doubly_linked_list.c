#include <stdio.h>
#include <stdlib.h>
#include "ds_custom_tests.h"
#include "../data_structures/doubly_linked_list.h"

int main(void) {
    dNode *head_and_tail[2];

    char arr[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    make_dlinked_list(arr, 10, head_and_tail);

    dNode *head = head_and_tail[0];

    char correct1[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_linked_list(head, correct1, 10, "Initial linked list");

    printf("============Initial Doubly Linked List============");
    print_dlinked_list_forward(head);
    printf("==================================================");

    dNode *new_head = malloc(sizeof(dNode));
    new_head->data = 'S';
    new_head->prev = NULL;
    new_head->next = NULL;

    head = insert_new_head(head, new_head);

    char correct2[11] = {'S', 'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_linked_list(head, correct2, 11, "Inserting new head");

    size_t list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 11, "List length: 11 nodes");

    dNode *new_node = malloc(sizeof(dNode));
    new_node->data = 'G';
    new_node->prev = NULL;
    new_node->next = NULL;

    head = insert_dnode_after_head(head, list_len, new_node, 7);

    char correct3[12] = {'S', 'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 't'};
    test_linked_list(head, correct3, 12, "Inserting node in a middle position");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 12, "List length: 12 nodes");

    dNode *new_node_last = malloc(sizeof(Node));
    new_node_last->data = 'W';
    new_node_last->prev = NULL;
    new_node_last->next = NULL;

    head = insert_dnode_after_head(head, list_len, new_node_last, 11);

    char correct4[13] = {'S', 'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 'W', 't'};
    test_linked_list(head, correct4, 13, "Inserting node before tail node");

    printf("============Modified Doubly Linked List============");
    print_dlinked_list_forward(head);
    printf("==================================================");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 13, "List length: 13 nodes");

    head = remove_head(head);

    char correct5[12] = {'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 'W', 't'};
    test_linked_list(head, correct5, 12, "Removing head");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 12, "List length: 12 nodes");

    head = remove_dnode_after_head(head, list_len, 6);

    char correct6[11] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 'W', 't'};
    test_linked_list(head, correct6, 11, "Removing a middle node");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 11, "List length: 11 nodes");

    head = remove_dnode_after_head(head, list_len, 9);

    char correct7[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_linked_list(head, correct7, 10, "Removing the node before tail");

    printf("============Doubly Linked List After Removing Nodes============");
    print_dlinked_list_forward(head);
    printf("==================================================");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 10, "List length: 10 nodes");

    dNode *found_node_first = search_dlinked_list_forward(head, 'l');

    char correct8[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_linked_list(found_node_first, correct8, 10, "Search for first node");

    dNode *found_node_middle = search_dlinked_list_forward(head, 'k');

    char correct9[7] = {'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_linked_list(found_node_middle, correct9, 7, "Search for node in the middle");

    dNode *found_node_last = search_dlinked_list_forward(head, 't');

    char correct10[1] = {'t'};
    test_linked_list(found_node_last, correct10, 1, "Search for last node");

    head = delete_dlinked_list_forward(head);

    if (head == NULL) {
        printf("\033[0;32m[Linked list was deleted successfully]\033[0;0m\n");
    }
    else {
        printf("\033[0;31m[Linked list was not deleted successfully]\033[0;0m\n");
    }

    return 0;
}