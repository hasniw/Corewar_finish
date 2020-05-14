/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:26:03 by wahasni           #+#    #+#             */
/*   Updated: 2020/02/27 21:00:23 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		free_just_inst(t_inst *inst, int ret)
{
	free(inst);
	return (ret);
}

void	free_inst(t_inst *inst)
{
	t_inst	*tmp;

	while (inst)
	{
		free_tab(inst->param_arr, 0);
		tmp = inst->next;
		free(inst);
		inst = tmp;
	}
}

void	free_labels(t_label *labels)
{
	t_label	*tmp;

	while (labels)
	{
		ft_strdel(&labels->name);
		tmp = labels->next;
		free(labels);
		labels = tmp;
	}
}

int		free_asm(t_asm *asmb, int ret)
{
	if (asmb->line)
		ft_strdel(&asmb->line);
	ft_strdel(&asmb->file_name);
	if (asmb->labels)
		free_labels(asmb->labels);
	if (asmb->inst)
		free_inst(asmb->inst);
	return (ret);
}
