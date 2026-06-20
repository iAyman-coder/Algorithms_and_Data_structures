#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE  100

typedef struct User {
    char user_name[20];
    char actual_name[40];
    char email[125];
    char job_title[30];
    int age;
    struct User *next;
}User;

// The hash table where users will be inserted into.
User *hash_table[TABLE_SIZE] = {NULL};


unsigned int hash(char *user_name) {
    /* This hash function uses the djb2 hashing method */

    unsigned int hash = 5381;
    int c;

    /*
        In the Boolean expression of the while loop, we are doing three things at once:
        1. *user_name -> dereferences the pointer and gives back the character that pointer was pointing to.
        2. (unsigned char) -> casting any character that is not ASCII into ASCII, so the hash function 
            doesn't calculate negative numbers. 
        3. user_name++ -> incrementing the pointer in order to go to the next character after the current
            iteration has ended.
    */
    while ((c = (unsigned char)*user_name++)) {
        hash = hash * 33 + c;   // hashing formula for the djb2 hasing method.
    }

    // Dividing by TABLE_SIZE to not return an index greater than the size of the hash table.
    return hash % TABLE_SIZE;
}

bool check_user_name(char *user_name) {
    /*
        This function returns true if the user name is available. It return false otherwise.
    */

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

bool insert_user(char *user_name, char *actual_name, char *email, char *job_title, int age) {
    if (strlen(user_name) > 20) {
        fprintf(stderr, "\033[0;31mError: User name can be at most 20 characters.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if (strlen(actual_name) > 40) {
        fprintf(stderr, "\033[0;31mError: Actual name can be at most 40 characters.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if (strlen(email) > 125) {
        fprintf(stderr, "\033[0;31mError: E-mail can be at most 125 characters.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if (strlen(job_title) > 30) {
        fprintf(stderr, "\033[0;31mError: Job title can be at most 30 characters.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if (age > 100) {
        fprintf(stderr, "\033[0;31mError: Age can't exceed 100 years.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    if (!check_user_name(user_name)) {
        /*
            This conditional checks if the user_name has been already taken
            and returns false accordingly.
        */
        return false;
    }

    unsigned int indx = hash(user_name);

    User *current_node = hash_table[indx];

    // Allocating a new user and populating it with data.
    User *new_user = malloc(sizeof(User));
    strcpy(new_user->user_name, user_name);
    strcpy(new_user->actual_name, actual_name);
    strcpy(new_user->email, email);
    strcpy(new_user->job_title, job_title);
    new_user->age = age;

    // Inserting the new user node into the beginning of the linked list.
    hash_table[indx] = new_user;
    new_user->next = current_node;

    return true;
}

bool remove_user(char *user_name) {
    if (strlen(user_name) > 20) {
        fprintf(stderr, "\033[0;31mError: User name can be at most 20 characters.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    unsigned int indx = hash(user_name);

    if (hash_table[indx] == NULL) {
        return false;
    }
    else if (strcmp(hash_table[indx]->user_name, user_name) == 0) {
        /*
            This conditional checks if the first node is the one to be
            removed and remove it accordingly then returns immediately. 
        */
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

    // Connecting the node before current node to the node after it.
    prev_node->next = next_node;

    free(current_node);

    return true;
}

User *search_user(char *user_name) {
    if (strlen(user_name) > 20) {
        fprintf(stderr, "\033[0;31mError: User name can be at most 20 characters.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

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
    size_t users_num = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            /*
                This conditional skips the current iteration if the element
                at index i doesn't contain any users. 
            */
            continue;
        }

        User *current_node = hash_table[i];

        while (current_node != NULL) {
            users_num++;

            current_node = current_node->next;
        }
    }

    return users_num;
}

bool is_hash_table_empty(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            return false;
        }
    }

    return true;
}

void print_user(User *usr) {
    if (usr == NULL) {
        printf("User doesn't exist\n");
        return;
    }

    printf("@%s information.\n", usr->user_name);
    printf("==================================\n");
    printf("Name: %s\n", usr->actual_name);
    printf("E-mail: %s\n", usr->email);
    printf("Job Title: %s\n", usr->job_title);
    printf("Age: %i\n", usr->age);
}

void unload_users(void) {
    if (is_hash_table_empty()) {
        fprintf(stderr, "\033[0;31mError: Can't unload users. Hash table is already empty.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            /*
                This conditional skips the current iteration if the element
                at index i doesn't contain any user nodes. 
            */
            continue;
        }

        User *current_node = hash_table[i];
        User *next_node;

        while (current_node != NULL) {
            next_node = current_node->next;

            free(current_node);

            current_node = next_node;
        }

        // Setting the element at index i to NULL in order to avoid ghost data.
        hash_table[i] = NULL;
    }
}