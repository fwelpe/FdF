/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:20:35 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/06 14:44:59 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	if (!(temp = ft_lstnew(lst->content, lst->content_size)))
	{
		ft_lstdelone(&temp, ft_lstdel_fn);
		return (NULL);
	}
	if (!(temp = f(temp)))
		return (NULL);
	result = temp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(temp->next = ft_lstnew(lst->content, lst->content_size)))
		{
			ft_lstdel(&result, ft_lstdel_fn);
			return (NULL);
		}
		temp->next = f(temp->next);
		temp = temp->next;
	}
	return (result);
}
