/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:07:27 by msabre            #+#    #+#             */
/*   Updated: 2020/04/07 21:46:12 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t i;
	size_t len;

	if (!(s1 || s2))
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (i < n)
	{
		if (s2[i] == '\0')
		{
			s1[len] = '\0';
			return (s1);
		}
		s1[len] = s2[i];
		len++;
		i++;
	}
	s1[len] = '\0';
	return (s1);
}
