/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:22:41 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/27 17:17:28 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_strnew(size_t size)
{
	unsigned char	*ret;

	if (!(ret = (unsigned char*)malloc(sizeof(unsigned char) * size + 1)))
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
