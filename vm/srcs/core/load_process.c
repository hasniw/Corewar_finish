/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:04:30 by lutsiara          #+#    #+#             */
/*   Updated: 2020/02/27 19:41:58 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

static t_process	*ft_load_process_from_player(t_player player)
{
	t_process *process;

	if (!(process = (t_process *)malloc(sizeof(t_process))))
		return (NULL);
	process->master = player.id;
	process->carry = 0;
	process->last_live = 0;
	process->current_op = player.exec[0];
	process->cycles_left = g_op_tab[process->current_op - 1].cycles - 1;
	ft_init_registers(process);
	process->next = NULL;
	return (process);
}

static void			ft_find_process_position(t_process **lst, t_process *proc)
{
	t_process	*tracer;
	t_process	*tmp;

	tracer = *lst;
	tmp = NULL;
	while (tracer && tracer->master > proc->master)
	{
		tmp = tracer;
		tracer = tracer->next;
	}
	if (!tmp)
	{
		proc->next = *lst;
		*lst = proc;
	}
	else
	{
		proc->next = tracer;
		tmp->next = proc;
	}
}

static void			ft_place_process(t_process **lst, t_process *proc, int i)
{
	proc->id = i;
	if (!*lst)
		*lst = proc;
	else if (!(*lst)->next)
	{
		if ((*lst)->master < proc->master)
		{
			proc->next = *lst;
			*lst = proc;
		}
		else
			(*lst)->next = proc;
	}
	else
		ft_find_process_position(lst, proc);
}

int					ft_load_process_list(t_vm *vm)
{
	int			i;
	t_process	*proc;

	i = 0;
	while (i < vm->nb_players)
	{
		if (!(proc = ft_load_process_from_player(vm->player[i])))
			return (ALLOC_ERROR);
		ft_place_process(&(vm->process), proc, i);
		i++;
	}
	vm->nb_proc = vm->nb_players;
	return (0);
}
