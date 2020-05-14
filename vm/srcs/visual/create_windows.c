/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:26:31 by dcoloma           #+#    #+#             */
/*   Updated: 2020/03/06 15:26:33 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_create_windows(t_visu *visu)
{
	t_win	*arena;
	t_win	*info;

	arena = visu->arena;
	info = visu->info;
	arena->window = newwin(arena->dim.lines, arena->dim.cols,
		arena->coord.y, arena->coord.x);
	info->window = newwin(info->dim.lines, info->dim.cols,
		info->coord.y, info->coord.x);
	ft_create_border(visu);
}

void		ft_create_border(t_visu *visu)
{
	box(visu->arena->window, ACS_VLINE, ACS_HLINE);
	box(visu->info->window, ACS_VLINE, ACS_HLINE);
	mvwprintw(visu->arena->window, 0, 1, "Arena");
	mvwprintw(visu->info->window, 0, 1, "Info");
	refresh();
}
