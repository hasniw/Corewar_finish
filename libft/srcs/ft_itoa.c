/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:09:13 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/04 11:22:16 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	i;
	int				x;
	char			*tmp;
	unsigned int	abs;

	i = ft_digitlen(n, 10);
	i += (n < 0) ? 1 : 0;
	if (!(tmp = ft_strnew((unsigned long)i)))
		return ((void *)0);
	*tmp = (n < 0) ? '-' : '\0';
	x = n;
	abs = 0;
	while ((n < 0) ? (--i) : (i--))
	{
		abs = (x % 10 < 0) ? -(x % 10) : x % 10;
		*(tmp + i) = '0' + abs;
		x /= 10;
	}
	return (tmp);
}
