/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flg_roles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:05:28 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/10 18:05:33 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	void set_strct(t_flag *strc)
{
	strc->alt = 0;
	strc->sign = 0;
	strc->space = 0;
}

void	ft_pars(char *form, int *i, va_list conver)
{
	t_flag	fl;
	int	res;
	int	nb;

	ft_set_strct(&fl);
	while (form[*i] && ft_check(form[*i]))
	{
		if (form[*i] == '+')
			strc.sign = 1;
		else if (form[*i] == '#')
			strc.alt = 1;
		else if (form[*i] == ' ')
			strc.space = 1;
	}
	*(i++);
	res[0] = 0;
	if (!form[*i])
	{
		if (form[*i] == 'd' || form [*i] == 'i')
		{
			nb = va_arg(conver, int)
			if (nb >= 0 && (strc.sign || strc.space))
			{
				if (strc.sign == 1)
					if (ft_putstr("+") == -1)
						return (-1);
				else
					if (ft_putstr(" ") == -1)
						return (-1);
				res[0] = 1
			}
			return (ft_putnb(nb) + res);
		}
		else if (form[*i] == 'p')
		{
			add = va_arg(conver, int)
			if ((strc.sign || strc.space) && !add)
			{
				if (strc.sign == 1)
					if (ft_putstr("+") == -1)
						return (-1);
				else
					if (ft_putstr(" ") == -1)
						return (-1);
				res[0] = 1;
			}
			return (ft_put_hex(add) + res);
		}
		else if ((form[*i] == 'x' || form[*i] == 'X') && strc.alt)
		{

		}
}
