/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:01:06 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/22 17:34:10 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

int		ft_op_lfork(t_vm *vm, t_process *proc)
{
	t_process	*new;

	if (!(new = (t_process *)malloc(sizeof(t_process))))
		return ((vm->malloc_flag = 1));
	new->id = vm->nb_proc++;
	new->master = proc->master;
	new->carry = proc->carry;
	new->last_live = 0;
	new->pc = ft_modulo_mem_size(proc->pc + ft_read_address(vm, \
					(proc->pc + 1) % MEM_SIZE, 2));
	new->current_op = vm->mem[new->pc];
	if (ft_is_valid_op(new->current_op))
		new->cycles_left = g_op_tab[new->current_op - 1].cycles - 1;
	else
		new->cycles_left = 0;
	ft_copy_registers(new, proc);
	new->next = vm->process;
	vm->process = new;
	return (3);
}

int		ft_op_aff(t_vm *vm, t_process *proc)
{
	char		c;

	if (vm->mem[(proc->pc + 1) % MEM_SIZE] == 64)
	{
		if (ft_is_valid_reg(vm->mem[(proc->pc + 2) % MEM_SIZE]))
		{
			c = proc->reg[vm->mem[(proc->pc + 2) % MEM_SIZE]] % 256;
			ft_printf("%c", c);
		}
	}
	return (3);
}

void	ft_check_empty(t_vm *vm)
{
	if (!ft_strlen(vm->player[vm->nb_players].name))
	{
		ft_bzero(vm->player[vm->nb_players].name, PROG_NAME_LENGTH);
		ft_memcpy(vm->player[vm->nb_players].name, "Anonymous", \
				ft_strlen("Anonymous"));
	}
	if (!ft_strlen(vm->player[vm->nb_players].comment))
	{
		ft_bzero(vm->player[vm->nb_players].comment, COMMENT_LENGTH);
		ft_memcpy(vm->player[vm->nb_players].comment, "Eeuuuhhh....", \
				ft_strlen("Eeuuuhhh...."));
	}
}
