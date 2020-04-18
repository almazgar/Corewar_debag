/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:52:44 by almazg            #+#    #+#             */
/*   Updated: 2020/04/18 13:03:49 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		check_comment(char *line, t_file *ssl)
{
	int		j;
	char	*s;

	j = 0;
	s = ft_strnew(COMMENT_LENGTH);
	ssl->a += 8;
	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		(ssl->a)++;
	if (line[ssl->a] != '"')
		check_comment2(line, ssl);
//	{
//		while (line[ssl->a] != '"' && (get_next_line(ssl->fd, &line)) > 0)
//		{
//			ssl->a = 0;
//			while (line[ssl->a] && is_whitespace(line[ssl->a]))
//				(ssl->a)++;
//			if (line[ssl->a] && line[ssl->a] != '"')
//				write_error("ERROR COMMENT");
//			ft_strdel(&line);
//		}
//	}
	(ssl->a)++;
	while (line[ssl->a] && line[ssl->a] != '"')
		s[j++] = line[(ssl->a)++];
	if (line[ssl->a] != '"')
		j = check_comment3(line, ssl, j, s);
//	{
//		s[j++] = '\n';
//		while ((get_next_line(ssl->fd, &line)) > 0)
//		{
//			ssl->a = 0;
//			while (line[ssl->a] && line[ssl->a] != '"')
//				s[j++] = line[(ssl->a)++];
//			if (line[ssl->a] == '"')
//				break ;
//			s[j++] = '\n';
//			ft_strdel(&line);
//		}
//	}
	if (line[ssl->a] != '"')
		write_error("ERROR NO FINISH COMMENT");
	if (j > COMMENT_LENGTH)
		write_error("VERY LONG COMMENT");
	ft_bzero(ssl->comment, COMMENT_LENGTH);
	ft_strncpy(ssl->comment, s, j);
	ssl->c = 1;
	ft_memdel((void **)&s);
}
