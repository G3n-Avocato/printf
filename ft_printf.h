/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:31:10 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/31 21:49:48 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_putchar_rec(char c);
int	ft_putnbr_rec(int n);
int	ft_putstr_rec(char *s);
int	ft_putnbr_base(unsigned long long n, char *base);
int	ft_printf(const char *str, ...);

#endif
