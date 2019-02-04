/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_md5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:31:00 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/13 18:00:33 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

uint32_t g_inits[4] = {
	0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476
};

uint32_t g_md5[4];

uint32_t g_s_md5[64] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

uint32_t g_k_md5[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

uint32_t	to_int(char *s)
{
	uint32_t	ret;
	uint32_t	i;
	uint32_t	tmp;

	ret = 0;
	i = 0;
	while (i < 4)
	{
		tmp = 0 | s[i];
		tmp = tmp << (i * 8);
		ret = ret | tmp;
		++i;
	}
	return (ret);
}

void		decode(uint32_t input[])
{
	int i;

	i = -1;
	while (input[++i])
	{
		input[i] = ((input[i] >> 24) & 0xff) |
		((input[i] << 8) & 0xff0000) |
		((input[i] >> 8) & 0xff00) |
		((input[i] << 24) & 0xff000000);
	}
}

int			md5_rotate(uint32_t val[], uint32_t *tmp, int i)
{
	int g;

	g = 0;
	if (i < 16)
	{
		*tmp = (val[1] & val[2]) | ((~val[1]) & val[3]);
		g = i;
	}
	else if (i >= 16 && i < 32)
	{
		*tmp = (val[3] & val[1]) | ((~val[3]) & val[2]);
		g = (5 * i + 1) % 16;
	}
	else if (i >= 32 && i < 48)
	{
		*tmp = val[1] ^ val[2] ^ val[3];
		g = (3 * i + 5) % 16;
	}
	else if (i >= 48 && i < 64)
	{
		*tmp = val[2] ^ (val[1] | (~val[3]));
		g = (7 * i) % 16;
	}
	return (g);
}

void		hash_md5(unsigned char *block)
{
	uint32_t val[4];
	uint32_t i;
	uint32_t tmp;
	uint32_t g;
	uint32_t *pieces;

	i = 0;
	init_val(val, g_md5, 4);
	pieces = (uint32_t*)block;
	while (i < 64)
	{
		g = md5_rotate(val, &tmp, i);
		tmp = tmp + val[0] + g_k_md5[i] + pieces[g];
		val[0] = val[3];
		val[3] = val[2];
		val[2] = val[1];
		val[1] = val[1] + leftrotate(tmp, g_s_md5[i]);
		++i;
	}
	update_gvals(val, g_md5, 4);
}

uint32_t	*f_md5(unsigned char *m, int mlen)
{
	int				i;
	unsigned char	*tmp;

	i = 0;
	tmp = ft_strnew(64);
	init_gvals(g_md5, g_inits, 4);
	while (i < (mlen / 8))
	{
		ft_memcpy(tmp, &m[i], 64);
		hash_md5(tmp);
		i += 64;
	}
	free(tmp);
	free(m);
	decode(g_md5);
	return (g_md5);
}
