/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:01:59 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 14:51:27 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	char	*crwr;

	crwr = (char*)s;
	while (*crwr != (char)c)
	{
		if (!(*crwr))
			return (NULL);
		crwr++;
	}
	return (crwr);
}
