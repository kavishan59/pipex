/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:38:58 by tkavisha          #+#    #+#             */
/*   Updated: 2023/01/16 13:25:20 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	char				*char_dest;
	const char			*char_src;

	i = 0;
	char_dest = dest;
	char_src = src;
	if (!dest && !src)
		return (NULL);
	if (src < dest && src + n > dest)
	{
		i = n + 1;
		while (--i > 0)
			char_dest[i - 1] = char_src[i - 1];
	}
	else
	{
		while (i < n)
		{
			char_dest[i] = char_src[i];
			i++;
		}
	}
	return (dest);
}
