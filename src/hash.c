/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 10:22:24 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/13 21:39:15 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

char	*read_file(int fd)
{
	char	*buf;
	char	*tmp;
	char	*msg;
	int		ret;

	msg = NULL;
	buf = (char*)ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!msg)
			msg = ft_strdup(buf);
		else
		{
			tmp = msg;
			msg = ft_strjoin(msg, buf);
			free(tmp);
		}
		ft_strclr(buf);
	}
	if (!msg && ret >= 0)
		msg = ft_strdup("\0");
	free(buf);
	return (msg);
}

void	hash_functions(uint32_t *(**h)(unsigned char *m, int mlen))
{
	h[MD5] = f_md5;
	h[SHA256] = f_sha256;
}

void	hash_file(char *arg, int flags, int hash)
{
	unsigned char	*msg;
	char			*tmp;
	int				mlen;
	uint32_t		*(*h[MAX_HASH])(unsigned char *m, int mlen);
	int				fd;

	hash_functions(h);
	if ((fd = open(arg, O_RDONLY)) != -1)
	{
		if ((tmp = read_file(fd)) == NULL)
		{
			print_error(FILE_ERR, arg, hash);
			return ;
		}
		msg = pad_str(tmp, &mlen, hash);
		print_hash(arg, h[(int)hash](msg, mlen), flags, hash);
	}
	else
		print_error(FILE_ERR, arg, hash);
}

void	hash_string(char *arg, int flags, int hash)
{
	unsigned char	*msg;
	int				mlen;
	uint32_t		*(*h[MAX_HASH])(unsigned char *m, int mlen);

	hash_functions(h);
	msg = pad_str(arg, &mlen, hash);
	print_hash(arg, h[(int)hash](msg, mlen), flags, hash);
}

void	hash_input(int flags, int hash)
{
	unsigned char	*msg;
	char			*tmp;
	int				mlen;
	uint32_t		*(*h[MAX_HASH])(unsigned char *m, int mlen);

	hash_functions(h);
	tmp = read_file(0);
	msg = pad_str(tmp, &mlen, hash);
	print_hash(tmp, h[(int)hash](msg, mlen), flags, hash);
}
