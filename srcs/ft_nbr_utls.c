/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_utls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:25:58 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/10 16:43:34 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_help(long nb)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_lng_itoa(nb);
	len = ft_putstr(str);
	if (len == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}

int	ft_putnb(int nb)
{
	return (ft_put_help(nb));
}

int	ft_putun_nb(unsigned int nb)
{
	return (ft_put_help(nb));
}

int	ft_hx_helper(unsigned long nb, char *base, int *res)
{
	if (nb < 16)
	{
		if (ft_putchar(base[nb]) == -1)
			return (-1);
		(*res)++;
	}
	else
	{
		ft_hx_helper(nb / 16, base, res);
		if (ft_putchar(base[nb % 16]) == -1)
			return (-1);
		(*res)++;
	}
	return (1);
}

int	ft_puthex(unsigned int nb, char c)
{
	char	*base_l;
	char	*base_u;
	int		res;

	base_u = "0123456789ABCDEF";
	base_l = "0123456789abcdef";
	res = 0;
	if (c == 'x')
	{
		if (ft_hx_helper(nb, base_l, &res) == -1)
			return (-1);
	}
	else
	{
		if (ft_hx_helper(nb, base_u, &res) == -1)
			return (-1);
	}
	return (res);
}
