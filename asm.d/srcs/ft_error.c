/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:26:07 by wahasni           #+#    #+#             */
/*   Updated: 2020/02/27 21:03:47 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_error_str(char *str, char *ret)
{
	ft_printf("%{RED}%s%{}\n", str);
	return (ret);
}

int		ft_error(char *str, int ret)
{
	ft_printf("%{RED}%s%{}\n", str);
	return (ret);
}
