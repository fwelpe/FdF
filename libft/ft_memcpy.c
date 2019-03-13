/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:42:19 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 14:50:36 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_iter;
	unsigned char	*src_iter;

	dst_iter = (unsigned char*)dst;
	src_iter = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		*dst_iter = *src_iter;
		dst_iter++;
		src_iter++;
		i++;
	}
	return (dst);
}
