/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:38:04 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 19:35:37 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim_char(char const *s, char c)
{
	size_t	i_b;
	size_t	i_e;
	size_t	len;
	char	*rt;

	if (!s)
		return (NULL);
	i_b = 0;
	i_e = ft_strlen(s) - 1;
	while (s[i_b] == c)
		i_b++;
	while (s[i_e] == c && i_e > 0)
		i_e--;
	len = (i_e < i_b) ? 0 : i_e - i_b + 1;
	rt = (char*)malloc(len + 1);
	if (!rt)
		return (NULL);
	rt = ft_strncpy(rt, (const char*)&s[i_b], len);
	rt[len] = '\0';
	return (rt);
}
