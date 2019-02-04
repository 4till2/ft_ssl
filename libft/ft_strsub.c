/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:16:57 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/30 11:44:55 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
		ret[i++] = (char)s[start++];
	ret[i] = '\0';
	return (ret);
}
