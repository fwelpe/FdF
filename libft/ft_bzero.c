/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:39:35 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 14:49:29 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tmptr;

	i = 0;
	tmptr = (unsigned char*)s;
	while (i < n)
	{
		*tmptr = 0;
		tmptr++;
		i++;
	}
}
