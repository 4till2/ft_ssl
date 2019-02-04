/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:50:55 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/29 21:40:21 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char *ptr2;

	if (n == 0)
		return (0);
	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	while (--n > 0 && *ptr1 == *ptr2)
	{
		ptr1++;
		ptr2++;
	}
	return ((int)(*ptr1 - *ptr2));
}
