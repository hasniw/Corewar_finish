/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:48:53 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/22 17:42:20 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			ft_check_extension(char *name)
{
	int	len;

	len = ft_strlen(name) - 4;
	if (len > 0)
		if (!ft_strcmp((name + len), ".cor"))
			return (0);
	return (1);
}

static int	ft_visualizer_option(t_vm *vm, char **av, int *i)
{
	if ((*i + 1) < vm->nb_args && ft_strisnum(av[*i + 1]) \
	&& vm->vis == -1 && vm->dump == -1)
	{
		vm->vis = ft_atoi(av[++(*i)]);
		if (vm->vis > 0)
			return (OH_OUI);
	}
	return (VIS_ERROR);
}

static int	ft_number_option(t_vm *vm, char **av, int *i)
{
	if ((*i + 1) < vm->nb_args && ft_strisnum(av[*i + 1]))
	{
		if (vm->nb_players < MAX_PLAYERS && !vm->nb_option)
		{
			if ((vm->nb_option = ft_atoi(av[++(*i)])) > 0 \
			&& vm->nb_option <= MAX_PLAYERS)
				return (vm->nb_players <= MAX_PLAYERS
							? OH_OUI
							: PLAYER_NUMBER_ERROR);
			else
				return (PLAYER_NUMBER_ERROR);
		}
	}
	return (PLAYER_NUMBER_ERROR);
}

static int	ft_dump_option(t_vm *vm, char **av, int *i)
{
	if ((*i + 1) < vm->nb_args && ft_strisnum(av[*i + 1]) \
	&& vm->dump == -1 && vm->vis == -1)
	{
		vm->dump = ft_atoi(av[++(*i)]);
		return (OH_OUI);
	}
	return (DUMP_ERROR);
}

int			ft_parse_options(t_vm *vm, char **av, int *i)
{
	if (!ft_strcmp(av[*i], "-v"))
		return (ft_visualizer_option(vm, av, i));
	if (!ft_strcmp(av[*i], "-n"))
		return (ft_number_option(vm, av, i));
	if (!ft_strcmp(av[*i], "-dump"))
		return (ft_dump_option(vm, av, i));
	return (1);
}
