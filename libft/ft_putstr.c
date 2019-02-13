/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:18:03 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 14:51:14 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr(char const *s)
{
	char	*crwr;

	if (!s)
		return ;
	crwr = (char*)s;
	while (*crwr)
		ft_putchar(*crwr++);
}
