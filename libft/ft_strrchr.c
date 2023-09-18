/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:38:57 by tkavisha          #+#    #+#             */
/*   Updated: 2022/11/21 14:31:34 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	size_t			total_length;
	const char		*returnptr;
	unsigned char	u_c;

	returnptr = NULL;
	i = 0;
	u_c = c;
	total_length = ft_strlen(s) + 1;
	while (i < total_length)
	{
		if (s[i] == u_c)
			returnptr = &s[i];
		i++;
	}
	return ((char *)returnptr);
}
