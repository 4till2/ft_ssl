/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:43:17 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/30 11:43:18 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (s1 == s2 ? 1 : 0);
	if (ft_strlen((char*)s1) != ft_strlen((char*)s2))
		return (0);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}
