/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 01:47:13 by wahasni           #+#    #+#             */
/*   Updated: 2020/02/27 20:49:12 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	handle_end(t_asm *asmb)
{
	asmb->prog_name[ft_strlen(asmb->prog_name) - 1] = 0;
	asmb->prog_comment[ft_strlen(asmb->prog_comment) - 1] = 0;
	if (asmb->prog_name[ft_strlen(asmb->prog_name)] == '"')
		asmb->prog_name[ft_strlen(asmb->prog_name)] = 0;
	if (asmb->prog_comment[ft_strlen(asmb->prog_comment)] == '"')
		asmb->prog_name[ft_strlen(asmb->prog_name)] = 0;
}
