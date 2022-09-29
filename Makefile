S = srcs/
O = objs/

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = -rm -rf

SRCS = $Scheck_map.c $Sdraw_map.c $Sfree.c $Sft_split.c $Sget_map.c $Smain.c $Smovements.c $Sprint.c $Sprocess_errors.c $Sstart_end_game.c $Sutils_linked.c $Sutils.c $Sutils2.c\

OBJS = $Ocheck_map.o $Odraw_map.o $Ofree.o $Oft_split.o $Oget_map.o $Omain.o $Omovements.o $Oprint.o $Oprocess_errors.o $Ostart_end_game.o $Outils_linked.o $Outils.o $Outils2.o\

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
	$(CC) $(CFLAGS)  $^ -o $(NAME) -Lmlx_linux -lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz

clean:
	$(RM) $(OBJS) $O

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all