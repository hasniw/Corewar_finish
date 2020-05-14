/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 02:36:09 by wahasni           #+#    #+#             */
/*   Updated: 2020/02/27 21:00:52 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_registry(char *str)
{
	int		num;

	str++;
	if (!ft_isdigit(*str))
		return (ft_error("registry argument has wrong format", 1));
	num = ft_atoi(str);
	if (num < 1 || num > REG_NUMBER)
		return (ft_error("registry argument is out of the limit", 1));
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (ft_error("registry argument has wrong format", 1));
	return (0);
}

static int	check_number(char *str, char type)
{
	if (type & T_DIR)
		str++;
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (ft_error("number argument has wrong format", 1));
		str++;
	}
	return (0);
}

static int	check_label(char *str, char type)
{
	if (type & T_DIR)
		str++;
	str++;
	if (*str == 0)
		return (ft_error("no character after label char", 1));
	while (*str)
	{
		if (!ft_strchr(LABEL_CHARS, *str))
			return (ft_error("label argument has wrong format", 1));
		str++;
	}
	return (0);
}

int			check_type(char *str, int type)
{
	if (type & T_REG)
	{
		if (check_registry(str))
			return (1);
	}
	else if (type & T_LAB)
	{
		if (check_label(str, type))
			return (1);
	}
	else if (type & (T_DIR | T_IND))
	{
		if (check_number(str, type))
			return (1);
	}
	return (0);
}
