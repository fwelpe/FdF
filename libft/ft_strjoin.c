/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwlpe <fwlpe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:50:06 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/02/12 16:23:06 by fwlpe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	full_l;
	char	*pre_rt;
	char	*rt;

	if (!s1 || !s2)
		return (NULL);
	full_l = ft_strlen(s1) + ft_strlen(s2) + 1;
	rt = (char *)malloc(full_l);
	if (!rt)
		return (NULL);
	pre_rt = ft_strdup(s1);
	rt = ft_strcat(pre_rt, s2);
	return (rt);
}
