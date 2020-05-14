/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_virtual_machine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:35:11 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/22 22:30:52 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <unistd.h>

static void	ft_cycle_review(t_vm *vm)
{
	if (++(vm->nb_checks) == MAX_CHECKS || vm->lives_since_check >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->nb_checks = 0;
		vm->cycles_to_die = vm->cycles_to_die < 1 ? 1 : vm->cycles_to_die;
	}
	vm->last_verif = vm->cycles;
	vm->lives_since_check = 0;
}

static int	ft_option_review(t_vm *vm)
{
	if (vm->dump == vm->cycles)
	{
		ft_print_dump(vm);
		return (END_GAME);
	}
	if (vm->vis != -1 && !(vm->cycles % vm->vis))
	{
		if (ft_refresh_visu(vm))
			return (VIS_ERROR);
	}
	return (0);
}

static int	ft_machine_review(t_vm *vm)
{
	if (ft_option_review(vm))
		return (END_GAME);
	if (vm->cycles && !((vm->cycles - vm->last_verif) % vm->cycles_to_die))
	{
		if (ft_life_check(vm))
			return (END_GAME);
		ft_cycle_review(vm);
	}
	return (0);
}

static void	ft_introduce_players(t_vm *vm)
{
	int			i;
	t_process	*tracer;

	tracer = vm->process;
	ft_printf("Introducing the champions up for battle...\n");
	while (tracer)
	{
		i = -1;
		while (++i < vm->nb_players)
			if (vm->player[i].id == tracer->master)
				break ;
		ft_printf("%s (%d), weighing in at %d bytes, \"%s\"\n", \
				vm->player[i].name, tracer->master, vm->player[i].size, \
				vm->player[i].comment);
		tracer = tracer->next;
	}
	ft_printf("%{RED}\nLEEEEEEEEET'S GEEEET");
	ft_printf(" REAAAADDDDYY TOOO RUUUUUUMBLEEEEEE!%{}\n\n");
}

int			ft_exec_machine(t_vm *vm)
{
	t_process	*champion;
	int			err;

	ft_introduce_players(vm);
	if (vm->vis != -1)
		if ((err = ft_visual(vm)) != OH_OUI)
			return (err);
	while ((ft_machine_review(vm) != END_GAME))
	{
		if (vm->vis != -1 && ft_key_event(vm) == END_GAME)
		{
			ft_exit_visu(vm->visu);
			break ;
		}
		champion = vm->process;
		while (champion)
		{
			if (ft_process_review(vm, champion))
				return (ALLOC_ERROR);
			champion = champion->next;
		}
		vm->cycles++;
	}
	return (END_GAME);
}
