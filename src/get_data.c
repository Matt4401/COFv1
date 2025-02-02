/*
** EPITECH PROJECT, 2025
** COFv1
** File description:
** Functions for have the executer data
*/

#include "my.h"

static int is_valid_file(char *filepath)
{
    FILE *file = fopen(filepath, "r");

    if (file) {
        fclose(file);
        return 0;
    }
    return 84;
}

static char *get_filepath(void)
{
    char *filepath = malloc(256 * sizeof(char));

    if (filepath == NULL) {
        perror("malloc");
        return NULL;
    }
    printf("-----------------------------------------------\n");
    printf("Enter the path of the file you want to encrypt: ");
    scanf("%s255", filepath);
    if (is_valid_file(filepath) == 84) {
        free(filepath);
        return NULL;
    }
    return filepath;
}

static int get_complexity(void)
{
    int comp = 0;

    printf("-----------------------------------------------\n");
    printf("Choose the complexity of the encryption :\n");
    printf("  1 : \033[1mBasic\033[0m (bit-shifting)\n");
    printf("  2 : \033[1mMedium\033[0m (dynamic cesar)\n");
    printf("  3 : \033[1mHard\033[0m ()\nChoose here -> ");
    scanf("%d", &comp);
    if (comp > 3 || comp < 1) {
        printf("\033[1;31mError : Invalid complexity\033[0m\n");
        return -1;
    }
    printf("\033[32mYou choose the %d encryption\033[0m\n", comp);
    return comp;
}

data_t *initialize_data(void)
{
    data_t *data = malloc(sizeof(data_t));

    if (data == NULL) {
        perror("malloc");
        return NULL;
    }
    data->filepath = get_filepath();
    if (!data->filepath) {
        free(data);
        printf("\033[1;31mError : the file does not exist\033[0m\n");
        return NULL;
    }
    printf("Filepath: \033[1m%s\033[0m\n", data->filepath);
    data->complexity = get_complexity();
    if (data->complexity == -1)
        return NULL;
    return data;
}
