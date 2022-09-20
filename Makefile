S = srcs/
O = objs/

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = -rm -rf

SRCS = $Scheck.c $Serrors.c $Sfree.c $Sft_split.c $Sget_map.c $Slinked.c $Smain.c $Sprint.c $Sutils.c\

OBJS = $Ocheck.o $Oerrors.o $Ofree.o $Oft_split.o $Oget_map.o $Olinked.o $Omain.o $Oprint.o $Outils.o\

F = -fsanitize=address

all: $(NAME)

$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS): | $O

$(OBJS): $O%.o: $S%.c
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME) -Lmlx_linux -lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all