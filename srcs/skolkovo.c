/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skolkovo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 11:09:33 by almazg            #+#    #+#             */
/*   Updated: 2020/04/15 12:45:26 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		skolkovo(char *line, t_file *ssl)
{
	t_exec	*head;

	name_comment(line, ssl);
	head = connecting_people(line, ssl);
	close(ssl->text);
	ft_putstr("Writing bytecode to ");
	ft_putendl(ssl->f_name);
	free_exec(head);
}
