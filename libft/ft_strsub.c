/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:20:14 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 14:52:59 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*rt;

	rt = (char *)ft_memalloc(len + 1);
	if (!s || !rt)
		return (NULL);
	rt[len] = '\0';
	return (ft_strncpy(rt, &(s[start]), len));
}
