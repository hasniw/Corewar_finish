/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modulo_mem_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:55:24 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/22 17:30:52 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_modulo_mem_size(int addr)
{
	if (addr >= 0)
		return (addr % MEM_SIZE);
	else
		return (MEM_SIZE + (addr % MEM_SIZE));
}
