/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:51:06 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/02/19 14:07:52 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_doublechar(char **w)
{
	int	i;
	
	if (!w)
		return ;
	i = 0;
	while (w[i])
	{
		free(w[i]);
		w[i] = NULL;
		i++;
	}
	free(w);
	w = NULL;
}

void	free_line(char *l)
{
	if (!l)
		return ;
	free(l);
	l = NULL;
}

void	free_all(char **w, char *l)
{
	free_doublechar(w);
	free_line(l);
}
