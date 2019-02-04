/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:27:07 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/13 17:50:19 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printflag(char *traverse, va_list arg, int *count)
{
	if (*traverse == '%')
		b_putchar('%', count);
	else if (*traverse == 's')
		b_putstr(va_arg(arg, char *), count);
	else if (*traverse == 'c')
		b_putchar(va_arg(arg, int), count);
	else if (*traverse == 'i' || *traverse == 'd')
		ft_putnbr_base(va_arg(arg, int), 10, count);
	else if (*traverse == 'o')
		ft_putnbr_base(va_arg(arg, unsigned int), 8, count);
	else if (*traverse == 'x')
		ft_putnbr_base(va_arg(arg, unsigned int), 16, count);
	else if (*traverse == 'p')
	{
		b_putstr("0x", count);
		ft_putnbr_base((long long)va_arg(arg, void*), 16, count);
	}
	else if (*traverse == 'u')
		ft_putnbr_base(va_arg(arg, unsigned int), 10, count);
}

int				b_printf(const char *restrict format, ...)
{
	int		*count;
	char	*traverse;
	va_list	arg;
	int		c;

	c = 0;
	count = &c;
	va_start(arg, format);
	traverse = (char*)format;
	while (*traverse != '\0')
	{
		while (*traverse != '%' && *traverse != '\0')
		{
			b_putchar(*traverse, count);
			traverse++;
		}
		if (*traverse == '\0')
			break ;
		traverse++;
		ft_printflag(traverse, arg, count);
		traverse++;
	}
	va_end(arg);
	return (*count);
}
