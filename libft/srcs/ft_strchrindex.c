/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:47:48 by lutsiara          #+#    #+#             */
/*   Updated: 2020/05/09 11:43:22 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strchrindex(const char *str, char c)
{
	unsigned long	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
