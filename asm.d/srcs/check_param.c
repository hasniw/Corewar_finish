/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 02:32:56 by wahasni           #+#    #+#             */
/*   Updated: 2020/02/27 21:01:27 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_param_num(char *str, char **arr, int param_num)
{
	int		i;
	int		sep_num;
	int		arr_num;

	i = 0;
	sep_num = 0;
	while (str[i])
		if (str[i++] == SEPARATOR_CHAR)
			sep_num++;
	arr_num = 0;
	while (arr[arr_num])
		arr_num++;
	if (arr_num != sep_num + 1)
		return (ft_error("too much separators", 1));
	if (param_num != arr_num)
		return (ft_error("parameter number is wrong", 1));
	return (0);
}

static void		get_inst_len(t_op *op, t_inst *inst, char type)
{
	if (type & T_REG)
		inst->len++;
	else if (type & T_DIR)
		inst->len += op->direct_len;
	else if (type & T_IND)
		inst->len += 2;
}

int				check_param(char *str, t_op *op, t_inst *inst, int i)
{
	char	**arr;
	char	*tmp;
	char	type;

	if (!(arr = ft_strsplit(str, SEPARATOR_CHAR)))
		return (ft_error("ft_strsplit failed", 1));
	if (check_param_num(str, arr, op->param_num))
		return (free_tab(arr, 1));
	while (++i < op->param_num)
	{
		if (!(tmp = ft_strtrim(arr[i])))
			return (ft_error("ft_strtrim failed", free_tab(arr, 1)));
		ft_strdel(&arr[i]);
		arr[i] = tmp;
		if (!(type = get_param_type(arr[i], inst, i)))
			return (ft_error("ft_strtrim failed", free_tab(arr, 1)));
		if (!(type & op->param_type[i]))
			return (ft_error("arguments have wrong type", free_tab(arr, 1)));
		if (check_type(arr[i], type))
			return (free_tab(arr, 1));
		get_inst_len(op, inst, type);
		inst->param_num = op->param_num;
		inst->param_arr = arr;
	}
	return (0);
}
