/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:48:55 by wahasni           #+#    #+#             */
/*   Updated: 2020/02/27 21:02:18 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_label	*ft_create_elem_label(char *name, int addr)
{
	t_label	*list;

	if (!(list = ft_memalloc(sizeof(t_label))))
		return (NULL);
	if (!(list->name = name))
		return (NULL);
	list->addr = addr;
	return (list);
}

static t_inst	*ft_create_elem_inst(t_inst *inst)
{
	t_inst	*list;

	if (!(list = ft_memalloc(sizeof(t_inst))))
		return (NULL);
	list->opcode = inst->opcode;
	list->ocp = inst->ocp;
	list->direct_len = inst->direct_len;
	list->param_byte = inst->param_byte;
	list->param_num = inst->param_num;
	list->param_arr = inst->param_arr;
	list->addr = inst->addr;
	list->len = inst->len;
	return (list);
}

void			ft_list_push_back_label(t_label **begin_list,
	char *name, int addr)
{
	t_label	*list;

	if (!begin_list)
		return ;
	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem_label(name, addr);
	}
	else
		*begin_list = ft_create_elem_label(name, addr);
}

void			ft_list_push_back_inst(t_inst **begin_list, t_inst *inst)
{
	t_inst	*list;

	if (!begin_list)
		return ;
	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem_inst(inst);
	}
	else
		*begin_list = ft_create_elem_inst(inst);
}
