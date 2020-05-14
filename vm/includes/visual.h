/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:04:05 by dcoloma           #+#    #+#             */
/*   Updated: 2020/03/06 18:04:06 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H
# include <stdlib.h>
# include <unistd.h>

# define COLOR_DEF	0
# define COLOR_P1	1
# define COLOR_P2	2
# define COLOR_P3	3
# define COLOR_P4	4
# define COLOR_P5	5
# define COLOR_P6	6
# define COLOR_P7	7
# define MAX_SLEEP_TIME 1000000

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;
typedef struct	s_dim
{
	int	lines;
	int	cols;
}				t_dim;
typedef struct	s_win
{
	t_coord	coord;
	t_dim	dim;
	WINDOW	*window;
}				t_win;

typedef struct	s_visu
{
	t_win	*arena;
	t_win	*info;
	t_coord	cursor;
	int		color_p[8];
	int		cps;
}				t_visu;
#endif
