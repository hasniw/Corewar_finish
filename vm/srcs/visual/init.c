/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:26:37 by dcoloma           #+#    #+#             */
/*   Updated: 2020/03/06 15:26:39 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_visu		*ft_init_visu(t_vm *vm)
{
	t_visu	*visu;
	t_win	*arena;
	t_win	*info;

	visu = (t_visu *)malloc(sizeof(t_visu));
	vm->visu = visu;
	arena = (t_win *)malloc(sizeof(t_win));
	info = (t_win *)malloc(sizeof(t_win));
	if (visu == NULL || arena == NULL || info == NULL)
		return (NULL);
	arena->dim.lines = 67;
	arena->dim.cols = 203;
	arena->coord.x = 0;
	arena->coord.y = 0;
	info->dim.lines = arena->dim.lines;
	info->dim.cols = 60;
	info->coord.x = arena->dim.cols;
	info->coord.y = 0;
	visu->arena = arena;
	visu->info = info;
	visu->cps = 40;
	return (visu);
}

static void	ft_init_colors(t_visu *visu)
{
	start_color();
	init_color(COLOR_WHITE, 255, 255, 255);
	init_pair(COLOR_DEF, COLOR_WHITE, COLOR_BLACK);
	init_pair(COLOR_P1, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_P2, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_P3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(COLOR_P4, COLOR_BLUE, COLOR_BLACK);
	init_pair(COLOR_P5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(COLOR_P6, COLOR_CYAN, COLOR_BLACK);
	init_pair(COLOR_P7, COLOR_BLACK, COLOR_WHITE);
	visu->color_p[0] = COLOR_DEF;
	visu->color_p[1] = COLOR_P1;
	visu->color_p[2] = COLOR_P2;
	visu->color_p[3] = COLOR_P3;
	visu->color_p[4] = COLOR_P4;
	visu->color_p[5] = COLOR_P5;
	visu->color_p[6] = COLOR_P6;
	visu->color_p[7] = COLOR_P7;
}

void		ft_init_arena(t_visu *visu, t_vm *vm, int *color_p)
{
	ft_print_col_numbers_bis(visu);
	ft_print_arena_bis(visu, vm, color_p);
}

void		ft_init_panel(t_visu *visu, t_vm *vm)
{
	int	x;
	int	y;

	x = 1;
	y = 2;
	ft_print_war_bis(visu->info, x, y);
	ft_print_first_panel(visu->info, vm);
	ft_print_secnd_panel(visu->info, vm);
	ft_print_third_panel(visu->info, vm);
	ft_print_fourth_panel(visu->info, "PAUSE");
}

void		ft_init(t_vm *vm, t_visu *visu)
{
	ft_create_windows(visu);
	visu->info->coord.x = 1;
	visu->info->coord.y = 2;
	ft_init_colors(visu);
	ft_init_arena(visu, vm, visu->color_p);
	ft_init_panel(visu, vm);
	wrefresh(vm->visu->arena->window);
	wrefresh(vm->visu->info->window);
}
