/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:39:44 by flcarre           #+#    #+#             */
/*   Updated: 2019/03/20 02:28:39 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_atoui(const char *str)
{
	unsigned int	r;

	r = 0;
	while (ft_isspace((int)(*str)))
		str++;
	if (*str == '+')
		str++;
	while (ft_isdigit((int)(*str)))
		r = r * 10 + *(str++) - '0';
	return (r);
}
