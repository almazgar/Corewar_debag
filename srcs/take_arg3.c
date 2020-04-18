/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:06:02 by almazg            #+#    #+#             */
/*   Updated: 2020/04/18 17:50:58 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	take_arg3(char *line, t_file *ssl, t_exec *com)
{
	int i;

	i = 0;
	skip_probel(ssl, line);
	if (line[ssl->a] == 'r')
		take_arg3_r(line, ssl, com, 0);
//	{
//		while (ft_isdigit(line[ssl->a + i + 1]))
//			i++;
//		if (0 < i && i < 3)
//		{
//			if (!(com->a3 = ft_strsub(line, ssl->a + 1, i)))
//				write_error("ERROR_ARGUMENT_INIT");
//		}
//		else
//			write_error("WRONG_NUMBER_REGISTR");
//		com->ta3 = 1;
//		ssl->a = ssl->a + i + 1;
//	}
	else if (line[ssl->a] == '%' && line[ssl->a + 1] && line[ssl->a + 1] != ':')
		take_arg3_pr(line, ssl, com, 1);
//	{
//		i = 1;
//		if (line[ssl->a + i] == '-')
//		{
//			i++;
//			while (ft_isdigit(line[ssl->a + i]))
//				i++;
//			if ((i > 2) && is_limit(line[ssl->a + i]))
//			{
//				if (!(com->a3 = ft_strsub(line, ssl->a + 1, i - 1)))
//					write_error("ERROR_ARGUMENT_INIT");
//			}
//			else
//				write_error("WRONG_NUMBER_ARGUMENT");
//			com->ta3 = 2;
//			ssl->a = ssl->a + i;
//		}
//		else if (ft_isdigit(line[ssl->a + i]) && ++i)
//		{
//			while (ft_isdigit(line[ssl->a + i]))
//				i++;
//			if ((i > 1) && is_limit(line[ssl->a + i]))
//			{
//				if (!(com->a3 = ft_strsub(line, ssl->a + 1, i - 1)))
//					write_error("ERROR_ARGUMENT_INIT");
//			}
//			else
//				write_error("WRONG_NUMBER_ARGUMENT");
//			com->ta3 = 2;
//			ssl->a = ssl->a + i;
//		}
//		else
//			write_error("WRONG_NUMBER_ARGUMENT");
//	}
	else if (line[ssl->a + 1] && line[ssl->a + 1] == ':')
		take_arg3_d(line, ssl, com, 2);
//	{
//		i = 2;
//		while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
//			i++;
//		if ((i > 2) && is_limit(line[ssl->a + i]))
//		{
//			if (!(com->a3 = ft_strsub(line, ssl->a + 2, i - 2)))
//				write_error("ERROR_ARGUMENT_INIT");
//		}
//		else
//			write_error("WRONG_LABEL_ARGUMENT");
//		com->ta3 = 3;
//		ssl->a = ssl->a + i;
//	}
	else if (ft_isdigit(line[ssl->a]))
		take_arg3_n(line, ssl, com, 1);
//	{
//		while (ft_isdigit(line[ssl->a + i]))
//			i++;
//		if (is_limit(line[ssl->a + i]))
//		{
//			if (!(com->a3 = ft_strsub(line, ssl->a, i)))
//				write_error("ERROR_ARGUMENT_INIT");
//		}
//		else
//			write_error("WRONG_NUMBER_ARGUMENT");
//		com->ta3 = 4;
//		ssl->a = ssl->a + i;
//	}
	else if (line[ssl->a] == '-')
		take_arg3_neg(line, ssl, com, 1);
//	{
//		i++;
//		while (ft_isdigit(line[ssl->a + i]))
//			i++;
//		if ((i > 1) && is_limit(line[ssl->a + i]))
//		{
//			if (!(com->a3 = ft_strsub(line, ssl->a, i)))
//				write_error("ERROR_ARGUMENT_INIT");
//		}
//		else
//			write_error("WRONG_NUMBER_ARGUMENT");
//		com->ta3 = 4;
//		ssl->a = ssl->a + i;
//	}
	else if (line[ssl->a] == ':')
		take_arg3_dv(line, ssl, com, 1);
//	{
//		i = 1;
//		while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
//			i++;
//		if ((i > 1) && is_limit(line[ssl->a + i]))
//		{
//			if (!(com->a3 = ft_strsub(line, ssl->a + 1, i - 1)))
//				write_error("ERROR_ARGUMENT_INIT");
//		}
//		else
//			write_error("WRONG_LABEL_NAME");
//		com->ta3 = 5;
//		ssl->a = ssl->a + i;
//	}
	else
		write_error("WRONG_ARGUMENT");
}
