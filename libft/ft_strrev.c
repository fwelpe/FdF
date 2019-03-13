/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:12:19 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/06 14:21:56 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *in)
{
	char	*out;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(in);
	if (!(out = (char*)malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		out[i] = in[len - i - 1];
		i++;
	}
	out[i] = '\0';
	return (out);
}
