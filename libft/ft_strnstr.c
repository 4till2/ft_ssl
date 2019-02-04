/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:50:55 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/30 11:45:24 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < n)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && haystack[i + j] && i + j < n)
			{
				if (haystack[i + j] == needle[j])
					j++;
				else
					break ;
			}
			if (needle[j] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
