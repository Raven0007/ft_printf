/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flg_roles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:05:28 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/11 15:09:08 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static int	ft_put_qualif(char type, va_list conver)
{
	if (type == 'c')
		return (ft_putchar(va_arg(conver, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(conver, char *)));
	else if (type == 'u')
		return (ft_putun_nb(va_arg(conver, unsigned int)));
	else
		return (ft_putchar('%'));
}

static int	ft_check_flg(char c)
{
	if (c == '#' || c == '+' || c == ' ')
		return (1);
	return (0);
}

static void	ft_set_strct(t_flag *strc)
{
	strc->alt = 0;
	strc->sign = 0;
	strc->space = 0;
}

static int	ft_check_qualif(char type, va_list conver, t_flag *strc)
{
	if (type == 'd' || type == 'i')
		return (ft_set_nb_sign(conver, strc));
	else if (type == 'p')
		return (ft_set_addrs_sign(conver, strc, type));
	else if ((type == 'x' || type == 'X'))
		return (ft_set_alternative(conver, strc, type));
	else
		return (ft_put_qualif(type, conver));
}

int	implement_strct(const char *form, int *i, va_list conver)
{
	t_flag	strc;

	ft_set_strct(&strc);
	while (form[*i] && ft_check_flg(form[*i]))
	{
		if (form[*i] == '+')
			strc.sign = 1;
		else if (form[*i] == '#')
			strc.alt = 1;
		else if (form[*i] == ' ')
			strc.space = 1;
		*i += 1;
	}
	return (ft_check_qualif(form[*i], conver, &strc));
}
