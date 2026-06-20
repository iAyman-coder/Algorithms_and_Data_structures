#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct User {
    char user_name[20];
    char actual_name[40];
    char email[125];
    char job_title[30];
    int age;
    struct User *next;
}User;


#define TABLE_SIZE  100

static User *hash_table[TABLE_SIZE] = {NULL};

static size_t USERS_NUM = 0;


unsigned int hash(const char user_name[20]) {
    /* This hash function is the djb2 hash function */

    unsigned int hash = 5381;
    int c;

    while ((c = (unsigned char)*user_name++)) {
        hash = hash * 33 + c;
    }

    return hash % TABLE_SIZE;
}

bool check_user_name(const char user_name[20]) {
    unsigned int indx = hash(user_name);

    User *current_node = hash_table[indx];

    if (current_node == NULL) {
        return true;
    }

    while (current_node != NULL) {
        if (strcmp(current_node->user_name, user_name) == 0) {
            return false;
        }

        current_node = current_node->next;
    }

    return true;
}

bool insert_user(char user_name[20], char actual_name[40], char email[125], char job_title[30], int age) {
    if (!check_user_name(user_name)) {
        return false;
    }

    unsigned int indx = hash(user_name);

    User *current_node = hash_table[indx];

    User *new_user = malloc(sizeof(User));
    strcpy(new_user->user_name, user_name);
    strcpy(new_user->actual_name, actual_name);
    strcpy(new_user->email, email);
    strcpy(new_user->job_title, job_title);
    new_user->age = age;

    hash_table[indx] = new_user;
    new_user->next = current_node;

    USERS_NUM++;

    return true;
}

bool remove_user(char user_name[20]) {
    unsigned int indx = hash(user_name);

    if (hash_table[indx] == NULL) {
        return false;
    }
    else if (strcmp(hash_table[indx]->user_name, user_name) == 0) {
        User *current_node = hash_table[indx];
        User *next_node = current_node->next;

        free(current_node);

        hash_table[indx] = next_node;

        return true;
    }

    User *prev_node = hash_table[indx];
    User *current_node = prev_node->next;

    while (current_node != NULL) {
        if (strcmp(current_node->user_name, user_name) == 0) {
            break;
        }

        prev_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        return false;
    }

    User *next_node = current_node->next;

    prev_node->next = next_node;

    free(current_node);

    USERS_NUM--;

    return true;
}

User *search_user(char user_name[20]) {
    unsigned int indx = hash(user_name);

    User *current_node = hash_table[indx];

    while (current_node != NULL) {
        if (strcmp(current_node->user_name, user_name) == 0) {
            return current_node;
        }

        current_node = current_node->next;
    }

    return NULL;
}

size_t get_users_num(void) {
    return USERS_NUM;
}

bool is_hash_table_empty(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            return false;
        }
    }

    return true;
}

void unload_users(void) {
    if (is_hash_table_empty()) {
        fprintf(stderr, "\033[0;31mError: Can't unload users. Hash table is already empty.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            continue;
        }

        User *current_node = hash_table[i];
        User *next_node;

        while (current_node != NULL) {
            next_node = current_node->next;

            free(current_node);

            current_node = next_node;
        }
    }
}