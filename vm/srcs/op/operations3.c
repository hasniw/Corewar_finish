/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:02:23 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/22 17:38:01 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

int		ft_op_ldi(t_vm *vm, t_process *proc)
{
	t_param		params;
	int			offset;

	params = ft_set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		if (params.c[0] == REG_CODE)
			params.n[0] = proc->reg[params.n[0]];
		else if (params.c[0] == IND_CODE)
			params.n[0] = ft_read_address(vm, params.n[0], 4);
		if (params.c[1] == REG_CODE)
			params.n[1] = proc->reg[params.n[1]];
		proc->reg[params.n[2]] = ft_read_address(vm, \
			ft_modulo_mem_size(proc->pc + \
			ft_idx_mod(params.n[0] + params.n[1])), 4);
	}
	return (offset);
}

int		ft_op_sti(t_vm *vm, t_process *proc)
{
	t_param		params;
	int			offset;

	params = ft_set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		if (params.c[1] == REG_CODE)
			params.n[1] = proc->reg[params.n[1]];
		else if (params.c[1] == IND_CODE)
			params.n[1] = ft_read_address(vm, params.n[1], 4);
		if (params.c[2] == REG_CODE)
			params.n[2] = proc->reg[params.n[2]];
		ft_write_to_address(vm, proc, \
			ft_modulo_mem_size(proc->pc + \
			ft_idx_mod(params.n[1] + params.n[2])), proc->reg[params.n[0]]);
	}
	return (offset);
}

int		ft_op_fork(t_vm *vm, t_process *proc)
{
	t_process	*new;

	if (!(new = (t_process *)malloc(sizeof(t_process))))
		return ((vm->malloc_flag = 1));
	new->id = vm->nb_proc++;
	new->master = proc->master;
	new->carry = proc->carry;
	new->last_live = 0;
	new->pc = ft_modulo_mem_size(proc->pc + ft_idx_mod(ft_read_address(vm, \
		(proc->pc + 1) % MEM_SIZE, 2)));
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

int		ft_op_lld(t_vm *vm, t_process *proc)
{
	t_param		params;
	int			offset;

	params = ft_set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		if (params.c[0] == IND_CODE)
			params.n[0] = ft_read_address(vm, params.n[0], 4);
		proc->reg[params.n[1]] = params.n[0];
		if (proc->reg[params.n[1]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return (offset);
}

int		ft_op_lldi(t_vm *vm, t_process *proc)
{
	t_param		params;
	int			offset;

	params = ft_set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		if (params.c[0] == REG_CODE)
			params.n[0] = proc->reg[params.n[0]];
		else if (params.c[0] == IND_CODE)
			params.n[0] = ft_read_address(vm, params.n[0], 4);
		if (params.c[1] == IND_CODE)
			params.n[1] = ft_read_address(vm, params.n[1], 4);
		proc->reg[params.n[2]] = ft_read_address(vm, \
			ft_modulo_mem_size(proc->pc + params.n[0] + params.n[1]), 4);
		if (proc->reg[params.n[2]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return (offset);
}
