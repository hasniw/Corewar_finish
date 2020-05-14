/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:56:46 by lutsiara          #+#    #+#             */
/*   Updated: 2020/02/19 11:57:39 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strspn(const char *s, const char *charset)
{
	unsigned long	i;

	i = 0;
	while (s[i] && ft_charinset(s[i], charset))
		i++;
	return (i);
}
