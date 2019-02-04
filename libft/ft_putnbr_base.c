/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 08:47:26 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/13 17:49:51 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long num, int base, int *count)
{
	unsigned long long unum;

	if (num < 0 && base == 10)
	{
		b_putchar('-', count);
		ft_putnbr_base(-num, base, count);
	}
	else
	{
		if (num >= base)
			ft_putnbr_base((num / base), base, count);
		unum = (unsigned long long)num;
		if ((unum % base) >= 10)
			b_putchar(((unum % base) - 10 + 'a'), count);
		else
			b_putchar(((unum % base) + '0'), count);
	}
}
