/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:54:25 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/30 11:56:07 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned	char	*ptr1;
	unsigned	char	*ptr2;
	size_t				i;

	i = 0;
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		if (ptr1[i] == (unsigned char)c)
			return ((char*)(dst + i + 1));
		++i;
	}
	return (NULL);
}
