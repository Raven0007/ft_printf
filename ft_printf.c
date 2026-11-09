/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:47:57 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/09 15:53:07 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static	void ft_qualif(char type, va_list conver)
{
	if (type == 'c')
		return (ft_putchar(va_arg(conver, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(conver, char *)));
	else if (type == 'd' || 'i')
		return (ft_putnb(va_arg(conver, int)));
	else if (type == 'u')
		return (ft_putun_nb(va_arg(conver, unsigned int)));
	else if (type == 'x' || 'X')
		return (ft_puHex(va_arg(conver, unsigned int), type));	
	else if (type == 'p')
		return (ft_putadd(va_arg(conver, void *)));
	else
		return (ft_putcahr(type));
}

int	ft_printf(char *form, ...)
{
	va_list	args;
	char	*str;
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
			flg[1] = ft_qualif(form[i++], args);
		if (flg[1] == -1)
			return (-1);
		flg[0] += flg[1];
	}	
	va_end(args);
	return (flg[0]);
}

int	main()
{
	ft_printf("Print this : %s : ", "Hello", "Hola","Parla", "");
}
/*
 * The variable flag used here to check ft_qualif returns
 * if it was diffrent than -1 so gonna consider this value as
 * number of printed characters 
 */
