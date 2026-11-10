/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lng_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 15:17:22 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/09 11:34:31 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(long n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_imp(char *str, int count, int sign, long n)
{
	str[count--] = '\0';
	while (count > 0)
	{
		str[count--] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == 1)
		str[0] = '-';
	else
		str[0] = (n % 10) + '0';
	return (str);
}

char	*ft_lng_itoa(long nb)
{
	char	*str;
	int		var[2];

	var[1] = 0;
	if (nb < 0)
	{
		var[1] = 1;
		nb = -nb;
	}
	var[0] = ft_count(nb) + var[1];
	str = malloc(var[0] * sizeof(char) + 1);
	if (!str)
		return (NULL);
	return (ft_imp(str, var[0], var[1], nb));
}
/*
 * var[1] represent the sign flag by default it set to 0 (post)
 * var[0] used to count nb of bytes must allocate var[1] count if (negtv)
 */