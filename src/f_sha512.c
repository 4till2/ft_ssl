/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sha256.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:33:13 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/13 22:19:43 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

uint64_t g_init[8] = {
	0xc1059ed8, 0x367cd507, 0x3070dd17,
	0xf70e5939, 0xffc00b31, 0x68581511,
	0x64f98fa7, 0xbefa4fa4
};

uint64_t g_sha512[8];

uint64_t g_k_sha[64] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 0x3956c25bf348b538, 
	0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242, 0x12835b0145706fbe, 
	0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2, 0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 
	0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5, 0x983e5152ee66dfab, 
	0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725, 
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 
	0x53380d139d95b3df, 0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b, 
	0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218, 
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8, 0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 
	0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 
	0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec, 
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b, 0xca273eceea26619c, 
	0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba, 0x0a637dc5a2c898a6, 
	0x113f9804bef90dae, 0x1b710b35131c471b, 0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

void		fill_chunks_512(unsigned char *message, uint64_t **w)
{
	int	i;
	int offset;

	i = -1;
	offset = 0;
	while (++i < 16)
	{
		(*w)[i] = (uint64_t)(uint8_t)message[offset + 3] |
		((uint64_t)(uint8_t)message[offset + 2] << 8) |
		((uint64_t)(uint8_t)message[offset + 1] << 16) |
		((uint64_t)(uint8_t)message[offset] << 24);
		offset += 4;
	}
}

void		compress_512(uint64_t **w, uint64_t s[])
{
	uint64_t	val[8];
	int			i;
	uint64_t	ch;
	uint64_t	maj;
	uint64_t	temp[2];

	init_val(val, g_sha512, 8);
	i = -1;
	while (++i < 80)
	{
		s[1] = rightrotate(val[4], 14) ^ rightrotate(val[4], 18) ^
			rightrotate(val[4], 41);
		ch = (val[4] & val[5]) ^ ((~val[4]) & val[6]);
		temp[0] = val[7] + s[1] + ch + g_k_sha[i] + (*w)[i];
		s[0] = rightrotate(val[0], 28) ^ rightrotate(val[0], 34) ^
			rightrotate(val[0], 39);
		maj = (val[0] & val[1]) ^ (val[0] & val[2]) ^ (val[1] & val[2]);
		temp[1] = s[0] + maj;
		update_val(val, temp);
	}
	update_gvals(val, g_sha512, 8);
}

void		rotate_512(uint64_t **w, uint64_t s[2])
{
	int			i;

	i = 15;
	while (++i < 80)
	{
		s[0] = rightrotate((*w)[i - 15], 1) ^ rightrotate((*w)[i - 15], 8) ^
			rightshift((*w)[i - 15], 7);
		s[1] = rightrotate((*w)[i - 2], 19) ^ rightrotate((*w)[i - 2], 61) ^
			rightshift((*w)[i - 2], 6);
		(*w)[i] = (*w)[i - 16] + s[0] + (*w)[i - 7] + s[1];
	}
}

void		hash_sha512(unsigned char *block)
{
	uint64_t	*w;
	uint64_t	s[2];

	w = ft_memalloc(sizeof(uint64_t) * 65);
	fill_chunks_512(block, &w);
	rotate_512(&w, s);
	compress_512(&w, s);
	free(w);
}

uint64_t	*f_sha512(unsigned char *m, int mlen)
{
	int				i;
	unsigned char	*tmp;

	i = 0;
	tmp = ft_strnew(64);
	init_gvals(g_sha256, g_init, 8);
	while (i < (mlen / 8))
	{
		ft_memcpy(tmp, &m[i], 64);
		hash_sha512(tmp);
		i += 64;
	}
	free(tmp);
	free(m);
	return (g_sha256);
}
