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

int main(int argc, char *argv[])
{
    if (get_password() == 84)
        return 84;
    if (set_up_data() == 84)
        return 84;
    return 0;
}
