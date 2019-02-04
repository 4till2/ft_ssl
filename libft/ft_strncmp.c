/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:28:09 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/29 21:51:53 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && (i < n - 1))
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
