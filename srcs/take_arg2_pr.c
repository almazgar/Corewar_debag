/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg2_pr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:20:00 by almazg            #+#    #+#             */
/*   Updated: 2020/04/18 16:27:59 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	take_arg2_pr(char *line, t_file *ssl, t_exec *com, int i)
{
	if (line[ssl->a + i] == '-')
		take_arg2_pr_neg(line, ssl, com, i);
	else if (ft_isdigit(line[ssl->a + i]) && ++i)
	{
		while (ft_isdigit(line[ssl->a + i]))
			i++;
		if ((i > 1) && is_limit(line[ssl->a + i]))
		{
			if (!(com->a2 = ft_strsub(line, ssl->a + 1, i - 1)))
				write_error("ERROR_ARGUMENT_INIT");
		}
		else
			write_error("WRONG_NUMBER_ARGUMENT");
		com->ta2 = 2;
		ssl->a = ssl->a + i;
	}
	else
		write_error("WRONG_NUMBER_ARGUMENT");
}
