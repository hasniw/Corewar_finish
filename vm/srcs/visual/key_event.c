/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:18:59 by dcoloma           #+#    #+#             */
/*   Updated: 2020/04/22 17:21:49 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_edit_speed_cycle(t_vm *vm, int ch)
{
	if ((ch == '-' || ch == '/'))
	{
		if (ch == '-' && vm->visu->cps > 1)
			vm->visu->cps--;
		else if (ch == '/' && vm->visu->cps > 51)
			vm->visu->cps -= 50;
	}
	else if (vm->visu->cps < 1000 && (ch == '+' || ch == '*'))
	{
		if (ch == '+' && vm->visu->cps < 1000)
			vm->visu->cps++;
		else if (ch == '*' && vm->visu->cps < 950)
			vm->visu->cps += 50;
	}
	if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
	{
		ft_print_first_panel(vm->visu->info, vm);
		wrefresh(vm->visu->info->window);
	}
}

static void	ft_resize_window(t_vm *vm, char *state)
{
	ft_init_arena(vm->visu, vm, vm->visu->color_p);
	ft_print_arena_bis(vm->visu, vm, vm->visu->color_p);
	ft_print_war_bis(vm->visu->info, 1, 2);
	ft_print_first_panel(vm->visu->info, vm);
	ft_print_secnd_panel(vm->visu->info, vm);
	ft_print_third_panel(vm->visu->info, vm);
	ft_print_fourth_panel(vm->visu->info, state);
	ft_create_border(vm->visu);
	wrefresh(vm->visu->info->window);
	wrefresh(vm->visu->arena->window);
	refresh();
}

int			ft_pause(t_vm *vm)
{
	int	ch;

	ft_print_fourth_panel(vm->visu->info, "PAUSE");
	wrefresh(vm->visu->info->window);
	while ((ch = getch()) != ' ')
	{
		if (ch == 27)
			return (END_GAME);
		ft_edit_speed_cycle(vm, ch);
		if (ch == KEY_RESIZE)
			ft_resize_window(vm, "PAUSE");
	}
	ft_print_fourth_panel(vm->visu->info, "RUNNING");
	return (0);
}

int			ft_key_event(t_vm *vm)
{
	int	ch;

	if ((ch = getch()) == 27)
		return (END_GAME);
	ft_edit_speed_cycle(vm, ch);
	if (ch == KEY_RESIZE)
		ft_resize_window(vm, "PAUSE");
	if (ch == ' ')
		return (ft_pause(vm));
	return (0);
}
