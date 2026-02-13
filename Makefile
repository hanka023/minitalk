
# Kompilátor
CC = cc

# Kompilační příznaky
CFLAGS = -Wall -Wextra -Werror -I./printf 

FT_PRINTF = ./ft_printf/libftprintf.a

#SRC = src/main.c

# Zdrojové soubory
SRCS =	server.c \
		client.c \
		./utils/ft_atoi.c

# Objektové soubory
OBJS = $(SRCS:%.c=%.o)



# Zdrojové soubory
SRCS_CL =	client.c \
			./utils/ft_atoi.c

SRCS_SV =	server.c \
			./utils/ft_atoi.c

# Objektové soubory
OBJS_CL = $(SRCS_CL:%.c=%.o)

OBJS_SV = $(SRCS_SV:%.c=%.o)
# Název knihovny
# NAME = ps.a

NAME_CL = client
NAME_SV = server

# Výchozí cíl
all: $(NAME_CL) $(NAME_SV)

$(FT_PRINTF):
	make -C  ./ft_printf

$(NAME_CL): $(OBJS_CL) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CL) $(FT_PRINTF) -o $(NAME_CL)


$(NAME_SV): $(OBJS_SV) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SV) $(FT_PRINTF) -o $(NAME_SV)	

# Překlad .c → .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Vyčištění objektových souborů
clean:
	rm -f	$(OBJS_CL)	$(OBJS_SV)
	make -C ./ft_printf clean


# Vyčištění všeho (objekty + knihovna)
fclean: clean
	rm -f $(NAME_CL)	$(NAME_SV)
	make -C ./ft_printf fclean


# Překompilovat celé
re: fclean all

# Phony cíle
.PHONY: all clean fclean re