/*
** EPITECH PROJECT, 2025
** COFv1
** File description:
** header of the project
*/

#ifndef MY_H_
    #define MY_H_

    #define HASH_SIZE 65
    #define FILE_PATH "password.txt"
    #define SECRET_KEY "f!5iVb7yR3S*jQzT4X$9U"

    #include <stdio.h>
    #include <unistd.h>
    #include <pwd.h>
    #include <openssl/sha.h>
    #include <openssl/evp.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <string.h>
    #include <termios.h>
    #include <crypt.h>
    #include <stddef.h>
    #include <sys/types.h>
    #include <stdbool.h>
    #include <grp.h>
    #include <unistd.h>
    #include <bits/getopt_core.h>
    #include <errno.h>
    #include "struct.h"

int get_password(void);
data_t *initialize_data(void);
int process_file(data_t *data);
char *set_crypt_comp(data_t *data, char *line);
char *basic_encrypt(char *line);
char *cesar_with_key(char *line, const char *key, bool action);

#endif /* !MY_H_ */
