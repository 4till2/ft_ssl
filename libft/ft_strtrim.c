/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:13:36 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/30 12:15:28 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char *s)
{
	int	size;
	int	i;

	i = -1;
	size = ft_strlen((char*)s);
	while (ft_iswhite(s[++i]))
		size--;
	if (size == 0)
		return (0);
	while (s[i])
		i++;
	while (ft_iswhite(s[--i]))
		size--;
	return (size);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		size;

	if (!s)
		return (NULL);
	size = ft_len((char*)s);
	i = 0;
	while (ft_iswhite(s[i]))
		i++;
	str = ft_strsub(s, i, size);
	return (str);
}
