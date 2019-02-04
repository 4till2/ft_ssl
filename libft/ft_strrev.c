/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:55:47 by yserkez           #+#    #+#             */
/*   Updated: 2018/11/19 15:12:26 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_strrev(unsigned char *s, int len)
{
	unsigned char 	*ret;
	int 	j;

	j = 0;
	ret = ft_strnew(len);
	while ( --len >= 0)
		ret[j++] = s[len];
	return (ret);
}
