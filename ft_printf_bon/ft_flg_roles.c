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

void	ft_pars(char *form, int *i)
{
	t_flag	fl;
    int     flg[2];

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
    if (!form[*i])
    {
        if 
    }
}
