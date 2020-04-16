/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:59:58 by msabre            #+#    #+#             */
/*   Updated: 2020/04/07 21:46:12 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	const char		*s;
	char			*d;

	d = dst;
	s = src;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		s += len - 1;
		d += len - 1;
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}
