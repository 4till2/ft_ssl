/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:15:57 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/30 11:51:09 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	i = 0;
	if (ptr2 < ptr1)
	{
		while (++i <= len)
			ptr1[len - i] = ptr2[len - i];
	}
	else
	{
		while (len-- > 0)
			*(ptr1++) = *(ptr2++);
	}
	return (dst);
}
