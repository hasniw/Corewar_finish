/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_review.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:56:19 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/22 17:59:13 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	ft_op_dispatch(t_vm *vm, t_process *proc, int op_code)
{
	int (*op[16])(t_vm *, t_process *);

	op[0] = &ft_op_live;
	op[1] = &ft_op_ld;
	op[2] = &ft_op_st;
	op[3] = &ft_op_add;
	op[4] = &ft_op_sub;
	op[5] = &ft_op_and;
	op[6] = &ft_op_or;
	op[7] = &ft_op_xor;
	op[8] = &ft_op_zjmp;
	op[9] = &ft_op_ldi;
	op[10] = &ft_op_sti;
	op[11] = &ft_op_fork;
	op[12] = &ft_op_lld;
	op[13] = &ft_op_lldi;
	op[14] = &ft_op_lfork;
	op[15] = &ft_op_aff;
	return (op[op_code - 1](vm, proc));
}

static void	ft_get_cycles_left(t_process *proc)
{
	if (ft_is_valid_op(proc->current_op))
		proc->cycles_left = g_op_tab[proc->current_op - 1].cycles - 1;
	else
		proc->cycles_left = 0;
}

static void	ft_set_current_op(t_vm *vm, t_process *proc)
{
	proc->current_op = vm->mem[proc->pc];
	ft_get_cycles_left(proc);
}

static int	ft_update_process(t_vm *vm, t_process *proc)
{
	int offset;

	if (proc->current_op != vm->mem[proc->pc])
		ft_set_current_op(vm, proc);
	else if (!ft_is_valid_op(proc->current_op))
	{
		proc->pc = (proc->pc + 1) % MEM_SIZE;
		ft_set_current_op(vm, proc);
	}
	else
	{
		offset = ft_op_dispatch(vm, proc, proc->current_op);
		proc->pc = ft_modulo_mem_size(proc->pc + offset);
		ft_set_current_op(vm, proc);
	}
	return (vm->malloc_flag ? ALLOC_ERROR : 0);
}

int			ft_process_review(t_vm *vm, t_process *process)
{
	if (!process->cycles_left || process->current_op != vm->mem[process->pc])
	{
		if (ft_update_process(vm, process))
			return (ALLOC_ERROR);
	}
	else
		process->cycles_left--;
	return (0);
}
