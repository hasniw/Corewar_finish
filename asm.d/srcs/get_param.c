/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 02:45:07 by hasni             #+#    #+#             */
/*   Updated: 2020/02/27 20:54:06 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_param_byte(t_inst *inst, int value, int i)
{
	if (i == 0)
		inst->param_byte = value * 64;
	else if (i == 1)
		inst->param_byte += value * 16;
	else
		inst->param_byte += value * 4;
}

char		get_param_type(char *str, t_inst *inst, int i)
{
	if (str[0] == 'r')
	{
		get_param_byte(inst, 1, i);
		return (T_REG);
	}
	if (str[0] == '%')
	{
		get_param_byte(inst, 2, i);
		if (ft_isdigit(str[1]) || str[1] == '-')
			return (T_DIR);
		else if (str[1] == ':')
			return (T_DIR | T_LAB);
		return (0);
	}
	get_param_byte(inst, 3, i);
	if (ft_isdigit(str[0]) || str[0] == '-')
		return (T_IND);
	else if (str[0] == ':')
		return (T_IND | T_LAB);
	return (0);
}
