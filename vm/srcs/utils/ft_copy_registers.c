/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_registers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:55:24 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/22 17:28:34 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_copy_registers(t_process *new, t_process *proc)
{
	int		i;

	i = 1;
	new->reg[0] = 0;
	while (i < 17)
	{
		new->reg[i] = proc->reg[i];
		i++;
	}
}
