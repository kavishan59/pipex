/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:26:24 by tkavisha          #+#    #+#             */
/*   Updated: 2022/11/17 15:03:04 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*returnptr;
	int		i;

	returnptr = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (returnptr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		returnptr[i] = s[i];
		i++;
	}
	returnptr[i] = '\0';
	return (returnptr);
}
