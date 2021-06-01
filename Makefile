NAME = libftprintf.a

SRCS =	ft_parser.c			ft_print_char.c		ft_print_digit.c \
		ft_print_hex.c		ft_print_pointer.c	ft_print_precent.c \
		ft_print_string.c	ft_printf.c			ft_printing.c \
		ft_utilts.c			ft_utilts2.c		ft_utilts3.c	\

OBJS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror 

INCLUDE = ./includes/

all : $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@  

$(NAME) : $(OBJS) $(INCLUDE)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : $(NAME)

.PHONY: clean fclean re all