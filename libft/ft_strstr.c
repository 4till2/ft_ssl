/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:50:55 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/30 11:55:29 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	ptr;
	int i;

	if (!(*needle))
		return ((char*)haystack);
	ptr = 0;
	while (haystack[ptr])
	{
		if (haystack[ptr] == needle[0])
		{
			i = 1;
			while (needle[i] && haystack[ptr + i] == needle[i])
				i++;
			if (!needle[i])
				return ((char*)&haystack[ptr]);
		}
		++ptr;
	}
	return (NULL);
}
