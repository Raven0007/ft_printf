NAME = libftprintf.a

CC = cc

AR = ar

CFLAGS = -Wall -Wextra -Werror

RFLAGS = rs

SHARED = srcs/ft_lng_itoa.c srcs/ft_putadd.c  \
       srcs/ft_prnt_utls.c srcs/ft_nbr_utls.c 

SHARED_OBJS = $(SHARED:.c=.o)

MAND_HDR = ft_printf.h

MAND_SRCS = ft_printf.c 

MAND_OBJS = $(MAND_SRCS:.c=.o)

BONUS_HDR = ft_printf_bonus/ft_printf_bonus.h

BONUS_SRCS = ft_printf_bonus/ft_printf_bonus.c \
		ft_printf_bonus/srcs_bonus/ft_flg_roles_bonus.c \
		ft_printf_bonus/srcs_bonus/ft_print_flg_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(MAND_OBJS) $(SHARED_OBJS) $(BONUS_OBJS)
	rm -f $(NAME)
	$(AR) $(RFLAGS) $(NAME) $(MAND_OBJS) $(SHARED_OBJS)

%.o : %.c $(MAND_HDR) $(BONUS_HDR)
	$(CC) -c -g $(CFLAGS) $< -o $@

bonus: $(NAME)
	rm -f $(NAME)
	$(AR) $(RFLAGS) $(NAME) $(BONUS_OBJS) $(SHARED_OBJS)
	
clean :
	rm -rf $(MAND_OBJS) $(SHARED_OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME)

re : clean all

.PHONY = clean
