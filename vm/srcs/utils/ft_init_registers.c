/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_registers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:55:24 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/22 17:29:14 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_init_registers(t_process *process)
{
	int		i;

	i = 2;
	process->reg[0] = 0;
	process->reg[1] = -process->master;
	while (i < 17)
	{
		process->reg[i] = 0;
		i++;
	}
}
