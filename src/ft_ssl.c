/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:25:05 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/13 18:16:58 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

unsigned char		*len_to_char(uint64_t len, int end)
{
	unsigned char	*ret;
	char			buf;
	int				i;

	ret = ft_strnew(8);
	i = 0;
	while (i++ < 8)
	{
		buf = 0;
		ret = ft_strand(ret, len | buf);
		len = len >> 8;
	}
	if (end == SHA256)
		swap_end_ptr(ret);
	return (ret);
}

unsigned char		*pad_str(char *str, int *mlen, int hash)
{
	uint64_t			olen;
	uint64_t			tlen;
	unsigned char		*ret;
	unsigned char		*tmp;

	olen = (uint64_t)ft_strlen(str) * 8;
	tlen = olen;
	while (++tlen % 512 != 448)
		;
	ret = ft_strnew(tlen / 8 + 8);
	ft_memset(ret, 0, tlen / 8);
	ft_strcpy(ret, str);
	ft_memset(ret + ft_strlen(str), 128, 1);
	tmp = len_to_char(olen, hash);
	ft_memcpy(ret + (tlen / 8), tmp, 8);
	free(tmp);
	*mlen = tlen + 64;
	return (ret);
}

int					get_hash(char *s)
{
	if (ft_strcmp(s, "md5") == 0)
		return (MD5);
	if (ft_strcmp(s, "sha256") == 0)
		return (SHA256);
	return (-1);
}

int					main(int argc, char **argv)
{
	int				start;
	int				hash;

	start = 0;
	hash = 0;
	if (argc > 1)
	{
		if ((hash = get_hash(argv[1])) < 0)
			return (-1);
		parse(&argv[2], hash);
	}
	return (0);
}
