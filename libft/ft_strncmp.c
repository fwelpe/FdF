/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:51:29 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 18:58:51 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] == s2[i] && i < n && s1[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (i == n ? 0 : (unsigned char)s1[i] - (unsigned char)s2[i]);
}
