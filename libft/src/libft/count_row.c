/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:51:52 by msabre            #+#    #+#             */
/*   Updated: 2020/04/07 21:46:12 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		count_row(void **mass)
{
	int			count;

	count = 0;
	while (mass[count] != NULL)
		count++;
	return (count);
}
