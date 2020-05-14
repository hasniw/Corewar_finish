/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_machine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:59:21 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/22 18:08:46 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_print_bytes(t_vm *vm, int i)
{
	int color;

	color = vm->owner[i] % 8;
	if (color == 0)
		ft_printf("%{}%02x ", vm->mem[i]);
	else if (color == 1)
		ft_printf("%{RED}%02x ", vm->mem[i]);
	else if (color == 2)
		ft_printf("%{GREEN}%02x ", vm->mem[i]);
	else if (color == 3)
		ft_printf("%{PURPLE}%02x ", vm->mem[i]);
	else if (color == 4)
		ft_printf("%{BLUE}%02x ", vm->mem[i]);
	else if (color == 5)
		ft_printf("%{YELLOW}%02x ", vm->mem[i]);
	else if (color == 6)
		ft_printf("%{CYAN}%02x ", vm->mem[i]);
	else if (color == 7)
		ft_printf("%{ORANGE}%02x ", vm->mem[i]);
}

/*
** if (vm->player[i].id == 1)
** 	ft_printf("%{RED}");
** else if (vm->player[i].id == 2)
** 	ft_printf("%{GREEN}");
** else if (vm->player[i].id == 3)
** 	ft_printf("%{PURPLE}");
** else if (vm->player[i].id == 4)
** 	ft_printf("%{BLUE}");
*/

int			ft_get_player_color(t_vm *vm, int players)
{
	int i;

	i = 0;
	while (i < vm->nb_players)
	{
		if (vm->player[i].id == players)
			break ;
		i++;
	}
	return (i);
}

static void	ft_print_col_numbers(void)
{
	int i;

	i = 0;
	ft_printf("Col nb : ");
	while (i < 64)
	{
		ft_printf("%02d ", i);
		i++;
	}
	ft_printf("     |\n");
}

int			ft_print_arena(t_vm *vm)
{
	int i;
	int lines;
	int players;

	i = 0;
	players = 0;
	ft_printf("\e[1;1H\e[2J");
	ft_print_col_numbers();
	lines = ft_sqrt(MEM_SIZE);
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % lines == 0)
			print_pannel(vm, i / lines, &players);
		if (i % lines == 0)
			ft_printf("0x%04x : ", i);
		ft_print_bytes(vm, i);
		i++;
	}
	ft_printf("%{}     |\n");
	return (0);
}

int			ft_print_dump(t_vm *vm)
{
	int i;
	int lines;

	i = 0;
	lines = ft_sqrt(MEM_SIZE);
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % lines == 0)
			ft_printf("\n");
		if (i % lines == 0)
			ft_printf("0x%04x : ", i);
		ft_printf("%02x ", vm->mem[i]);
		i++;
	}
	ft_printf("\n");
	return (0);
}
