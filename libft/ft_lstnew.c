/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:10:00 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/06 12:45:50 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l;

	if (!(l = (t_list*)malloc(sizeof(*l))))
		return (NULL);
	if (!content)
	{
		l->content = NULL;
		l->content_size = 0;
	}
	else
	{
		if (!(l->content = malloc(content_size)))
		{
			free(l);
			return (NULL);
		}
		ft_memcpy(l->content, content, content_size);
		l->content_size = content_size;
	}
	l->next = NULL;
	return (l);
}
