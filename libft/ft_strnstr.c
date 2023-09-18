/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:02:18 by tkavisha          #+#    #+#             */
/*   Updated: 2023/01/16 14:09:46 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char	*little, size_t	len)
{
	const char	*returnptr;
	size_t		i;
	size_t		j;

	i = -1;
	j = 0;
	returnptr = NULL;
	if (little[0] == '\0')
		return ((char *)big);
	if (!big && len == 0)
		return (NULL);
	while (big[++i] && (i + ft_strlen(little)) <= len)
	{
		if (big[i] == little[j])
		{
			returnptr = &big[i];
			while (big[i + j] == little[j] && big[i + j] && little[j])
				j++;
			if (j == ft_strlen(little))
				break ;
		}
		j = 0;
		returnptr = NULL;
	}
	return ((char *)returnptr);
}
