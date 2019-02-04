/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:46:29 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/30 11:53:39 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			++count;
		}
		if (*s == c && i == 1)
			i = 0;
		++s;
	}
	return (count);
}

static int	ft_wlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s && *s != c)
	{
		++len;
		++s;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		word;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	word = ft_wcount(s, c);
	if (!(ret = (char**)malloc(sizeof(*ret) * (word + 1))))
		return (NULL);
	while (word > 0)
	{
		while (*s == c && *s)
			++s;
		ret[i] = ft_strsub(s, 0, ft_wlen(s, c));
		if (!ret[i])
			return (NULL);
		s = s + ft_wlen(s, c);
		++i;
		--word;
	}
	ret[i] = NULL;
	return (ret);
}
