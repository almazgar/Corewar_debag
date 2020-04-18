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
//	long long		j;
//	int				k;

	if (!*com)
		write_error("ERROR NOTHING TO DO");
	current = *com;
	while (current)
	{
//		k = 3;
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
//		j = ft_atoi(current->a1);
//		if (current->ta1 == 1)
//			s[i++] = j;
//		else if (current->ta1 == 2 && current->dir_size == 4)
//		{
//			while (k > -1)
//				s[i++] = j >> (8 * k--);
//		}
//		else
//		{
//			k = 1;
//			while (k > -1)
//				s[i++] = j >> (8 * k--);
//		}
		if (current->ta2 != 0)
			i = line_part(current, s, i, 2);
//			i = line_part(current->a2, current->ta2, current->dir_size, s, i);

//		if (current->ta2 != 0)
//		{
//			k = 3;
//			j = ft_atoi(current->a2);
//			if (current->ta2 == 1)
//				s[i++] = j;
//			else if (current->ta2 == 2 && current->dir_size == 4)
//			{
//				while (k > -1)
//					s[i++] = j >> (8 * k--);
//			}
//			else
//			{
//				k = 1;
//				while (k > -1)
//					s[i++] = j >> (8 * k--);
//			}
//		}
		if (current->ta3 != 0)
			i = line_part(current, s, i, 3);
//			i = line_part(current->a3, current->ta3, current->dir_size, s, i);

//		if (current->ta3 != 0)
//		{
//			k = 3;
//			j = ft_atoi(current->a3);
//			if (current->ta3 == 1)
//				s[i++] = j;
//			else if (current->ta3 == 2 && current->dir_size == 4)
//			{
//				while (k > -1)
//					s[i++] = j >> (8 * k--);
//			}
//			else
//			{
//				k = 1;
//				while (k > -1)
//					s[i++] = j >> (8 * k--);
//			}
//		}
		if (i == current->n_bytes)
			write(ssl->text, s, i);
		else
			write_error("ERROR_CONVERTING_ARGUMENTS");
		current = current->next;
		ft_memdel((void**)&s);
	}
}
