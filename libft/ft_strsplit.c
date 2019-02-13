/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:31:38 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/06 12:34:49 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	mlc_count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i + 1);
}

static void		*ft_clear(char **s, size_t z)
{
	while ((int)z >= 0)
	{
		free(s[z]);
		s[z--] = NULL;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**result;
	int			i;
	size_t		j;
	char const	*crwr;

	if (!s)
		return (NULL);
	if (!(result = (char**)malloc(sizeof(char*) * (ft_countwords(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	crwr = s;
	while ((j < ft_countwords(s, c)) && *crwr)
	{
		while (*crwr == c)
			crwr++;
		if (!(result[j] = (char*)malloc(sizeof(char) * mlc_count(crwr, c))))
			return (ft_clear(result, j - 1));
		while ((*crwr != c) && *crwr)
			result[j][i++] = *(crwr++);
		result[j++][i] = '\0';
		i = 0;
	}
	result[j] = (NULL);
	return (result);
}
