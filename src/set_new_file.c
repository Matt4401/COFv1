/*
** EPITECH PROJECT, 2025
** COFv1
** File description:
** Functions for clone and crypt the file
*/

#include "my.h"

static FILE *create_new_file(void)
{
    FILE *temp = fopen("temp.txt", "w");

    if (!temp) {
        perror("Erreur lors de la création du fichier temporaire");
        return NULL;
    }
    return temp;
}

static int rename_temp_file(const char *tempfile, const char *newname)
{
    if (rename(tempfile, newname) != 0) {
        perror("Erreur lors du renommage du fichier");
        return 84;
    }
    return 0;
}

static int del_old_file(const char *oldfile)
{
    if (remove(oldfile) != 0) {
        perror("Erreur lors de la suppression du fichier");
        return 84;
    }
    return 0;
}

static int check_files(FILE *file, FILE *temp)
{
    if (!file || !temp) {
        perror("Erreur d'ouverture du fichier");
        if (file)
            fclose(file);
        if (temp)
            fclose(temp);
        return 84;
    }
    return 0;
}

int process_file(data_t *data)
{
    FILE *file = fopen(data->filepath, "r");
    FILE *temp = create_new_file();
    char *line = malloc(sizeof(char) * 1024);

    if (check_files(file, temp) == 84)
        return 84;
    while (fgets(line, sizeof(line), file)) {
        line = set_crypt_comp(data, line);
        fprintf(temp, "%s", line);
    }
    fclose(file);
    if (del_old_file(data->filepath) != 0)
        return 84;
    if (rename_temp_file("temp.txt", data->filepath) != 0)
        return 84;
    fclose(temp);
    return 0;
}
