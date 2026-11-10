/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:11:55 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/09 17:12:01 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putadd(void *add)
{
    unsigned long   nb;
    int             res;
    int             fl;

    nb = (unsigned long)add;
    if (!add)
    {
        if (ft_putstr("(nil)") == -1)
            return (-1);
        return (5);
    }
    if (ft_putstr("0x") == -1)
        return (-1);
    res = 2;
    fl = ft_Hx_helper(nb, "0123456789abcdef", &res);
    if (fl == -1)
        return (-1);
    return (res);
}