/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:27:41 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/27 20:04:28 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static int	ft_add_p(va_list ap)
{
	unsigned long long	tmp;
	int	size;
	
	size = 0;
	tmp = va_arg(ap, unsigned long long);
	if (!tmp)
		size = ft_putstr_rec("(nil)");
	else
	{
		size = ft_putstr_rec("0x");
		size += ft_putnbr_base(tmp, "0123456789abcdef");
	}
	return (size);
}

static int	ft_others(char c)
{
	int	size;

	size = 0;
	size = ft_putchar_rec('%');
	size += ft_putchar_rec(c);
	return (size);
}

static int	ft_find_arg(const char c, va_list ap)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = ft_putchar_rec(va_arg(ap, int));
	else if (c == 's')
 		size = ft_putstr_rec(va_arg(ap, char *));
	else if (c == 'p')
		size = ft_add_p(ap);
	else if (c == 'd')
		size = ft_putnbr_rec(va_arg(ap, int));
	else if (c == 'i')
		size = ft_putnbr_rec(va_arg(ap, int));
	else if (c == 'u')
		size = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'x')
		size = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		size = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		size = ft_putchar_rec('%');
	else
		size = ft_others(c);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (!str)
		return (0);
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			size += ft_find_arg(str[i + 1], ap);
			i += 2;
		}
		else
		{
			size += ft_putchar_rec(str[i]);
			i++;
		}
	}
	va_end(ap);
	return (size);
}

#include <stdio.h>
int	main()
{
	char	c = '0';
	char	s[] = "La maison saucisse";
	int	d = 55;
	int	dd = -66;
	int	i = 22;
	int	ii = -22;
	int	u = 33;
	int	uu = -1;
	int	x = 42;
	int	X = 42;
	int	p = 10;

	ft_printf("%d\n", ft_printf("c = %c || s = %s || p = %p || d = %d || dd = %d || i = %i || ii = %i || u = %u || uu = %u || x = %x || X = %X || t = %%\n ", c, s, &p, d, dd, i, ii, u, uu, x, X));
	printf("%d\n", printf("c = %c || s = %s || p = %p || d = %d || dd = %d || i = %i || ii = %i || u = %u || uu = %u || x = %x || X = %X || t = %%\n ", c, s, &p, d, dd, i, ii, u, uu, x, X));
}

//taille printf chaine || retour int fonction bonne taille || calcul de i pr la size ds la fct principal
//fonction approprie pour chaque argument memoire + autres
//test debug de tt les possibilités
//Makefile .h
//norme
