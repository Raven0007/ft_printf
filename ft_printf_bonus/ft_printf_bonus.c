/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:47:57 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/13 17:00:26 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_traverse(const char *form, va_list *args)
{
	int	flg[2];
	int	i;

	flg[0] = 0;
	i = 0;
	while (form[i])
	{
		if (form[i] == '%')
		{
			i++;
			flg[1] = implement_strct(form, &i, args);
		}
		else
			flg[1] = ft_putchar(form[i]);
		if (flg[1] == -1)
			return (-1);
		flg[0] += flg[1];
		i++;
	}
	return (flg[0]);
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		res;

	if (!form)
		return (-1);
	va_start(args, form);
	res = ft_traverse(form, &args);
	if (res == -1)
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (res);
}
/*
 * flg is array contains two indecators
 *flg[1] by defalut = 0, if called ft returns -1 ,
 * then ft_printf gonna return -1, else
 * will assgine to flg[0] which means nb of bytes printed
 */
