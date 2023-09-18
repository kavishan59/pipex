/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:12:17 by tkavisha          #+#    #+#             */
/*   Updated: 2022/11/21 14:12:20 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*c_1;
	const unsigned char	*c_2;

	c_1 = s1;
	c_2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (c_1[i] == c_2[i] && i < n - 1)
		i++;
	return (c_1[i] - c_2[i]);
}
