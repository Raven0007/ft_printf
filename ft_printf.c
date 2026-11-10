/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:47:57 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/10 16:41:32 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_qualif(char type, va_list conver)
{
	if (type == 'c')
		return (ft_putchar(va_arg(conver, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(conver, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnb(va_arg(conver, int)));
	else if (type == 'u')
		return (ft_putun_nb(va_arg(conver, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_put_hex(va_arg(conver, unsigned int), type));
	else if (type == 'p')
		return (ft_putadd(va_arg(conver, void *)));
	else
		return (ft_putchar('%'));
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		flg[2];
	int		i;

	if (!form)
		return (-1);
	va_start(args, form);
	flg[0] = 0;
	i = 0;
	while (form[i])
	{
		if (form[i] == '%')
		{
			flg[1] = ft_qualif(form[++i], args);
			i++;
		}
		else
			flg[1] = ft_putchar(form[i++]);
		if (flg[1] == -1)
			return (-1);
		flg[0] += flg[1];
	}
	va_end(args);
	return (flg[0]);
}
/*
 * The variable flag used here to check ft_qualif returns
 * if it was diffrent than -1 so gonna consider this value as
 * number of printed characters and stored on flg[0]
 */
