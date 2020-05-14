/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:25:43 by wahasni           #+#    #+#             */
/*   Updated: 2020/04/22 17:06:14 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

int	handle_file(t_asm *file, int ac, char *av)
{
	int		len;

	if (ac != 2)
		return (ft_error("format : ./asm champ.s", 1));
	len = ft_strlen(av);
	if (len <= 2 || av[len - 2] != '.' || av[len - 1] != 's' || av[len])
		return (ft_error("format : ./asm champ.s", 1));
	if ((file->fd = open(av, 0)) == -1)
		return (ft_error("open file failed", 1));
	if (!(file->file_name = ft_strnew(len + 2)))
		return (ft_error("malloc failed", 1));
	ft_strncpy(file->file_name, av, len - 1);
	ft_strcat(file->file_name, "cor");
	return (0);
}

int	main(int ac, char **av)
{
	t_asm	asmb;

	init_asm(&asmb);
	if (handle_file(&asmb, ac, av[1]))
		return (ft_error("Wrong input", -1));
	if (parse(&asmb))
		return (-1);
	if ((close(asmb.fd)) == -1)
		return (free_asm(&asmb, ft_error("close file failed", -1)));
	if (output(&asmb))
		return (free_asm(&asmb, -1));
	return (free_asm(&asmb, -1));
}
