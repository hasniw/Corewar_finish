/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:58:15 by lutsiara          #+#    #+#             */
/*   Updated: 2020/02/27 22:26:22 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

static t_process	*ft_list_pop(t_vm *vm)
{
	t_process *first;

	first = vm->process;
	vm->process = vm->process->next;
	free(first);
	return (vm->process);
}

static t_process	*ft_list_delone(t_process *prec, t_process *current)
{
	prec->next = current->next;
	free(current);
	return (prec->next);
}

static int			ft_process_life_check(t_vm *vm)
{
	t_process *tracer;
	t_process *prec;

	prec = vm->process;
	tracer = vm->process;
	while (tracer)
	{
		if (tracer->last_live <= vm->last_verif)
		{
			if (tracer == vm->process)
				tracer = ft_list_pop(vm);
			else
				tracer = ft_list_delone(prec, tracer);
		}
		else
		{
			prec = tracer;
			tracer = tracer->next;
		}
	}
	return (0);
}

int					ft_life_check(t_vm *vm)
{
	ft_process_life_check(vm);
	if (vm->process == NULL && vm->last_live)
	{
		if (vm->vis == -1)
			ft_printf("The winner is: %20s (%d)\n",
				vm->last_live->name, vm->last_live->id);
		else
			ft_end_visu(vm);
		return (END_GAME);
	}
	return (0);
}
