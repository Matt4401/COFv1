/*
** EPITECH PROJECT, 2025
** COFv1
** File description:
** Password checker
*/

#include "my.h"

static void disable_echo(void)
{
    struct termios tty;

    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

static void enable_echo(void)
{
    struct termios tty;

    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

static void disp_result(int is_correct_mdp)
{
    if (is_correct_mdp == 0)
        printf("\033[31mInvalid password, please try again: \033[0m");
    else
        printf("\033[32mThe password is correct !\033[0m\n");
}

static void hash_to_hex(const unsigned char *hash, char *hex_output)
{
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hex_output + (i * 2), "%02x", hash[i]);
    }
    hex_output[HASH_SIZE - 1] = '\0';
}

static void hash_password(const char *password, char *hashed_password)
{
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    unsigned char hash[SHA256_DIGEST_LENGTH];
    unsigned int len;

    if (!mdctx) {
        perror("Erreur de création du contexte EVP");
        exit(EXIT_FAILURE);
    }
    if (EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL) != 1 ||
        EVP_DigestUpdate(mdctx, password, strlen(password)) != 1 ||
        EVP_DigestFinal_ex(mdctx, hash, &len) != 1) {
        perror("Erreur lors du hachage SHA-256");
        EVP_MD_CTX_free(mdctx);
        exit(EXIT_FAILURE);
    }
    EVP_MD_CTX_free(mdctx);
    hash_to_hex(hash, hashed_password);
}

static int check_password(const char *password)
{
    char hashed_password[HASH_SIZE];
    char line[HASH_SIZE];
    FILE *file = fopen(FILE_PATH, "r");

    if (!file)
        exit(-1);
    hash_password(password, hashed_password);
    if (fgets(line, sizeof(line), file) && line[0] == '#') {
        if (fgets(line, sizeof(line), file) && line[0] == '\n')
            fgets(line, sizeof(line), file);
    }
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, hashed_password) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int get_password(void)
{
    char mdp[256];
    int is_correct_mdp = 0;
    int attempts = 0;

    printf("Welcome !\nEnter password: ");
    while (is_correct_mdp != 1 && attempts < 3) {
        disable_echo();
        scanf("%255s", mdp);
        enable_echo();
        printf("\n");
        is_correct_mdp = check_password(mdp);
        disp_result(is_correct_mdp);
        attempts++;
        if (is_correct_mdp == 1)
            return 0;
    }
    printf("\n\033[1;31m3 incorrect password attempts\033[0m\n");
    return 84;
}
