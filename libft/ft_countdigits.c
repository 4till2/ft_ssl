/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:45:02 by yserkez           #+#    #+#             */
/*   Updated: 2018/11/17 14:54:06 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countdigits(long long nb, unsigned int base)
{
	int i;

	i = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	while (nb / base > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}
