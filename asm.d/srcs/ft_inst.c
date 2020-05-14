/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:25:14 by wahasni           #+#    #+#             */
/*   Updated: 2020/05/13 16:26:10 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_inst		*create_inst(t_asm *asmb, t_op *op)
{
	t_inst	*inst;

	if (!(inst = (t_inst *)malloc(sizeof(t_inst))))
		return (NULL);
	inst->opcode = op->opcode;
	inst->addr = asmb->accu_len;
	inst->len = 1 + op->ocp;
	inst->ocp = op->ocp;
	inst->direct_len = op->direct_len;
	return (inst);
}

t_op		*check_inst(char *str)
{
	int		inst_len;
	char	*inst;
	t_op	*op;

	inst = NULL;
	inst_len = 0;
	while (str[inst_len] && !ft_isspace(str[inst_len])
		&& str[inst_len] != DIRECT_CHAR)
		inst_len++;
	if (!(inst = ft_strsub(str, 0, inst_len)))
		return (NULL);
	if (!(op = get_op(inst)))
	{
		ft_strdel(&inst);
		return (NULL);
	}
	ft_strdel(&inst);
	return (op);
}
