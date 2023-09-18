/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:12:19 by tkavisha          #+#    #+#             */
/*   Updated: 2023/01/16 14:29:01 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const	*s1, char const *s2)
{
	char	*returnptr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	returnptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (returnptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && s1)
	{
		returnptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0' && s2)
	{
		returnptr[i + j] = s2[j];
		j++;
	}
	returnptr[i + j] = '\0';
	return (returnptr);
}
