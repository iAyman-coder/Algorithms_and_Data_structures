#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <stddef.h>    // Included for the size_t data type.

/**
 * @brief Node of hash table for encapsulating data about user.
 */
typedef struct User {
    char user_name[20];
    char actual_name[40];
    char email[125];
    char job_title[30];
    int age;
    struct User *next;
}User;

/**
 * @brief Turn a user name into an index in the hash table.
 * 
 * @param user_name: String containing the user name that will be hashed.
 * 
 * @return Index in the hash table.
 */
unsigned int hash(const char user_name[20]);

/**
 * @brief Check if user_name is available to use.
 * 
 * @param user_name: String containing the user name that will be hashed.
 * 
 * @return True if user_name is available. false if user_name has already been used.
 */
bool check_user_name(const char user_name[20]);

/**
 * @brief Insert a new user into the hash table.
 * 
 * @param user_name: String containing the user name that will be hashed.
 * @param actual_name: String containing the real name of the user.
 * @param email: String containing the email of the user.
 * @param job_title: String containing specification about the job of the user.
 * @param age: Integer representing the age of the user.
 * 
 * @return True if user was inserted, false if not. 
 */
bool insert_user(char user_name[20], char actual_name[40], char email[125], char job_title[30], int age);

/**
 * @brief Delete user from the hash table.
 * 
 * @param user_name: String containing the user name that will be hashed.
 * 
 * @return True if user was removed successfully, false if not.
 */
bool remove_user(char user_name[20]);

/**
 * @brief Search for user in the hash table.
 * 
 * @param user_name: String containing the user name that will be hashed.
 * 
 * @return If found, pointer to the node that contins information about user. If not found, NULL.
 */
User *search_user(char user_name[20]);

/**
 * @brief Get how many users exist in the hash table.
 * 
 * @param void: No parameters are needed.
 * 
 * @return Number of existing users as size_t.
 */
size_t get_users_num(void);

/**
 * @brief Check if the hash table contains data or not.
 * 
 * @param void: No parameters are needed.
 * 
 * @return True if hash table is empty, false otherwise.
 */
bool is_hash_table_empty(void);

/**
 * @brief Print information about found user.
 * 
 * @param user_name: String containing the user name that will be hashed.
 * 
 * @return Nothing (void).
 */
void print_user(char user_name[20]);

/**
 * @brief Delete all users from the hash table.
 * 
 * @param void: No parameters are needed.
 * 
 * @return Nothing (void).
 */
void unload_users(void);


#endif