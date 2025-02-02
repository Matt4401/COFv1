/*
** EPITECH PROJECT, 2025
** COFv1
** File description:
** functions for the basic crypt
*/

#include "my.h"

char *basic_encrypt(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        line[i] = line[i] + 1;
    }
    return line;
}

// void simple_decrypt(char *line)
// {
//     for (int i = 0; line[i] != '\0'; i++) {
//         line[i] = line[i] - 1;
//     }
// }
