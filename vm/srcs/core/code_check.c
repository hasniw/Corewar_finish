/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:04:54 by lutsiara          #+#    #+#             */
/*   Updated: 2020/02/24 18:41:13 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_get_t_code(char ocp)
{
	if ((ocp & 1) && ((ocp >> 1) & 1))
		return (T_IND);
	else if ((ocp >> 1) & 1)
		return (T_DIR);
	else if (ocp & 1)
		return (REG_CODE);
	else
		return (0);
}

int		ft_check_ocp(t_process *proc, char ocp)
{
	int i;
	int param;

	i = 0;
	if ((ocp & 1) || (ocp >> 1) & 1)
		return (0);
	while (i < g_op_tab[proc->current_op - 1].params)
	{
		param = ocp >> (6 - (2 * i));
		if (!(ft_get_t_code(param) & g_op_tab[proc->current_op - 1].type[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_get_code(char ocp)
{
	if ((ocp & 1) && ((ocp >> 1) & 1))
		return (IND_CODE);
	else if ((ocp >> 1) & 1)
		return (DIR_CODE);
	else if (ocp & 1)
		return (REG_CODE);
	else
		return (0);
}
