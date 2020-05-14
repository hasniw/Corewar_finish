/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdequeue_del.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:40:11 by lutsiara          #+#    #+#             */
/*   Updated: 2019/05/15 19:02:46 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstdequeue_del(t_list **alst, void (*del)(void *, unsigned long))
{
	t_list	*tmp;

	tmp = *alst;
	if (!(*alst))
		return (1);
	*alst = tmp->next;
	if (del)
		del(tmp->content, tmp->content_size);
	ft_memdel((void **)&tmp);
	return (0);
}
