/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:22:56 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/13 15:50:24 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../ft_printf.h"

typedef struct s_flag
{
	int	alt;
	int	sign;
	int	space;
}		t_flag;

int		ft_printf(const char *form, ...);
int		implement_strct(const char *form, int *i, va_list *conver);
int		ft_set_nb_sign(va_list *conver, t_flag *strc);
int		ft_set_addrs_sign(va_list *conver, t_flag *strc, char type);
int		ft_set_alternative(va_list *conver, t_flag *strc, char type);

#endif
