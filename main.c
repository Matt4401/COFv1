/*
** EPITECH PROJECT, 2025
** COFv1
** File description:
** main of the project
*/

#include "my.h"

static int set_up_data(void)
{
    data_t *data = initialize_data();

    if (!data)
        return 84;
    if (process_file(data) == 84) {
        free(data);
        return 84;
    }
    return 0;
}

static int check_arg(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "\033[1;31mError: Invalid nb of arguments\033[0m\n");
        return 84;
    }
    if (strcmp(argv[1], "encrypt") != 0 && strcmp(argv[1], "decrypt") != 0) {
        fprintf(stderr, "\033[1;31mError: Invalid arguments\033[0m\n");
        fprintf(stderr, "\033[31m./COFv1 [encrypt][decrypt]\033[0m\n");
        return 84;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (check_arg(argc, argv) == 84)
        return 84;
    if (get_password() == 84)
        return 84;
    if (strcmp(argv[1], "encrypt") == 0)
        if (set_up_data() == 84)
            return 84;
    return 0;
}
