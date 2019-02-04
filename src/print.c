/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 10:28:58 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/13 21:37:14 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

char	*put_hash(int hash)
{
	if (hash == MD5)
		return ("md5");
	else if (hash == SHA256)
		return ("sha256");
	return (NULL);
}

void	print_error(int err, char *arg, int hash)
{
	if (err == FLAG_ERR)
	{
		b_printf("%s: illegal option -- %s\n", put_hash(hash), arg);
		b_printf("usage: %s [-pqr] [-s string] [files ...]", put_hash(hash));
	}
	if (err == FILE_ERR)
		b_printf("%s: %s: %s", put_hash(hash), arg, strerror(errno));
}

void	output_hash(uint32_t g_x[])
{
	int i;

	i = -1;
	while (g_x[++i])
		b_printf("%x", g_x[i]);
}

void	print_hash(char *arg, uint32_t g_x[], int flags, int hash)
{
	flags = 0;
	if (is_flag('q'))
		output_hash(g_x);
	else if (is_flag('r'))
	{
		output_hash(g_x);
		b_printf(" %s", arg);
	}
	else if (is_flag('p'))
	{
		b_printf("%s", arg);
		output_hash(g_x);
	}
	else
	{
		if (hash == MD5)
			b_printf("MD5 (%s) = ", arg);
		else if (hash == SHA256)
			b_printf("SHA256 (%s) = ", arg);
		output_hash(g_x);
	}
}
