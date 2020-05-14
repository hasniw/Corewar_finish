/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:26:59 by dcoloma           #+#    #+#             */
/*   Updated: 2020/04/22 17:21:07 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_visual(t_vm *vm)
{
	t_visu	*visu;

	initscr();
	timeout(0);
	visu = ft_init_visu(vm);
	if (visu == NULL)
	{
		ft_exit_visu(vm->visu);
		return (ALLOC_ERROR);
	}
	curs_set(FALSE);
	noecho();
	if (has_colors() == FALSE)
	{
		ft_exit_visu(vm->visu);
		ft_printf("Your terminal does not support color\n");
		return (VIS_ERROR);
	}
	ft_init(vm, visu);
	if (ft_pause(vm) == END_GAME)
	{
		ft_exit_visu(vm->visu);
		return (END_GAME);
	}
	return (0);
}

int	ft_refresh_visu(t_vm *vm)
{
	t_visu		*visu;
	t_process	*champion;
	int			curs_x;
	int			curs_y;

	visu = vm->visu;
	ft_print_arena_bis(visu, vm, visu->color_p);
	ft_print_first_panel(visu->info, vm);
	ft_print_secnd_panel(visu->info, vm);
	ft_print_third_panel(visu->info, vm);
	champion = vm->process;
	while (champion != NULL)
	{
		curs_x = (champion->pc % ft_sqrt(MEM_SIZE)) * 3 + 10;
		curs_y = (champion->pc / ft_sqrt(MEM_SIZE)) + 2;
		mvwchgat(visu->arena->window, curs_y, curs_x,
			2, A_STANDOUT, champion->id + 1, NULL);
		champion = champion->next;
	}
	wrefresh(visu->arena->window);
	wrefresh(visu->info->window);
	usleep(MAX_SLEEP_TIME / visu->cps);
	return (0);
}

int	ft_exit_visu(t_visu *visu)
{
	endwin();
	if (visu != NULL)
	{
		if (visu->arena != NULL)
		{
			if (visu->arena->window != NULL)
				free(visu->arena->window);
			free(visu->arena);
		}
		if (visu->info != NULL)
		{
			if (visu->info->window != NULL)
				free(visu->info->window);
			free(visu->info);
		}
		free(visu);
	}
	return (0);
}

int	ft_end_visu(t_vm *vm)
{
	int		x;
	int		y;
	t_win	*info;
	int		i;

	info = vm->visu->info;
	x = info->coord.x;
	y = info->coord.y + 58;
	i = ft_get_player_color(vm, vm->last_live->id);
	ft_print_fourth_panel(vm->visu->info, "Press q to quit");
	y = y + (info->dim.lines - y) / 2 + 1;
	x = info->dim.cols / 2 - ft_strlen(vm->last_live->name) / 2 - 9;
	mvwprintw(info->window, y + 1, x, "The winner is:");
	wattron(info->window, COLOR_PAIR(vm->visu->color_p[i + 1]) | A_BOLD);
	mvwprintw(info->window, y + 1, x + 15, "%.30s (%d)",
		vm->last_live->name, vm->last_live->id);
	wattroff(info->window, COLOR_PAIR(vm->visu->color_p[i + 1]) | A_BOLD);
	wrefresh(vm->visu->info->window);
	while (getch() != 'q')
		;
	ft_exit_visu(vm->visu);
	return (END_GAME);
}
