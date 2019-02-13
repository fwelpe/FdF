/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:53:02 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 14:50:14 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*p;

	p = (unsigned char *)malloc(size);
	if (!p)
		return (NULL);
	while (size)
		p[--size] = 0;
	return (void*)p;
}
