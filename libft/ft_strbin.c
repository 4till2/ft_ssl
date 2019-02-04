/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:16:30 by yserkez           #+#    #+#             */
/*   Updated: 2018/11/19 13:35:29 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strbin(char *s, int len)
{
	int i;
	int k;
	int ret;

	k = 0;
	ret = 0;
	while (k < len)
	{
		i = 7;
		while (i >= 0)
		{
			++ret;
			ft_putchar((s[k] & (1 << i)) ? '1' : '0');
			--i;
		}
		ft_putchar(' ');
		++k;
	}
	ft_putchar('\n');
	return (ret);
}
