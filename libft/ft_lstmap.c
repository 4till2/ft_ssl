/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:37:39 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/30 11:51:55 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list *current;
	t_list *end;
	t_list *front;

	front = NULL;
	while (lst && f)
	{
		if (!(end = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		end = f(lst);
		if (front == NULL)
		{
			front = end;
			current = end;
		}
		else
		{
			current->next = end;
			current = current->next;
		}
		lst = lst->next;
	}
	return (front);
}
