/*
** EPITECH PROJECT, 2025
** COFv1
** File description:
** functions for the medium encryption
*/

#include "my.h"

char *uppercase(char *line, int i, const char *key, bool action)
{
    int shift = key[i % strlen(key)] - 'A';

    if (action)
        line[i] = 'A' + (line[i] - 'A' + shift) % 26;
    else
        line[i] = 'A' + (line[i] - 'A' - shift + 26) % 26;
    return line;
}

char *lowercase(char *line, int i, const char *key, bool action)
{
    int shift = key[i % strlen(key)] - 'a';

    if (action)
        line[i] = 'a' + (line[i] - 'a' + shift) % 26;
    else
        line[i] = 'a' + (line[i] - 'a' - shift + 26) % 26;
    return line;
}

char *digit(char *line, int i, const char *key, bool action)
{
    int shift = key[i % strlen(key)] - '0';

    if (action)
        line[i] = '0' + (line[i] - '0' + shift) % 10;
    else
        line[i] = '0' + (line[i] - '0' - shift + 10) % 10;
    return line;
}

char *printable(char *line, int i, const char *key, bool action)
{
    int shift = key[i % strlen(key)] - 32;

    if (action)
        line[i] = 32 + (line[i] - 32 + shift) % 95;
    else
        line[i] = 32 + (line[i] - 32 - shift + 95) % 95;
    return line;
}

char *cesar_with_key(char *line, const char *key, bool action)
{
    int line_len = strlen(line);
    char current_char;

    for (int i = 0; i < line_len; i++) {
        current_char = line[i];
        if (current_char >= 'A' && current_char <= 'Z')
            line = uppercase(line, i, key, action);
        if (current_char >= 'a' && current_char <= 'z')
            line = lowercase(line, i, key, action);
        if (current_char >= '0' && current_char <= '9')
            line = digit(line, i, key, action);
        if (current_char >= 32 && current_char <= 126)
            line = printable(line, i, key, action);
    }
    return line;
}
