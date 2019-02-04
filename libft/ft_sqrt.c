/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:25:56 by yserkez           #+#    #+#             */
/*   Updated: 2018/11/09 17:28:43 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_sqrt(long long n)
{
	long long low;
	long long mid;
	long long high;

	low = 0;
	high = n + 1;
	while (high - low > 1)
	{
		mid = (low + high) / 2;
		if (mid * mid <= n)
			low = mid;
		else
			high = mid;
	}
	return (low);
}
