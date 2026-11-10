NAME = libftprintf.a

CC = cc

AR = ar

CFLAGS = -Wall -Wextra -Werror

RFLAGS = rs

HDR = ft_printf.h

SRCS = ft_printf.c srcs/ft_lng_itoa.c \
       srcs/ft_prnt_utls.c  srcs/ft_nbr_utls.c \
       srcs/ft_putadd.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(RFLAGS) $(NAME) $(OBJS)

%.o : %.c $(HDR)
	$(CC) -c -g $(CFLAGS) $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : clean all

.PHONY = clean
