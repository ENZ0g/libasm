NAME = libasm.a
NAME_BONUS = libasm_bonus.a

CC = gcc
ASM_CC = nasm
FORMAT = macho64
FLAGS = -Werror -Wextra -Wall

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRCS_BONUS = ft_list_size_bonus.s ft_list_push_front.s

OBJ_FILES = $(SRCS:.s=.o)
OBJ_FILES_BONUS = $(SRCS_BONUS:.s=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f test_asm
	rm -f test_bonus

re: fclean all

bonus: $(OBJ_FILES_BONUS)
	ar rc $(NAME_BONUS) $(OBJ_FILES_BONUS)
	ranlib $(NAME_BONUS)

test: test.c $(OBJ_FILES)
	$(CC) $(FLAGS) -c test.c
	$(CC) $(FLAGS) test.o $(OBJ_FILES) -o test_asm
	./test_asm

test_bonus: test_bonus.c $(OBJ_FILES_BONUS)
	$(CC) $(FLAGS) -c test_bonus.c
	$(CC) $(FLAGS) test_bonus.o $(OBJ_FILES_BONUS) -o test_bonus -I. -L. -lft
	./test_bonus

%.o: %.s
	$(ASM_CC) -f $(FORMAT) $^