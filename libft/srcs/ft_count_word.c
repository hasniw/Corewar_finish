/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:21:48 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/01 13:41:45 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char *str, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			w++;
		i++;
	}
	return (w);
}
