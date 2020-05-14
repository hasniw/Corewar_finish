/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_to_address.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:56:53 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/22 18:03:01 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_write_to_address(t_vm *vm, t_process *proc, int addr, int to_write)
{
	int				bytes;
	int				chunk;
	unsigned int	to_write_uns;

	bytes = 0;
	to_write_uns = (unsigned int)to_write;
	while (bytes < 4)
	{
		chunk = ft_power(256, (4 - (bytes + 1)));
		vm->mem[(addr + bytes) % MEM_SIZE] = to_write_uns / chunk;
		vm->owner[(addr + bytes) % MEM_SIZE] = proc->master;
		to_write_uns = to_write_uns % chunk;
		bytes++;
	}
}
