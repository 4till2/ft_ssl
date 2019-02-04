/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:41:56 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/13 17:58:18 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	init_gvals(uint32_t g_x[], uint32_t inits[], int len)
{
	int i;

	i = -1;
	while (++i < len)
		g_x[i] = inits[i];
}

void	init_val(uint32_t val[], uint32_t g_x[], int len)
{
	int i;

	i = -1;
	while (++i < len)
		val[i] = g_x[i];
}

void	update_val(uint32_t val[], uint32_t temp[])
{
	val[7] = val[6];
	val[6] = val[5];
	val[5] = val[4];
	val[4] = val[3] + temp[0];
	val[3] = val[2];
	val[2] = val[1];
	val[1] = val[0];
	val[0] = temp[0] + temp[1];
}

void	update_gvals(uint32_t val[], uint32_t g_x[], int len)
{
	int i;

	i = -1;
	while (++i < len)
		g_x[i] = g_x[i] + val[i];
}
