/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:34:49 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 14:52:56 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (*needle == '\0')
		return ((char*)haystack);
	i = 0;
	j = 0;
	result = (char*)haystack;
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			result = (char*)&haystack[i];
			while (haystack[i + j] == needle[j] && needle[j] != '\0')
				j++;
			if (needle[j] == '\0')
				return (result);
			else
				j = 0;
		}
		i++;
	}
	return (NULL);
}
