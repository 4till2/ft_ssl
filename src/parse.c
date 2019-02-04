/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 09:50:50 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/13 21:46:19 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int		g_flag = 0;

void	set_flag(char flag)
{
	if (flag == 'q')
		g_flag = g_flag | 00000001;
	else if (flag == 'r')
		g_flag = g_flag | 00000010;
	else if (flag == 'p')
		g_flag = g_flag | 00000100;
	else if (flag == 's')
		g_flag = g_flag | 00001000;
	else if (flag == 'x')
		g_flag = g_flag | 00010000;
}

void	unset_flag(char flag)
{
	if (flag == 'q')
		g_flag = g_flag ^ 00000001;
	else if (flag == 'r')
		g_flag = g_flag ^ 00000010;
	else if (flag == 'p')
		g_flag = g_flag ^ 00000100;
	else if (flag == 's')
		g_flag = g_flag ^ 00001000;
}

int		is_flag(char flag)
{
	if (flag == 'q')
		return (g_flag & 00000001);
	if (flag == 'r')
		return (g_flag & 00000010);
	if (flag == 'p')
		return (g_flag & 00000100);
	if (flag == 's')
		return (g_flag & 00001000);
	if (flag == 'x')
		return (g_flag & 00010000);
	return (0);
}

void	handle_flags(char *arg, int hash)
{
	if (!arg[0])
		return ;
	if (arg[0] == 's')
		arg[1] ? hash_string(&arg[1], g_flag, hash) : set_flag('s');
	else if (arg[0] == 'q')
	{
		set_flag('q');
		handle_flags(&arg[1], hash);
	}
	else if (arg[0] == 'r')
	{
		set_flag('r');
		handle_flags(&arg[1], hash);
	}
	else if (arg[0] == 'p')
	{
		set_flag('p');
		hash_input(g_flag, hash);
		handle_flags(&arg[1], hash);
	}
	else
		print_error(FLAG_ERR, arg, hash);
}

void	parse(char **args, int hash)
{
	int i;

	i = -1;
	if (!args[0])
	{
		set_flag('q');
		hash_input(g_flag, hash);
	}
	while (args[++i])
	{
		is_flag('p') ? unset_flag('p') : 0;
		is_flag('s') ? unset_flag('s') : 0;
		if (args[i][0] == '-' && !is_flag('x'))
		{
			handle_flags(&args[i][1], hash);
			is_flag('s') ? hash_string(args[++i], g_flag, hash) : 0;
		}
		else
		{
			hash_file(args[i], g_flag, hash);
			set_flag('x');
		}
		b_printf("\n");
	}
}
