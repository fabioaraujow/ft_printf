NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRCS = ft_printf.c\
	ft_putchar_pf.c\
	ft_putstr_pf.c\
	ft_putnbr_pf.c\
	ft_putunsigned_pf.c\
	ft_puthex_pf.c
#	ft_putptr_pf.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
