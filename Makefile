NAME = libasm.a

CC = gcc
ASM_CC = nasm
FORMAT = macho64
FLAGS = -Werror -Wextra -Wall

SRCS = ft_strlen.s ft_strcpy.s

OBJ_FILES = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f test_asm

re: fclear all

%.o: %.s
	$(ASM_CC) -f $(FORMAT) $^

test: main.c
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) main.o $(OBJ_FILES) -o test_asm
	./test_asm
