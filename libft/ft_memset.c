/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:17:31 by yserkez           #+#    #+#             */
/*   Updated: 2018/09/14 15:11:16 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ch;
	size_t			i;

	ch = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		ch[i++] = (unsigned char)c;
	}
	return (b);
}
