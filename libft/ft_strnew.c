/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:22:40 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/01/13 19:56:30 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * ++size);
	if (!p)
		return (NULL);
	while (size)
		p[--size] = '\0';
	return (p);
}
