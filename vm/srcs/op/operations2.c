/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:02:52 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/22 17:39:27 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_op_sub(t_vm *vm, t_process *proc)
{
	t_param	params;
	int		offset;

	params = ft_set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		proc->reg[params.n[2]] = proc->reg[params.n[0]]
			- proc->reg[params.n[1]];
		if (proc->reg[params.n[2]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return (offset);
}

int		ft_op_and(t_vm *vm, t_process *proc)
{
	t_param	params;
	int		offset;

	params = ft_set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		if (params.c[0] == REG_CODE)
			params.n[0] = proc->reg[params.n[0]];
		else if (params.c[0] == IND_CODE)
			params.n[0] = ft_read_address(vm, params.n[0], 4);
		if (params.c[1] == REG_CODE)
			params.n[1] = proc->reg[params.n[1]];
		else if (params.c[1] == IND_CODE)
			params.n[1] = ft_read_address(vm, params.n[1], 4);
		proc->reg[params.n[2]] = params.n[0] & params.n[1];
		if (proc->reg[params.n[2]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return (offset);
}

int		ft_op_or(t_vm *vm, t_process *proc)
{
	t_param	params;
	int		offset;

	params = ft_set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		if (params.c[0] == REG_CODE)
			params.n[0] = proc->reg[params.n[0]];
		else if (params.c[0] == IND_CODE)
			params.n[0] = ft_read_address(vm, params.n[0], 4);
		if (params.c[1] == REG_CODE)
			params.n[1] = proc->reg[params.n[1]];
		else if (params.c[1] == IND_CODE)
			params.n[1] = ft_read_address(vm, params.n[1], 4);
		proc->reg[params.n[2]] = params.n[0] | params.n[1];
		if (proc->reg[params.n[2]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return (offset);
}

int		ft_op_xor(t_vm *vm, t_process *proc)
{
	t_param	params;
	int		offset;

	params = ft_set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		if (params.c[0] == REG_CODE)
			params.n[0] = proc->reg[params.n[0]];
		else if (params.c[0] == IND_CODE)
			params.n[0] = ft_read_address(vm, params.n[0], 4);
		if (params.c[1] == REG_CODE)
			params.n[1] = proc->reg[params.n[1]];
		else if (params.c[1] == IND_CODE)
			params.n[1] = ft_read_address(vm, params.n[1], 4);
		proc->reg[params.n[2]] = params.n[0] ^ params.n[1];
		if (proc->reg[params.n[2]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return (offset);
}

int		ft_op_zjmp(t_vm *vm, t_process *proc)
{
	if (proc->carry)
		return (
			ft_idx_mod(ft_read_address(vm, (proc->pc + 1) % MEM_SIZE, 2)));
	else
		return (3);
}
