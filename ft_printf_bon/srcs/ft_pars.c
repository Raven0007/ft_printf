/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:41:31 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/10 15:40:46 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_alt(char type, va_list conver)
{
	int	res;

	if (type == 'x')
		if (ft_putstr("0x") == -1)
			return (-1);
	else if (type == 'X')
		if (ft_putstr("0X") == -1)
			return (-1);
	res = ft_putHex(va_arg(conver, unsigned int), type);
		if (res == -1)
			return (-1);
		return (res + 2);
}

int	ft_put_sp_sgn(char type, char flg, va_list conver)
{
	int	res;
	int	nb;

	if (flg == '+' && (type == 'd' || type == ))
}

