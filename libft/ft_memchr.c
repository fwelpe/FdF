/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:58:17 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 14:50:22 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*u_s;
	unsigned char	u_c;
	size_t			i;

	u_s = (unsigned char*)s;
	u_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (u_s[i] == u_c)
			return (&(u_s[i]));
		i++;
	}
	return (NULL);
}
