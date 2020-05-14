/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:30:17 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/22 17:03:10 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisnum(const char *s)
{
	unsigned long	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (ft_isdigit(s[i]))
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
