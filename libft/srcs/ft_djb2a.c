/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_djb2a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:54:18 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/12 01:57:54 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_djb2a(char *str)
{
	unsigned long	hash;

	hash = 5381;
	while (str && *str)
	{
		hash = (hash * 33) ^ *str;
		str++;
	}
	return (hash);
}

unsigned long	ft_hash(unsigned long addr)
{
	unsigned long	hash;
	unsigned int	i;

	hash = 0;
	i = 0;
	while (i < 64)
		hash = (hash * 33) ^ (addr >> i++);
	return (hash);
}
