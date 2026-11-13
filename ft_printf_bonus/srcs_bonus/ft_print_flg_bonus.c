/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flg_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:24:15 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/13 15:49:46 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_set_nb_sign(va_list *conver, t_flag *strc)
{
	int	nb;
	int	res[2];

	res[0] = 0;
	nb = va_arg(*conver, int);
	if (nb >= 0 && (strc->sign || strc->space))
	{
		if (strc->sign == 1)
		{
			if (ft_putstr("+") == -1)
				return (-1);
		}
		else
		{
			if (ft_putstr(" ") == -1)
				return (-1);
		}
		res[0] = 1;
	}
	res[1] = ft_putnb(nb);
	if (res[1] == -1)
		return (-1);
	return (res[1] + res[0]);
}

int	ft_set_addrs_sign(va_list *conver, t_flag *strc, char type)
{
	void	*add;
	int		res[2];

	res[0] = 0;
	add = va_arg(*conver, void *);
	if ((strc->sign || strc->space) && !add)
	{
		if (strc->sign == 1)
		{
			if (ft_putstr("+") == -1)
				return (-1);
		}
		else
		{
			if (ft_putstr(" ") == -1)
				return (-1);
		}
		res[0] = 1;
	}
	res[1] = ft_put_hex((unsigned long)add, type);
	if (res[1] == -1)
		return (-1);
	return (res[1] + res[0]);
}

int	ft_set_alternative(va_list *conver, t_flag *strc, char type)
{
	unsigned int	hex;
	int				res[2];

	res[0] = 0;
	hex = va_arg(*conver, unsigned int);
	if (hex > 0 && strc->alt)
	{
		if (type == 'X')
		{
			if (ft_putstr("0X") == -1)
				return (-1);
		}
		else
		{
			if (ft_putstr("0x") == -1)
				return (-1);
		}
		res[0] = 2;
	}
	res[1] = ft_put_hex(hex, type);
	if (res[1] == -1)
		return (-1);
	return (res[1] + res[0]);
}
