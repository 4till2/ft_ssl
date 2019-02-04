/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:49:01 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/13 17:50:54 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
void				b_putstr(char *s, int *count);
void				b_putchar(int c, int *count);
void				ft_putnbr_base(long long num, int base, int *count);
int					b_printf(const char *restrict format, ...);
unsigned char		*ft_strrev(unsigned char *s, int len);
int					ft_strbin(char *s, int len);
int					get_next_line(const int fd, char **line);
void				ft_putstr_newline(char const *s);
char				*ft_itoa_base(long long n, int base);
long long			ft_sqrt(long long n);
int					get_next_line(const int fd, char **line);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_countdigits(long long nb, unsigned int base);
unsigned	int		ft_nbrsize(int n);
int					ft_iswhite(char const c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
unsigned char		*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
unsigned char		*ft_strand(unsigned char *s1, const char c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void	*dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(char *str);
void				ft_putnbr(int nb);
void				ft_putstr(char *s);
void				ft_putchar(int c);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
unsigned char		*ft_strcpy(unsigned char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isdigit(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
#endif
