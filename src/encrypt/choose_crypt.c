/*
** EPITECH PROJECT, 2025
** COFv1
** File description:
** Functions for crypt the given file
*/

#include "my.h"

char *set_crypt_comp(data_t *data, char *line)
{
    if (data->complexity == 1)
        line = basic_encrypt(line);
    if (data->complexity == 2)
        line = cesar_with_key(line, SECRET_KEY, true);
    return line;
}
