/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:43:08 by almazg            #+#    #+#             */
/*   Updated: 2020/04/08 16:53:45 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	sti(t_file *ssl, char *line, t_exec *com)
{
	take_arg1(line, ssl, com);
	no_separator(ssl, line);
	take_arg2(line, ssl, com);
	no_separator(ssl, line);
	take_arg3(line, ssl, com);
	if (com->ta1 != 1)
		write_error("ERROR_TYPE_ARGUMENT_1_STI_COMMAND");
	if (com->ta3 == 4 || com->ta3 == 5)
		write_error("ERROR_TYPE_ARGUMENT_3_STI_COMMAND");
	com->inst = 11;
	com->n_bytes = 7;
	com->dir_size = 2;
	if (com->ta2 == 1)
		com->n_bytes = com->n_bytes - 1;
	if (com->ta3 == 1)
		com->n_bytes = com->n_bytes - 1;
	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		ssl->a = ssl->a + 1;
	if (line[ssl->a] == '#' || line[ssl->a] == ';')
		while (line[ssl->a] && line[ssl->a] != '\n')
			ssl->a = ssl->a + 1;
	else if (line[ssl->a] != '\n' && line[ssl->a] != '\0')
		write_error("ALLOW_ONLY_THREE_ARGUMENT_TO_STI");
}
