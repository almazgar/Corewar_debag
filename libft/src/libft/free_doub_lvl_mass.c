/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_doub_lvl_mass.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:53:13 by msabre            #+#    #+#             */
/*   Updated: 2020/04/07 21:46:12 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void		*free_doub_lvl_mass(void **mas)
{
	char	**ptr;
	int		i;

	i = 0;
	if (!mas)
		return (NULL);
	ptr = (char**)mas;
	while (ptr[i] != NULL)
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}
