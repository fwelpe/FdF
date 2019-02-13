/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:38:04 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 14:53:02 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	size_t	i_b;
	size_t	i_e;
	size_t	len;
	char	*rt;

	if (!s)
		return (NULL);
	i_b = 0;
	i_e = ft_strlen(s) - 1;
	while (s[i_b] == ' ' || s[i_b] == '\n' || s[i_b] == '\t')
		i_b++;
	while ((s[i_e] == ' ' || s[i_e] == '\n' || s[i_e] == '\t') && i_e > 0)
		i_e--;
	len = (i_e < i_b) ? 0 : i_e - i_b + 1;
	rt = (char*)malloc(len + 1);
	if (!rt)
		return (NULL);
	rt = ft_strncpy(rt, (const char*)&s[i_b], len);
	rt[len] = '\0';
	return (rt);
}
