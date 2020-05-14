/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:48:50 by lutsiara          #+#    #+#             */
/*   Updated: 2020/02/24 18:41:13 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	ft_arg_check(int ac)
{
	if (ac == 1)
	{
		ft_print_helper();
		return (1);
	}
	return (0);
}

static int	ft_load_players(char **av, t_vm *vm)
{
	int	i;
	int	ret;
	int	err;

	i = 0;
	while (++i < vm->nb_args)
	{
		if (av[i] && av[i][0] == '-')
		{
			if ((ret = ft_parse_options(vm, av, &i)))
				return (ret);
		}
		else if ((err = ft_parse_players(vm, av, i)))
			return (err);
	}
	return (vm->nb_players > 0 ? 0 : 1);
}

static void	ft_position_loading(t_vm *vm)
{
	t_process	*tracer;
	int			div;
	int			i;

	i = vm->nb_players - 1;
	div = MEM_SIZE / vm->nb_players;
	tracer = vm->process;
	while (tracer)
	{
		tracer->pc = div * i;
		i--;
		tracer = tracer->next;
	}
}

int			main(int ac, char **av)
{
	int		err;
	t_vm	*vm;

	err = 0;
	if (ft_arg_check(ac))
		return (1);
	if (!(vm = ft_init_vm(ac)))
		return (ft_init_error(ALLOC_ERROR, vm));
	if ((err = ft_load_players(av, vm)))
		return (ft_init_error(err, vm));
	if ((ft_load_process_list(vm)) == ALLOC_ERROR)
		return (ALLOC_ERROR);
	ft_position_loading(vm);
	ft_create_arena(vm);
	vm->last_live = &vm->player[vm->nb_players - 1];
	err = ft_exec_machine(vm);
	if (err != END_GAME)
		return (ft_init_error(err, vm));
	ft_free_machine(vm);
	ft_printf("That was Corewar !\nDid you enjoyed ?\n");
	return (0);
}
