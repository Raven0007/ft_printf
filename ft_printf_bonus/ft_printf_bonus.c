/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:47:57 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/13 16:14:12 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
			flg[1] = (i++, implement_strct(form, &i, &args));
		else
			flg[1] = ft_putchar(form[i]);
		if (flg[1] == -1)
		{
			va_end(args);
			return (-1);
		}
		flg[0] += flg[1];
		i++;
	}
	va_end(args);
	return (flg[0]);
}
/*
 * The variable flag used here to check ft_qualif returns
 * if it was diffrent than -1 so gonna consider this value as
 * number of printed characters and stored on flg[0]
 */
