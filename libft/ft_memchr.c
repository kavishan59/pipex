/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:46:02 by tkavisha          #+#    #+#             */
/*   Updated: 2022/11/21 13:59:47 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const void			*returnptr;
	const unsigned char	*char_s;
	unsigned char		u_c;

	i = 0;
	u_c = c;
	returnptr = NULL;
	char_s = s;
	while (i < n)
	{
		if (char_s[i] == u_c)
		{
			returnptr = &char_s[i];
			break ;
		}
		i++;
	}
	return ((void *)returnptr);
}
