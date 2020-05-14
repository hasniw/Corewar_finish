/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunkcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:43:16 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/08 19:38:44 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chunkcmp(const char *cmp, const char *need, const char sep)
{
	unsigned long	len;
	unsigned long	len2;
	char			*tmp;

	if (!cmp)
		return ((void *)0);
	if (!need || !(*need))
		return ((char *)cmp);
	len2 = ft_strlen(need);
	tmp = (char *)cmp;
	while (tmp)
	{
		len = 0;
		if (*tmp == sep)
			tmp++;
		while (tmp[len] && tmp[len] != (char)sep)
			len++;
		if (len == len2 && !ft_strncmp(need, tmp, len))
			return ((char *)tmp);
		tmp = ft_strchr(tmp, (int)sep);
	}
	return ((void *)0);
}
