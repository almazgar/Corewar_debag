/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 09:52:44 by almazg            #+#    #+#             */
/*   Updated: 2020/04/16 10:34:33 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		take_label(char *line, t_file *ssl, t_label **list, t_exec *co)
{
	int		i;
	char	*name;
	t_exec	*com;

	com = NULL;
	i = 0;
	while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
		i++;
	if ((i) && line[ssl->a + i] == ':')
	{
		if (!(name = ft_strsub(line, ssl->a, i)))
			write_error("ERROR_STR_LABEL");
		add_label(list, cnl(name, ssl->line_byte));
		ssl->a = ssl->a + i + 1;
	}
	else if (i)
	{
		ssl->a = ssl->a + i;
		if (1 < i && i < 6)
		{
			com = init_exec();
			com->line_byte = ssl->line_byte;
			compare(ssl, line, i, com);
			ssl->line_byte = ssl->line_byte + com->n_bytes;
		}
		else
			write_error("WRONG_OPERATOR");
		add_comand(co, com);
	}
	else
		write_error("WRONG_LABEL_STRING");
}
