/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:22:56 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/07 15:06:16 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

int	ft_putstr(char *s);
unsigned int	ft_putun_nb(unsigned int nb);
int	ft_putchar(char c);
int	ft_printf(char *form, ...);

#endif
