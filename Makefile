##
## EPITECH PROJECT, 2024
## COFv1
## File description:
## makefile
##

SRC = src/password/password.c \
		src/get_data.c \
		src/encrypt/choose_crypt.c \
		src/set_new_file.c \
		src/encrypt/basic_crypt.c \
		src/encrypt/med_crypt.c \

OBJ = $(SRC:.c=.o)

NAME = COFv1

CRP = -lcrypt -lssl -lcrypto

INCLUDE = -I./includes/

CFLAGS = -Wall -Wextra -g $(INCLUDE)

CRITERION = -lcriterion --coverage

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) main.c $(OBJ) $(CRP) $(INCLUDE)

tests_run: $(OBJ)
	@gcc -o unit_test $(SRC) tests/*.c $(CRITERION) -lm -g -I./includes -lcrypt
	@./unit_test
	@gcovr --exclude tests/
	@gcovr --exclude tests/ --branches

clean:
	rm -f $(OBJ)

fclean:
	@rm -f $(NAME)

re: fclean all clean
