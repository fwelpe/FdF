/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:59:26 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 17:00:21 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_fd(char const *s, int fd)
{
	char	*crwr;

	if (!s)
		return ;
	crwr = (char*)s;
	while (*crwr)
		ft_putchar_fd(*crwr++, fd);
}
