/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:15:52 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/30 12:05:52 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	unsigned	int		i;
	long				ret;
	int					sign;

	i = 0;
	ret = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' ||
			str[i] == '\f' || str[i] == '\r'))
		i++;
	sign = (str[i] == '-' ? -1 : 1);
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		ret = (ret * 10 + (str[i++] - '0'));
	return (ret * sign);
}
