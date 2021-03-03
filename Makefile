NAME = libftprintf.a

SRCS = srcs/basic_fcts.c \
		srcs/converters.c \
		srcs/flag_minus.c \
		srcs/flag_point.c \
		srcs/flag_width.c \
		srcs/ft_printf.c \
		srcs/supp_fcts.c

OTH_OBJS = basic_fcts.o \
		converters.o \
		flag_minus.o \
		flag_point.o \
		flag_width.o \
		ft_printf.o \
		supp_fcts.o

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror -I./headers

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(OTH_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re