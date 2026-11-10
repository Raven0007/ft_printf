/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:22:56 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/10 16:39:16 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *form, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
char	*ft_lng_itoa(long nb);
int		ft_putadd(void *add);
int		ft_put_hex(unsigned int nb, char c);
int		ft_hx_helper(unsigned long nb, char *base, int *res);
int		ft_putun_nb(unsigned int nb);
int		ft_putnb(int nb);

#endif
