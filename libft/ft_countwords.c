/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:00:05 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/02 14:50:52 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_countwords(char const *s, char d)
{
	size_t	c;
	size_t	w;

	c = 0;
	w = 0;
	if (s[0] == '\0')
		return (0);
	while (s[c] == d)
		c++;
	w = 1;
	while (s[c])
	{
		if (s[c] == d)
		{
			w++;
			while (s[c] == d)
				c++;
		}
		else
			c++;
	}
	return ((s[c - 1] == d && w != 0) ? w - 1 : w);
}
