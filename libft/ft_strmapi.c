/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:47:09 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/05 22:29:28 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	full_l;
	char			*rt;
	char			cell;

	if (!s || !f)
		return (NULL);
	i = 0;
	j = 0;
	full_l = ft_strlen(s) + 1;
	rt = (char *)malloc(full_l);
	if (!rt)
		return (NULL);
	while (s[i])
	{
		if ((cell = f(i, s[i])))
			rt[j++] = cell;
		i++;
	}
	while (j < full_l)
		rt[j++] = '\0';
	return (rt);
}
