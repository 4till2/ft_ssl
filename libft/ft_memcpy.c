/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:46:23 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/30 12:04:00 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*ptr1;
	const unsigned char		*ptr2;

	ptr1 = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	while (n-- > 0)
		*(ptr1++) = *(ptr2++);
	return (dst);
}
