NAME = libftprintf.a

CC = cc

AR = ar

CFLAGS = -Wall -Wextra -Werror

RFLAGS = rs

SHARED = shared/ft_lng_itoa.c shared/ft_putadd.c  \
       shared/ft_prnt_utls.c shared/ft_nbr_utls.c 

SHARED_OBJS = $(SHARED:.c=.o)

MAND_HDR = ft_printf.h

MAND_SRCS = ft_printf.c 

MAND_OBJS = $(MAND_SRCS:.c=.o)

BONUS_HDR = ft_printf_bonus/ft_printf_bonus.h

BONUS_SRCS = ft_printf_bonus/ft_printf_bonus.c \
		ft_printf_bonus/srcs_bonus/ft_flg_roles_bonus.c \
		ft_printf_bonus/srcs_bonus/ft_print_flg_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(MAND_OBJS) $(SHARED_OBJS)
	rm -f $(NAME) $(BONUS_OBJS) bonus
	$(AR) $(RFLAGS) $(NAME) $(MAND_OBJS) $(SHARED_OBJS)

%.o : %.c $(MAND_HDR) $(BONUS_HDR)
	$(CC) -c -g $(CFLAGS) $< -o $@

bonus: $(BONUS_OBJS) $(SHARED_OBJS)
	rm -f $(NAME) $(MAND_OBJS)
	$(AR) $(RFLAGS) $(NAME) $(BONUS_OBJS) $(SHARED_OBJS)
	touch bonus

clean :
	rm -rf $(MAND_OBJS) $(SHARED_OBJS) $(BONUS_OBJS) bonus

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean
