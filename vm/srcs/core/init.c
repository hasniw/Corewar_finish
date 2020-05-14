/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:46:35 by flcarre           #+#    #+#             */
/*   Updated: 2020/04/22 17:51:13 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

static int	ft_get_master(t_vm *vm, int master)
{
	int i;

	i = 0;
	while (i < vm->nb_players)
	{
		if (vm->player[i].id == master)
			return (i);
		i++;
	}
	return (0);
}

void		ft_create_arena(t_vm *vm)
{
	int			i;
	int			div;
	t_process	*tracer;

	i = vm->nb_players - 1;
	div = MEM_SIZE / vm->nb_players;
	tracer = vm->process;
	while (tracer)
	{
		ft_memcpy(vm->mem + (div * i), \
				vm->player[ft_get_master(vm, tracer->master)].exec, \
				vm->player[ft_get_master(vm, tracer->master)].size);
		ft_memset(vm->owner + (div * i), \
				vm->player[ft_get_master(vm, tracer->master)].id, \
				vm->player[ft_get_master(vm, tracer->master)].size);
		tracer = tracer->next;
		i--;
	}
}

void		ft_init_players(t_vm *vm)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		vm->player[vm->nb_players].id = -1;
		vm->player[i].size = 0;
		i++;
	}
	i = -1;
	while (++i < 6)
		vm->live_tab[i] = -1;
}

t_vm		*ft_init_vm(int ac)
{
	t_vm *vm;

	if (!(vm = (t_vm *)malloc(sizeof(t_vm))))
		return (NULL);
	ft_bzero(vm->mem, MEM_SIZE);
	ft_bzero(vm->owner, MEM_SIZE);
	vm->vis = -1;
	vm->process = NULL;
	vm->dump = -1;
	vm->nb_args = ac;
	vm->nb_players = 0;
	vm->cycles = 0;
	vm->nb_lives = 0;
	vm->nb_proc = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->nb_checks = 0;
	vm->last_verif = 0;
	vm->lives_since_check = 0;
	vm->nb_option = 0;
	vm->malloc_flag = 0;
	ft_bzero(vm->player_numbers, MAX_PLAYERS);
	ft_init_players(vm);
	return (vm);
}
