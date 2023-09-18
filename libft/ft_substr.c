/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:51:25 by tkavisha          #+#    #+#             */
/*   Updated: 2023/01/16 14:14:13 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*returnptr;
	size_t	length;

	length = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (s[start + length] && length < len)
		length++;
	returnptr = (char *)malloc((length + 1) * sizeof(char));
	if (returnptr == NULL)
		return (NULL);
	while (s[start + i] && i < length)
	{
		returnptr[i] = s[start + i];
		i++;
	}
	returnptr[i] = '\0';
	return (returnptr);
}
