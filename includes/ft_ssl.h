/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:22:28 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/13 21:34:57 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_SSL_H
# define _FT_SSL_H

# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# define MD5 0
# define SHA256 1
# define MAX_HASH 2
# define BUFF_SIZE 4242
# define FLAG_ERR 1
# define FILE_ERR 2 
# define DIRECTORY_ERR 3
# define PERMISSION_ERR 4 


void			print_hash(char *arg, uint32_t g_x[], int flags, int hash);
void			parse(char **args, int hash);
unsigned char	*pad_str(char *str, int *mlen, int hash);
int				is_flag(char flag);
void			print_error(int err, char *arg, int hash);
void			hash_file(char *arg, int flag, int hash);
void			hash_string(char *arg, int flag, int hash);
void			hash_input(int flag, int hash);
uint32_t		*f_md5(unsigned char *m, int  mlen);
uint32_t		*f_sha256(unsigned char *m, int mlen);
uint32_t		leftrotate(uint32_t x, uint32_t c);
uint32_t		rightshift(uint32_t nbr, int i);
uint32_t		rightrotate(uint32_t num, unsigned int rotation);
void			init_gvals(uint32_t g_x[], uint32_t inits[], int len);
void			init_val(uint32_t val[], uint32_t g_x[], int len);
void			update_val(uint32_t val[], uint32_t temp[]);
void			update_gvals(uint32_t val[], uint32_t g_x[], int len);
void			swap_end_ptr(unsigned char *x);
#endif
