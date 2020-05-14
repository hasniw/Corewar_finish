/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:37:35 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/13 00:49:33 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strrevncmp(const char *s1, const char *s2, unsigned long n)
{
	unsigned long	l1;
	unsigned long	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s1 += l1 - 1;
	s2 += l2 - 1;
	if (!n)
		return (0);
	if (l1 < n || l2 < n)
		return (1);
	while (--n && --l1 && --l2)
	{
		if ((unsigned char)(*s1) != (unsigned char)(*s2))
			return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
		s1--;
		s2--;
	}
	return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
}
