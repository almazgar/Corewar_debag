/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 19:06:48 by almazg            #+#    #+#             */
/*   Updated: 2020/03/31 15:49:58 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	take_arg1(char *line, t_file *ssl, t_exec *com)
{
	int i;

	i = 0;
	skip_probel(ssl, line);
	if (line[ssl->a] == 'r')
	{
		while (ft_isdigit(line[ssl->a + i + 1]))
			i++;
		if (0 < i && i < 3 && ft_atoi(&line[ssl->a + 1]) > 0)
		{
			if (!(com->a1 = ft_strsub(line, ssl->a + 1, i)))
				write_error("ERROR_ARGUMENT_INIT");
		}
		else
			write_error("WRONG_NUMBER_REGISTR");
		com->ta1 = 1;
		ssl->a = ssl->a + i + 1;
	}
	else if (line[ssl->a] == '%' && line[ssl->a + 1] && line[ssl->a + 1] != ':')
	{
		i = 1;
		if (line[ssl->a + i] == '-')
		{
			i++;
			while (ft_isdigit(line[ssl->a + i]))
				i++;
			if ((i > 2) && is_limit(line[ssl->a + i]))
			{
				if (!(com->a1 = ft_strsub(line, ssl->a + 1, i - 1)))
					write_error("ERROR_ARGUMENT_INIT");
			}
			else
				write_error("WRONG_NUMBER_ARGUMENT");
			com->ta1 = 2;
			ssl->a = ssl->a + i;
		}
		else if (ft_isdigit(line[ssl->a + i]) && ++i)
		{
			while (ft_isdigit(line[ssl->a + i]))
				i++;
			if ((i > 1) && is_limit(line[ssl->a + i]))
			{
				if (!(com->a1 = ft_strsub(line, ssl->a + 1, i - 1)))
					write_error("ERROR_ARGUMENT_INIT");
			}
			else
				write_error("WRONG_NUMBER_ARGUMENT");
			com->ta1 = 2;
			ssl->a = ssl->a + i;
		}
		else
			write_error("WRONG_NUMBER_ARGUMENT");
	}
	else if (line[ssl->a + 1] && line[ssl->a + 1] == ':')
	{
		i = 2;
		while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
			i++;
		if ((i > 2) && is_limit(line[ssl->a + i]))
		{
			if (!(com->a1 = ft_strsub(line, ssl->a + 2, i - 2)))
				write_error("ERROR_ARGUMENT_INIT");
		}
		else
			write_error("WRONG_LABEL_ARGUMENT");
		com->ta1 = 3;
		ssl->a = ssl->a + i;
	}
	else if (ft_isdigit(line[ssl->a]) && ++i)
	{
		while (ft_isdigit(line[ssl->a + i]))
			i++;
		if (is_limit(line[ssl->a + i]))
		{
			if (!(com->a1 = ft_strsub(line, ssl->a, i)))
				write_error("ERROR_ARGUMENT_INIT");
		}
		else
			write_error("WRONG_NUMBER_ARGUMENT");
		com->ta1 = 4;
		ssl->a = ssl->a + i;
	}
	else if (line[ssl->a] == '-')
	{
		i++;
		while (ft_isdigit(line[ssl->a + i]))
			i++;
		if ((i > 1) && is_limit(line[ssl->a + i]))
		{
			if (!(com->a1 = ft_strsub(line, ssl->a, i)))
				write_error("ERROR_ARGUMENT_INIT");
		}
		else
			write_error("WRONG_NUMBER_ARGUMENT");
		com->ta1 = 4;
		ssl->a = ssl->a + i;
	}
	else if (line[ssl->a] == ':')
	{
		i = 1;
		while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
			i++;
		if ((i > 1) && is_limit(line[ssl->a + i]))
		{
			if (!(com->a1 = ft_strsub(line, ssl->a + 1, i - 1)))
				write_error("ERROR_ARGUMENT_INIT");
		}
		else
			write_error("WRONG_LABEL_NAME");
		com->ta1 = 5;
		ssl->a = ssl->a + i;
	}
	else
		write_error("WRONG_ARGUMENT");
}
