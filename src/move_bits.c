/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:11:15 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/13 17:55:36 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

uint32_t	rightrotate(uint32_t num, unsigned int rotation)
{
	rotation %= 31;
	while (rotation--)
	{
		num = (((num >> 1) & (~(1 << 31))) | ((num & 1) << 31));
	}
	return (num);
}

uint32_t	rightshift(uint32_t nbr, int i)
{
	return (nbr >> i);
}

uint32_t	leftrotate(uint32_t x, uint32_t c)
{
	return ((x << c) | (x >> (32 - c)));
}

void		swap_end_ptr(unsigned char *x)
{
	unsigned char	*px;
	unsigned char	temp;
	int				i;

	px = x;
	i = -1;
	while (++i < 4)
	{
		temp = px[i];
		px[i] = px[7 - i];
		px[7 - i] = temp;
	}
}
