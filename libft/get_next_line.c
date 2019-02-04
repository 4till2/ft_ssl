/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:42:39 by yserkez           #+#    #+#             */
/*   Updated: 2018/11/01 10:49:11 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	add_next_line(char **statstr, char **line)
{
	char	*ptr;

	if (ft_strchr(*statstr, '\n') != NULL)
	{
		ptr = *statstr;
		*line = ft_strsub(*statstr, 0, ft_strchr(*statstr, '\n') - *statstr);
		*statstr = ft_strdup(ft_strchr(*statstr, '\n') + 1);
		free(ptr);
		return (1);
	}
	else if (**statstr != '\0')
	{
		ptr = *statstr;
		*line = ft_strdup(*statstr);
		*statstr = ft_strdup("\0");
		free(ptr);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char		*buf;
	static char *statstr[54139];
	int			red;
	char		*ptr;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	buf = (char*)ft_strnew(BUFF_SIZE);
	while ((red = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!statstr[fd])
			statstr[fd] = ft_strdup(buf);
		else
		{
			ptr = statstr[fd];
			statstr[fd] = ft_strjoin(statstr[fd], buf);
			free(ptr);
		}
		ft_strclr(buf);
		if (ft_strchr(statstr[fd], '\n'))
			break ;
	}
	free(buf);
	return (red < 0 ? (-1) : (add_next_line(&statstr[fd], line)));
}
