/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:53:56 by lutsiara          #+#    #+#             */
/*   Updated: 2020/02/19 11:57:47 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strcspn(const char *s, const char *charset)
{
	unsigned long	i;

	i = 0;
	while (s[i] && !ft_charinset(s[i], charset))
		i++;
	return (i);
}
