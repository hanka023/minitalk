
# Kompilátor
CC = cc

# Kompilační příznaky
CFLAGS = -Wall -Wextra -Werror -I./printf 

FT_PRINTF = ./ft_printf/libftprintf.a

#SRC = src/main.c

# Zdrojové soubory
SRCS =	main.c \
		server.c \
		client.c 

# Objektové soubory
OBJS = $(SRCS:%.c=%.o)

# Název knihovny
# NAME = ps.a

NAME = minitalk

# Výchozí cíl
all: $(NAME)

$(FT_PRINTF):
	make -C  ./ft_printf

# $(LIBFT):
# 	make -C  ./libft


# Vytvoření statické knihovny
# $(NAME): $(OBJS)
# 	ar rcs $(NAME) $(OBJS)

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)

# Překlad .c → .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Vyčištění objektových souborů
clean:
	rm -f $(OBJS)
	make -C ./ft_printf clean


# Vyčištění všeho (objekty + knihovna)
fclean: clean
	rm -f $(NAME)
	make -C ./ft_printf fclean


# Překompilovat celé
re: fclean all

# Phony cíle
.PHONY: all clean fclean re