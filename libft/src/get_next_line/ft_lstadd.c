/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 22:21:14 by msabre            #+#    #+#             */
/*   Updated: 2020/04/07 21:46:12 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"

void			ft_lstadd(t_gnlist **alst, t_gnlist *new)
{
	t_gnlist	*ptr;

	ptr = *alst;
	if (!ptr)
		*alst = new;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->next = NULL;
	}
}
