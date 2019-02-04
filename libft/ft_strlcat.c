/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:50:55 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/30 11:50:32 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;
	size_t	j;

	i = 0;
	ret = 0;
	j = 0;
	if (dstsize < 1)
		return (ft_strlen(dst));
	while (dst[i])
		++i;
	while (src[ret])
		++ret;
	if (dstsize <= i)
		ret += dstsize;
	else
		ret += i;
	while (src[j] && (i < (dstsize - 1)))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ret);
}
