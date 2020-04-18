/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 16:13:47 by almazg            #+#    #+#             */
/*   Updated: 2020/04/17 16:47:17 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void				line_to_write(t_exec **com, t_file *ssl)
{
	t_exec			*current;
	unsigned char	*s;
	int				i;

	if (!*com)
		write_error("ERROR NOTHING TO DO");
	current = *com;
	while (current)
	{
		if (!(s = (unsigned char*)malloc(sizeof(unsigned char)
				* (current->n_bytes))))
			return ;
		s[0] = current->inst;
		i = 1;
		if (current->ta)
		{
			i = 2;
			s[1] = current->ta;
		}
		i = line_part(current, s, i, 1);
		if (current->ta2 != 0)
			i = line_part(current, s, i, 2);
		if (current->ta3 != 0)
			i = line_part(current, s, i, 3);
		if (i == current->n_bytes)
			write(ssl->text, s, i);
		else
			write_error("ERROR_CONVERTING_ARGUMENTS");
		current = current->next;
		ft_memdel((void**)&s);
	}
}
