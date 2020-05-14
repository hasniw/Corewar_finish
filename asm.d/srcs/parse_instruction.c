/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:20:58 by wahasni           #+#    #+#             */
/*   Updated: 2020/05/14 13:01:24 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		remove_comment(char *str)
{
	int		i;
	int		j;
	int		index;

	if (!str)
		return ;
	i = ft_strchrindex(str, COMMENT_CHAR);
	j = ft_strchrindex(str, ALT_COMMENT_CHAR);
	if (i > j)
		index = j;
	else
		index = i;
	if (index >= 0)
		while (str[index])
			str[index] = 0;
}

static int		space(char *str, t_norme norme)
{
	while (ft_isspace(str[norme.i]))
		norme.i++;
	return (0);
}

static int		check_label_infront(t_asm *asmb, char *str, t_norme norme)
{
	while (norme.nb-- && space(str, norme) == 0)
	{
		if (ft_strchr(LABEL_CHARS, str[norme.i]))
		{
			norme.j = norme.i;
			while (str[norme.i] && !ft_isspace(str[norme.i])
				&& str[norme.i] != DIRECT_CHAR)
			{
				if (str[norme.i] == LABEL_CHAR)
				{
					while (norme.j < norme.i)
						if (!ft_strchr(LABEL_CHARS, str[norme.j++]))
							return (ft_error("contains non-LABEL_CHARS", 1));
					ft_list_push_back_label(&asmb->labels,
						ft_strsub(str, 0, norme.i), asmb->accu_len);
					norme.i++;
					break ;
				}
				norme.i++;
			}
		}
		else
			return (ft_error("contains non-LABEL_CHARS", -1));
	}
	return (norme.i);
}

int				parse_instruction(t_asm *asmb)
{
	char	*str;
	int		i;
	t_op	*op;
	t_inst	*inst;

	if (check_name_comment(asmb))
		return (0);
	remove_comment(asmb->line);
	if (!(str = ft_strtrim(asmb->line)))
		return (ft_error("Failed strtrim", 1));
	i = check_label_infront(asmb, str, (t_norme){0, 0, is_label(str)});
	if (i == -1)
		return (free_str_value(str, 0));
	if (!str[i])
		return (free_str_value(str, 1));
	if (!(op = check_inst(str + skip_space(str, i))))
		return (free_str_value(str, 0));
	if (!(inst = create_inst(asmb, op)))
		return (free_str_value(str, 0));
	i = skip_space(str, skip_nonspace(str, i));
	if (check_param(str + i, op, inst, -1))
		return (free_str_value(str, free_just_inst(inst, 0)));
	asmb->accu_len += inst->len;
	ft_list_push_back_inst(&asmb->inst, inst);
	return (free_str_value(str, free_just_inst(inst, 1)));
}
