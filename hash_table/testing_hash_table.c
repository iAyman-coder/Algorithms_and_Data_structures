#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash_table.h"
#include "testing_tools.h"


int main(void) {
    test_boolean(is_hash_table_empty(), "Checking if initial hash table is empty");

    bool insertion;
    bool removal;
    size_t user_num;

    insertion = insert_user("Lilly",
                            "Lilly Rose Simon",
                            "lilly.rose@example.com",
                            "Fashion Designer",
                            44);

    test_boolean(insertion, "Inserting first user");
    test_result(get_users_num(), 1, "One user");

    insertion = insert_user("Genevieve",
                            "Genevieve Georgie Wilson",
                            "gen_g_wilson@example.com",
                            "Carpenter",
                            47);

    test_boolean(insertion, "Inserting second user");
    test_result(get_users_num(), 2, "Two users");

    insertion = insert_user("Mamie",
                            "Mamie Leah Buchanan",
                            "mamie_LB@example.com",
                            "Musician",
                            27);

    test_boolean(insertion, "Inserting third user");
    test_result(get_users_num(), 3, "Three users");

    insertion = insert_user("Don",
                            "Don Nicholas Klein",
                            "Don.Nich123@example.com",
                            "Mechanic",
                            38);

    test_boolean(insertion, "Inserting fourth user");
    test_result(get_users_num(), 4, "Four users");

    insertion = insert_user("Marc",
                            "Marc Arthur Williamson",
                            "marcWilli88@example.com",
                            "Taxi Driver",
                            21);

    test_boolean(insertion, "Inserting fifth user");
    test_result(get_users_num(), 5, "Five users");

    User *found_user1 = search_user("Genevieve");
    printf("\n");
    print_user(found_user1);
    printf("\n");

    User *found_user2 = search_user("Marc");
    printf("\n");
    print_user(found_user2);
    printf("\n");

    User *found_user3 = search_user("Daisy");
    printf("\n");
    printf("Test: Searching for a user that doesn't exist\n");
    print_user(found_user3);
    printf("\n");

    removal = remove_user("Don");

    test_boolean(removal, "Removing 'Don'");
    test_result(get_users_num(), 4, "Four users (removal)");

    User *removed_user1 = search_user("Don");
    printf("\n");
    printf("Test: Searching for a deleted user\n");
    print_user(removed_user1);
    printf("\n");

    removal = remove_user("Lilly");

    test_boolean(removal, "Removing 'Lilly'");
    test_result(get_users_num(), 3, "Three users (removal)");

    User *removed_user2 = search_user("Lilly");
    printf("\n");
    printf("Test: Searching for a deleted user\n");
    print_user(removed_user2);
    printf("\n");

    removal = remove_user("Johnny");
    if (!removal) {
        printf("\033[0;32mNon-existing node was not removed\033[0;0m\n");
    }
    else {
        printf("\033[0;32mNon-existing node was removed\033[0;0m\n");
    }

    unload_users();

    printf("\n");
    test_boolean(is_hash_table_empty(), "Checking if unloaded hash table is empty");

    return 0;
}