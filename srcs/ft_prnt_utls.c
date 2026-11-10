/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_utls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:13:03 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/09 11:47:40 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	ln;

	if (!str)
		str = "(null)";
	ln = 0;
	while (str[ln])
	{
		if (ft_putchar(str[ln]) == -1)
			return (-1);
		ln++;
	}
	return (ln);
}
