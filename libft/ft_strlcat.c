/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:15:03 by tkavisha          #+#    #+#             */
/*   Updated: 2023/01/16 13:38:55 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_initial_length;

	if (dst)
		dst_initial_length = ft_strlen(dst);
	else
		dst_initial_length = 0;
	if (size > (dst_initial_length + 1))
	{
		i = 0;
		while (src[i] && i < (size - 1 - dst_initial_length))
		{
			dst[dst_initial_length + i] = src[i];
			i++;
		}
		dst[dst_initial_length + i] = '\0';
	}
	if (size > dst_initial_length)
		return (dst_initial_length + ft_strlen(src));
	else
		return (size + ft_strlen(src));
}
