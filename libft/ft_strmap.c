/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:15:32 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/30 11:46:11 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr1;
	char	*ptr2;
	char	*ret;

	if (!s || !(ret = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
		return (NULL);
	ptr1 = ret;
	ptr2 = (char*)s;
	while (*ptr2)
		*(ptr1++) = f(*(ptr2++));
	*ptr1 = '\0';
	return (ret);
}
