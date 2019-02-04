/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sha256.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:33:13 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/13 17:55:20 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

uint32_t g_init[8] = {
	0x6a09e667, 0xbb67ae85, 0x3c6ef372,
	0xa54ff53a, 0x510e527f, 0x9b05688c,
	0x1f83d9ab, 0x5be0cd19
};

uint32_t g_sha256[8];

uint32_t g_k_sha[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void		fill_chunks(unsigned char *message, uint32_t **w)
{
	int	i;
	int offset;

	i = -1;
	offset = 0;
	while (++i < 16)
	{
		(*w)[i] = (uint32_t)(uint8_t)message[offset + 3] |
		((uint32_t)(uint8_t)message[offset + 2] << 8) |
		((uint32_t)(uint8_t)message[offset + 1] << 16) |
		((uint32_t)(uint8_t)message[offset] << 24);
		offset += 4;
	}
}

void		compress(uint32_t **w, uint32_t s[])
{
	uint32_t	val[8];
	int			i;
	uint32_t	ch;
	uint32_t	maj;
	uint32_t	temp[2];

	init_val(val, g_sha256, 8);
	i = -1;
	while (++i < 64)
	{
		s[1] = rightrotate(val[4], 6) ^ rightrotate(val[4], 11) ^
			rightrotate(val[4], 25);
		ch = (val[4] & val[5]) ^ ((~val[4]) & val[6]);
		temp[0] = val[7] + s[1] + ch + g_k_sha[i] + (*w)[i];
		s[0] = rightrotate(val[0], 2) ^ rightrotate(val[0], 13) ^
			rightrotate(val[0], 22);
		maj = (val[0] & val[1]) ^ (val[0] & val[2]) ^ (val[1] & val[2]);
		temp[1] = s[0] + maj;
		update_val(val, temp);
	}
	update_gvals(val, g_sha256, 8);
}

void		rotate(uint32_t **w, uint32_t s[2])
{
	int			i;

	i = 15;
	while (++i < 64)
	{
		s[0] = rightrotate((*w)[i - 15], 7) ^ rightrotate((*w)[i - 15], 18) ^
			rightshift((*w)[i - 15], 3);
		s[1] = rightrotate((*w)[i - 2], 17) ^ rightrotate((*w)[i - 2], 19) ^
			rightshift((*w)[i - 2], 10);
		(*w)[i] = (*w)[i - 16] + s[0] + (*w)[i - 7] + s[1];
	}
}

void		hash_sha256(unsigned char *block)
{
	uint32_t	*w;
	uint32_t	s[2];

	w = ft_memalloc(sizeof(uint32_t) * 65);
	fill_chunks(block, &w);
	rotate(&w, s);
	compress(&w, s);
	free(w);
}

uint32_t	*f_sha256(unsigned char *m, int mlen)
{
	int				i;
	unsigned char	*tmp;

	i = 0;
	tmp = ft_strnew(64);
	init_gvals(g_sha256, g_init, 8);
	while (i < (mlen / 8))
	{
		ft_memcpy(tmp, &m[i], 64);
		hash_sha256(tmp);
		i += 64;
	}
	free(tmp);
	free(m);
	return (g_sha256);
}
