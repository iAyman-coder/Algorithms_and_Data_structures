#include <stdio.h>
#include <stdlib.h>
#include "ds_custom_tests.h"
#include "../data_structures/doubly_linked_list.h"

void testing_forward(void) {
    dNode *head_and_tail[2];

    char arr[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    make_dlinked_list(arr, 10, head_and_tail);

    dNode *head = head_and_tail[0];

    char correct1[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct1, 10, "Initial linked list");

    printf("\n");
    printf("============Initial Doubly Linked List============\n");
    print_dlinked_list_forward(head);
    printf("==================================================\n");
    printf("\n");

    dNode *new_head = malloc(sizeof(dNode));
    new_head->data = 'S';
    new_head->prev = NULL;
    new_head->next = NULL;

    head = insert_new_head(head, new_head);

    char correct2[11] = {'S', 'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct2, 11, "Inserting new head");

    size_t list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 11, "List length: 11 nodes (insertion)");

    dNode *new_node = malloc(sizeof(dNode));
    new_node->data = 'G';
    new_node->prev = NULL;
    new_node->next = NULL;

    head = insert_dnode_after_head(head, list_len, new_node, 7);

    char correct3[12] = {'S', 'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct3, 12, "Inserting node in a middle position");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 12, "List length: 12 nodes (insertion)");

    dNode *new_node_last = malloc(sizeof(Node));
    new_node_last->data = 'W';
    new_node_last->prev = NULL;
    new_node_last->next = NULL;

    head = insert_dnode_after_head(head, list_len, new_node_last, 11);

    char correct4[13] = {'S', 'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 'W', 't'};
    test_dlinked_list(head, correct4, 13, "Inserting node before tail node");

    printf("\n");
    printf("============Modified Doubly Linked List============\n");
    print_dlinked_list_forward(head);
    printf("==================================================\n");
    printf("\n");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 13, "List length: 13 nodes (insertion)");

    head = remove_head(head);

    char correct5[12] = {'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 'W', 't'};
    test_dlinked_list(head, correct5, 12, "Removing head");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 12, "List length: 12 nodes (removal)");

    head = remove_dnode_after_head(head, list_len, 6);

    char correct6[11] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 'W', 't'};
    test_dlinked_list(head, correct6, 11, "Removing a middle node");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 11, "List length: 11 nodes (removal)");

    head = remove_dnode_after_head(head, list_len, 9);

    char correct7[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct7, 10, "Removing the node before tail");

    printf("\n");
    printf("============Doubly Linked List After Removing Nodes============\n");
    print_dlinked_list_forward(head);
    printf("==================================================\n");
    printf("\n");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 10, "List length: 10 nodes (removal)");

    dNode *found_node_first = search_dlinked_list_forward(head, 'l');

    char correct8[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(found_node_first, correct8, 10, "Search for first node");

    dNode *found_node_middle = search_dlinked_list_forward(head, 'k');

    char correct9[7] = {'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(found_node_middle, correct9, 7, "Search for node in the middle");

    dNode *found_node_last = search_dlinked_list_forward(head, 't');

    char correct10[1] = {'t'};
    test_dlinked_list(found_node_last, correct10, 1, "Search for last node");

    head = delete_dlinked_list_forward(head);

    if (head == NULL) {
        printf("\033[0;32m[Linked list was deleted successfully]\033[0;0m\n");
    }
    else {
        printf("\033[0;31m[Linked list was not deleted successfully]\033[0;0m\n");
    }

}

void testing_backward(void) {
    dNode *head_and_tail[2];

    char arr[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    make_dlinked_list(arr, 10, head_and_tail);

    dNode *head = head_and_tail[0];
    dNode *tail = head_and_tail[1];

    char correct1[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct1, 10, "Initial linked list");

    printf("\n");
    printf("============Initial Doubly Linked List============\n");
    print_dlinked_list_backward(tail, 10);
    printf("==================================================\n");
    printf("\n");

    dNode *new_tail = malloc(sizeof(dNode));
    new_tail->data = 'S';
    new_tail->prev = NULL;
    new_tail->next = NULL;

    tail = insert_new_tail(tail, new_tail);

    char correct2[11] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't', 'S'};
    test_dlinked_list(head, correct2, 11, "Inserting new tail");

    size_t list_len = len_dlinked_list(tail, "backward");
    test_result(list_len, 11, "List length: 11 nodes (insertion)");

    dNode *new_node = malloc(sizeof(dNode));
    new_node->data = 'G';
    new_node->prev = NULL;
    new_node->next = NULL;

    tail = insert_dnode_before_tail(tail, list_len, new_node, 6);

    char correct3[12] = {'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 't', 'S'};
    test_dlinked_list(head, correct3, 12, "Inserting node in a middle position");

    list_len = len_dlinked_list(tail, "backward");
    test_result(list_len, 12, "List length: 12 nodes (insertion)");

    dNode *new_node_first = malloc(sizeof(Node));
    new_node_first->data = 'W';
    new_node_first->prev = NULL;
    new_node_first->next = NULL;

    tail = insert_dnode_before_tail(tail, list_len, new_node_first, 1);

    char correct4[13] = {'l', 'W', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 't', 'S'};
    test_dlinked_list(head, correct4, 13, "Inserting node before head node");

    printf("\n");
    printf("============Modified Doubly Linked List============\n");
    print_dlinked_list_backward(tail, 13);
    printf("==================================================\n");
    printf("\n");

    list_len = len_dlinked_list(tail, "backward");
    test_result(list_len, 13, "List length: 13 nodes (insertion)");

    tail = remove_tail(tail);

    char correct5[12] = {'l', 'W', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct5, 12, "Removing tail");

    list_len = len_dlinked_list(tail, "backward");
    test_result(list_len, 12, "List length: 12 nodes (removal)");

    tail = remove_dnode_before_tail(tail, list_len, 7);

    char correct6[11] = {'l', 'W', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct6, 11, "Removing a middle node");

    list_len = len_dlinked_list(tail, "backward");
    test_result(list_len, 11, "List length: 11 nodes (removal)");

    tail = remove_dnode_before_tail(tail, list_len, 1);

    char correct7[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct7, 10, "Removing the node before head");

    printf("\n");
    printf("============Doubly Linked List After Removing Nodes============\n");
    print_dlinked_list_backward(tail, 10);
    printf("==================================================\n");
    printf("\n");

    list_len = len_dlinked_list(tail, "backward");
    test_result(list_len, 10, "List length: 10 nodes (removal)");

    dNode *found_node_last = search_dlinked_list_backward(tail, 't');

    char correct8[1] = {'t'};
    test_dlinked_list(found_node_last, correct8, 1, "Search for last node");

    dNode *found_node_middle = search_dlinked_list_backward(tail, 'k');

    char correct9[7] = {'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(found_node_middle, correct9, 7, "Search for node in the middle");

    dNode *found_node_first = search_dlinked_list_backward(tail, 'l');

    char correct10[4] = {'l', 'i', 's', 't'};
    test_dlinked_list(found_node_first, correct10, 4, "Search for first node");

    tail = delete_dlinked_list_backward(tail);

    if (tail == NULL) {
        printf("\033[0;32m[Linked list was deleted successfully]\033[0;0m\n");
    }
    else {
        printf("\033[0;31m[Linked list was not deleted successfully]\033[0;0m\n");
    }
}

int main(void) {
    testing_forward();

    printf("#\n");
    printf("#\n");
    printf("#\n");
    printf(">>>>>>>>>> testing_forward finished\n");
    printf("#\n");
    printf("#\n");
    printf("#\n");

    testing_backward();

    printf("#\n");
    printf("#\n");
    printf("#\n");
    printf(">>>>>>>>>> testing_backward finished\n");
    printf("#\n");
    printf("#\n");
    printf("#\n");

    return 0;
}